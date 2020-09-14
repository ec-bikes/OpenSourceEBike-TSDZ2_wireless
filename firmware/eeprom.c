/*
 * Bafang LCD 850C firmware
 *
 * Copyright (C) Casainho, 2018.
 *
 * Released under the GPL License, Version 3
 */

#include "stdio.h"
#include <string.h>
#include "eeprom_hw.h"
#include "eeprom.h"
#include "main_screen.h"
#include "state.h"
//#include "lcd_configurations.h"

static eeprom_data_t m_eeprom_data;

// get rid of some copypasta with this little wrapper for copying arrays between structs
#define COPY_ARRAY(dest, src, field) memcpy((dest)->field, (src)->field, sizeof((dest)->field))

const eeprom_data_t m_eeprom_data_defaults = {
  .eeprom_version = EEPROM_VERSION,
  .ui8_assist_level = DEFAULT_VALUE_ASSIST_LEVEL,
  .ui16_wheel_perimeter = DEFAULT_VALUE_WHEEL_PERIMETER,
  .ui8_wheel_max_speed = DEFAULT_VALUE_WHEEL_MAX_SPEED,
  .ui8_units_type = DEFAULT_VALUE_UNITS_TYPE,
  .ui32_wh_x10_offset = DEFAULT_VALUE_WH_X10_OFFSET,
  .ui32_wh_x10_100_percent = DEFAULT_VALUE_HW_X10_100_PERCENT,
  .ui8_battery_max_current = DEFAULT_VALUE_BATTERY_MAX_CURRENT,
  .ui8_target_max_battery_power_div25 = DEFAULT_VALUE_TARGET_MAX_BATTERY_POWER,
  .ui8_motor_max_current = DEFAULT_VALUE_MOTOR_MAX_CURRENT,
  .ui8_motor_current_min_adc = DEFAULT_VALUE_CURRENT_MIN_ADC,
  .ui8_field_weakening = DEFAULT_FIELD_WEAKENING,
  .ui8_ramp_up_amps_per_second_x10 = DEFAULT_VALUE_RAMP_UP_AMPS_PER_SECOND_X10,
  .ui16_battery_low_voltage_cut_off_x10 = DEFAULT_VALUE_BATTERY_LOW_VOLTAGE_CUT_OFF_X10,
  .ui8_motor_type = DEFAULT_VALUE_MOTOR_TYPE,
  .ui8_motor_current_control_mode = DEFAULT_VALUE_MOTOR_CURRENT_CONTROL_MODE,
  .ui8_motor_assistance_startup_without_pedal_rotation = DEFAULT_VALUE_MOTOR_ASSISTANCE_WITHOUT_PEDAL_ROTATION,
  .ui16_assist_level_factor = {
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_1,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_2,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_3,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_4,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_5,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_6,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_7,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_8,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_9,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_10,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_11,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_12,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_13,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_14,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_15,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_16,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_17,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_18,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_19,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_20,
  },
  .ui8_number_of_assist_levels = DEFAULT_VALUE_NUMBER_OF_ASSIST_LEVELS,
  .ui8_startup_motor_power_boost_feature_enabled = DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_FEATURE_ENABLED,
  .ui8_startup_motor_power_boost_always = DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ALWAYS,
  .ui16_startup_motor_power_boost_factor = {
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_1,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_2,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_3,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_4,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_5,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_6,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_7,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_8,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_9,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_10,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_11,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_12,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_13,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_14,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_15,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_16,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_17,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_18,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_19,
  DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_20,
  },
  .ui8_startup_motor_power_boost_time =
  DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_TIME,
  .ui8_startup_motor_power_boost_fade_time =
  DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_FADE_TIME,
  .ui8_temperature_limit_feature_enabled =
  DEFAULT_VALUE_MOTOR_TEMPERATURE_FEATURE_ENABLE,
  .ui8_motor_temperature_min_value_to_limit =
  DEFAULT_VALUE_MOTOR_TEMPERATURE_MIN_VALUE_LIMIT,
  .ui8_motor_temperature_max_value_to_limit =
  DEFAULT_VALUE_MOTOR_TEMPERATURE_MAX_VALUE_LIMIT,
  .ui16_battery_voltage_reset_wh_counter_x10 =
  DEFAULT_VALUE_BATTERY_VOLTAGE_RESET_WH_COUNTER_X10,
  .ui8_lcd_power_off_time_minutes =
  DEFAULT_VALUE_LCD_POWER_OFF_TIME,
  .ui16_battery_pack_resistance_x1000 =
  DEFAULT_VALUE_BATTERY_PACK_RESISTANCE,
  .ui8_offroad_feature_enabled =
  DEFAULT_VALUE_OFFROAD_FEATURE_ENABLED,
  .ui8_offroad_enabled_on_startup =
  DEFAULT_VALUE_OFFROAD_MODE_ENABLED_ON_STARTUP,
  .ui8_offroad_speed_limit = DEFAULT_VALUE_OFFROAD_SPEED_LIMIT,
  .ui8_offroad_power_limit_enabled =
  DEFAULT_VALUE_OFFROAD_POWER_LIMIT_ENABLED,
  .ui8_offroad_power_limit_div25 =
  DEFAULT_VALUE_OFFROAD_POWER_LIMIT_DIV25,
  .ui32_odometer_x10 =
  DEFAULT_VALUE_ODOMETER_X10,
  .ui8_walk_assist_feature_enabled =
  DEFAULT_VALUE_WALK_ASSIST_FEATURE_ENABLED,
  .ui8_walk_assist_level_factor = {
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_1,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_2,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_3,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_4,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_5,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_6,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_7,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_8,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_9,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_10,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_11,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_12,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_13,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_14,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_15,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_16,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_17,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_18,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_19,
  DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_20,
  },

  .ui16_torque_sensor_calibration_table_left[0][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_1,
  .ui16_torque_sensor_calibration_table_left[0][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_1,
  .ui16_torque_sensor_calibration_table_left[1][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_2,
  .ui16_torque_sensor_calibration_table_left[1][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_2,
  .ui16_torque_sensor_calibration_table_left[2][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_3,
  .ui16_torque_sensor_calibration_table_left[2][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_3,
  .ui16_torque_sensor_calibration_table_left[3][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_4,
  .ui16_torque_sensor_calibration_table_left[3][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_4,
  .ui16_torque_sensor_calibration_table_left[4][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_5,
  .ui16_torque_sensor_calibration_table_left[4][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_5,
  .ui16_torque_sensor_calibration_table_left[5][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_6,
  .ui16_torque_sensor_calibration_table_left[5][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_6,
  .ui16_torque_sensor_calibration_table_left[6][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_7,
  .ui16_torque_sensor_calibration_table_left[6][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_7,
  .ui16_torque_sensor_calibration_table_left[7][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_8,
  .ui16_torque_sensor_calibration_table_left[7][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_8,

  .ui16_torque_sensor_calibration_table_right[0][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_1,
  .ui16_torque_sensor_calibration_table_right[0][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_1,
  .ui16_torque_sensor_calibration_table_right[1][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_2,
  .ui16_torque_sensor_calibration_table_right[1][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_2,
  .ui16_torque_sensor_calibration_table_right[2][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_3,
  .ui16_torque_sensor_calibration_table_right[2][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_3,
  .ui16_torque_sensor_calibration_table_right[3][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_4,
  .ui16_torque_sensor_calibration_table_right[3][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_4,
  .ui16_torque_sensor_calibration_table_right[4][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_5,
  .ui16_torque_sensor_calibration_table_right[4][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_5,
  .ui16_torque_sensor_calibration_table_right[5][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_6,
  .ui16_torque_sensor_calibration_table_right[5][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_6,
  .ui16_torque_sensor_calibration_table_right[6][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_7,
  .ui16_torque_sensor_calibration_table_right[6][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_7,
  .ui16_torque_sensor_calibration_table_right[7][0] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_8,
  .ui16_torque_sensor_calibration_table_right[7][1] = DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_8,

  .ui8_street_mode_function_enabled = DEFAULT_STREET_MODE_FUNCTION_ENABLE,
  .ui8_street_mode_enabled_on_startup = DEFAULT_STREET_MODE_ENABLE_AT_STARTUP,
  .ui8_street_mode_enabled = DEFAULT_STREET_MODE_ENABLE,
  .ui8_street_mode_speed_limit = DEFAULT_STREET_MODE_SPEED_LIMIT,
  .ui8_street_mode_power_limit_div25 = DEFAULT_STREET_MODE_POWER_LIMIT,
  .ui8_street_mode_throttle_enabled = DEFAULT_STREET_MODE_THROTTLE_ENABLE,
  .ui8_street_mode_hotkey_enabled = DEFAULT_STREET_MODE_HOTKEY_ENABLE,
  .ui8_pedal_cadence_fast_stop = DEFAULT_PEDAL_CADENCE_FAST_STOP_ENABLE,
  .ui8_coast_brake_adc = DEFAULT_COAST_BRAKE_ADC,
  .ui8_adc_lights_current_offset = DEFAULT_ADC_LIGHTS_CURRENT_OFFSET,
  .ui8_throttle_virtual_step = DEFAULT_THROTTLE_VIRTUAL_STEP,
  .ui8_torque_sensor_filter = DEFAULT_TORQUE_SENSOR_FILTER,
  .ui8_torque_sensor_adc_threshold = DEFAULT_TORQUE_SENSOR_ADC_THRESHOLD,
  .ui8_coast_brake_enable = DEFAULT_COAST_BRAKE_ENABLE,
};

void eeprom_init() {
	eeprom_hw_init();

	// read the values from EEPROM to array
	memset(&m_eeprom_data, 0, sizeof(m_eeprom_data));

	// if eeprom is blank use defaults
	// if eeprom version is less than the min required version, wipe and use defaults
	// if eeprom version is greater than the current app version, user must have downgraded - wipe and use defaults
	if (!flash_read_words(&m_eeprom_data,
			sizeof(m_eeprom_data)
					/ sizeof(uint32_t))
	    || m_eeprom_data.eeprom_version < EEPROM_MIN_COMPAT_VERSION
	    || m_eeprom_data.eeprom_version > EEPROM_VERSION
	    )
		// If we are using default data it doesn't get written to flash until someone calls write
		memcpy(&m_eeprom_data, &m_eeprom_data_defaults,
				sizeof(m_eeprom_data_defaults));

	eeprom_init_variables();
	set_conversions();

	// prepare torque_sensor_calibration_table as it will be used at begin to init the motor
	prepare_torque_sensor_calibration_table();
}

void eeprom_init_variables(void) {
	ui_vars_t *ui_vars = get_ui_vars();
	rt_vars_t *rt_vars = get_rt_vars();

	// copy data final variables
	ui_vars->ui8_assist_level = m_eeprom_data.ui8_assist_level;
	ui_vars->ui16_wheel_perimeter = m_eeprom_data.ui16_wheel_perimeter;
	ui_vars->wheel_max_speed_x10 =
			m_eeprom_data.ui8_wheel_max_speed * 10;
	ui_vars->ui8_units_type = m_eeprom_data.ui8_units_type;
	ui_vars->ui32_wh_x10_offset = m_eeprom_data.ui32_wh_x10_offset;
	ui_vars->ui32_wh_x10_100_percent =
			m_eeprom_data.ui32_wh_x10_100_percent;
	ui_vars->ui8_battery_soc_enable =
			m_eeprom_data.ui8_battery_soc_enable;
  ui_vars->ui8_time_field_enable =
      m_eeprom_data.ui8_time_field_enable;
  ui_vars->ui8_target_max_battery_power_div25 =
      m_eeprom_data.ui8_target_max_battery_power_div25;
	ui_vars->ui8_battery_max_current =
			m_eeprom_data.ui8_battery_max_current;
  ui_vars->ui8_motor_max_current =
      m_eeprom_data.ui8_motor_max_current;
  ui_vars->ui8_motor_current_min_adc =
      m_eeprom_data.ui8_motor_current_min_adc;
  ui_vars->ui8_field_weakening =
      m_eeprom_data.ui8_field_weakening;
	ui_vars->ui8_ramp_up_amps_per_second_x10 =
			m_eeprom_data.ui8_ramp_up_amps_per_second_x10;
	ui_vars->ui16_battery_low_voltage_cut_off_x10 =
			m_eeprom_data.ui16_battery_low_voltage_cut_off_x10;
	ui_vars->ui8_motor_type = m_eeprom_data.ui8_motor_type;
	ui_vars->ui8_motor_current_control_mode = m_eeprom_data.ui8_motor_current_control_mode;
	ui_vars->ui8_motor_assistance_startup_without_pedal_rotation =
			m_eeprom_data.ui8_motor_assistance_startup_without_pedal_rotation;
	ui_vars->ui8_temperature_limit_feature_enabled =
			m_eeprom_data.ui8_temperature_limit_feature_enabled;
	COPY_ARRAY(ui_vars, &m_eeprom_data, ui16_assist_level_factor);
	ui_vars->ui8_number_of_assist_levels =
			m_eeprom_data.ui8_number_of_assist_levels;
	ui_vars->ui8_startup_motor_power_boost_feature_enabled =
			m_eeprom_data.ui8_startup_motor_power_boost_feature_enabled;
	ui_vars->ui8_startup_motor_power_boost_limit_power =
			m_eeprom_data.ui8_startup_motor_power_boost_limit_power;
	ui_vars->ui8_startup_motor_power_boost_always =
			m_eeprom_data.ui8_startup_motor_power_boost_always;
	COPY_ARRAY(ui_vars, &m_eeprom_data,
			ui16_startup_motor_power_boost_factor);
	ui_vars->ui8_startup_motor_power_boost_time =
			m_eeprom_data.ui8_startup_motor_power_boost_time;
	ui_vars->ui8_startup_motor_power_boost_fade_time =
			m_eeprom_data.ui8_startup_motor_power_boost_fade_time;
	ui_vars->ui8_motor_temperature_min_value_to_limit =
			m_eeprom_data.ui8_motor_temperature_min_value_to_limit;
	ui_vars->ui8_motor_temperature_max_value_to_limit =
			m_eeprom_data.ui8_motor_temperature_max_value_to_limit;
	ui_vars->ui16_battery_voltage_reset_wh_counter_x10 =
			m_eeprom_data.ui16_battery_voltage_reset_wh_counter_x10;
	ui_vars->ui8_lcd_power_off_time_minutes =
			m_eeprom_data.ui8_lcd_power_off_time_minutes;
	ui_vars->ui8_lcd_backlight_on_brightness =
			m_eeprom_data.ui8_lcd_backlight_on_brightness;
	ui_vars->ui8_lcd_backlight_off_brightness =
			m_eeprom_data.ui8_lcd_backlight_off_brightness;
	ui_vars->ui16_battery_pack_resistance_x1000 =
			m_eeprom_data.ui16_battery_pack_resistance_x1000;
	ui_vars->ui8_offroad_feature_enabled =
			m_eeprom_data.ui8_offroad_feature_enabled;
	ui_vars->ui8_offroad_enabled_on_startup =
			m_eeprom_data.ui8_offroad_enabled_on_startup;
	ui_vars->ui8_offroad_speed_limit =
			m_eeprom_data.ui8_offroad_speed_limit;
	ui_vars->ui8_offroad_power_limit_enabled =
			m_eeprom_data.ui8_offroad_power_limit_enabled;
	ui_vars->ui8_offroad_power_limit_div25 =
			m_eeprom_data.ui8_offroad_power_limit_div25;
	rt_vars->ui32_odometer_x10 = m_eeprom_data.ui32_odometer_x10; // odometer value should reside on RT vars
	ui_vars->ui8_walk_assist_feature_enabled =
			m_eeprom_data.ui8_walk_assist_feature_enabled;
	COPY_ARRAY(ui_vars, &m_eeprom_data, ui8_walk_assist_level_factor);
  ui_vars->ui8_torque_sensor_calibration_pedal_ground = m_eeprom_data.ui8_torque_sensor_calibration_pedal_ground;

  ui_vars->ui8_torque_sensor_calibration_feature_enabled = m_eeprom_data.ui8_torque_sensor_calibration_feature_enabled;
  ui_vars->ui8_torque_sensor_calibration_pedal_ground = m_eeprom_data.ui8_torque_sensor_calibration_pedal_ground;
  for (uint8_t i = 0; i < 8; i++) {
    ui_vars->ui16_torque_sensor_calibration_table_left[i][0] = m_eeprom_data.ui16_torque_sensor_calibration_table_left[i][0];
    ui_vars->ui16_torque_sensor_calibration_table_left[i][1] = m_eeprom_data.ui16_torque_sensor_calibration_table_left[i][1];
    ui_vars->ui16_torque_sensor_calibration_table_right[i][0] = m_eeprom_data.ui16_torque_sensor_calibration_table_right[i][0];
    ui_vars->ui16_torque_sensor_calibration_table_right[i][1] = m_eeprom_data.ui16_torque_sensor_calibration_table_right[i][1];
  }

  ui_vars->ui8_street_mode_function_enabled =
      m_eeprom_data.ui8_street_mode_function_enabled;
  ui_vars->ui8_street_mode_enabled =
      m_eeprom_data.ui8_street_mode_enabled;
  ui_vars->ui8_street_mode_enabled_on_startup =
      m_eeprom_data.ui8_street_mode_enabled_on_startup;
  ui_vars->ui8_street_mode_speed_limit =
      m_eeprom_data.ui8_street_mode_speed_limit;
  ui_vars->ui8_street_mode_power_limit_div25 =
      m_eeprom_data.ui8_street_mode_power_limit_div25;
  ui_vars->ui8_street_mode_throttle_enabled =
      m_eeprom_data.ui8_street_mode_throttle_enabled;
  ui_vars->ui8_street_mode_hotkey_enabled =
      m_eeprom_data.ui8_street_mode_hotkey_enabled;

  ui_vars->ui8_pedal_cadence_fast_stop =
      m_eeprom_data.ui8_pedal_cadence_fast_stop;
  ui_vars->ui8_coast_brake_adc =
      m_eeprom_data.ui8_coast_brake_adc;
  ui_vars->ui8_adc_lights_current_offset =
      m_eeprom_data.ui8_adc_lights_current_offset;
  ui_vars->ui8_throttle_virtual_step =
      m_eeprom_data.ui8_throttle_virtual_step;
  ui_vars->ui8_torque_sensor_filter =
      m_eeprom_data.ui8_torque_sensor_filter;
  ui_vars->ui8_torque_sensor_adc_threshold =
      m_eeprom_data.ui8_torque_sensor_adc_threshold;
  ui_vars->ui8_coast_brake_enable =
      m_eeprom_data.ui8_coast_brake_enable;
}

void eeprom_write_variables(void) {
	ui_vars_t *ui_vars = get_ui_vars();
	m_eeprom_data.ui8_assist_level = ui_vars->ui8_assist_level;
	m_eeprom_data.ui16_wheel_perimeter = ui_vars->ui16_wheel_perimeter;
	m_eeprom_data.ui8_wheel_max_speed =
			ui_vars->wheel_max_speed_x10 / 10;
	m_eeprom_data.ui8_units_type = ui_vars->ui8_units_type;
	m_eeprom_data.ui32_wh_x10_offset = ui_vars->ui32_wh_x10_offset;
	m_eeprom_data.ui32_wh_x10_100_percent =
			ui_vars->ui32_wh_x10_100_percent;
	m_eeprom_data.ui8_battery_soc_enable =
			ui_vars->ui8_battery_soc_enable;
  m_eeprom_data.ui8_time_field_enable =
      ui_vars->ui8_time_field_enable;
  m_eeprom_data.ui8_target_max_battery_power_div25 =
      ui_vars->ui8_target_max_battery_power_div25;
  m_eeprom_data.ui8_battery_max_current =
      ui_vars->ui8_battery_max_current;
  m_eeprom_data.ui8_motor_max_current =
      ui_vars->ui8_motor_max_current;
  m_eeprom_data.ui8_motor_current_min_adc =
      ui_vars->ui8_motor_current_min_adc;
  m_eeprom_data.ui8_field_weakening =
      ui_vars->ui8_field_weakening;
	m_eeprom_data.ui8_ramp_up_amps_per_second_x10 =
			ui_vars->ui8_ramp_up_amps_per_second_x10;
	m_eeprom_data.ui16_battery_low_voltage_cut_off_x10 =
			ui_vars->ui16_battery_low_voltage_cut_off_x10;
	m_eeprom_data.ui8_motor_type = ui_vars->ui8_motor_type;
	m_eeprom_data.ui8_motor_current_control_mode = ui_vars->ui8_motor_current_control_mode;
	m_eeprom_data.ui8_motor_assistance_startup_without_pedal_rotation =
			ui_vars->ui8_motor_assistance_startup_without_pedal_rotation;
	m_eeprom_data.ui8_temperature_limit_feature_enabled =
			ui_vars->ui8_temperature_limit_feature_enabled;
	COPY_ARRAY(&m_eeprom_data, ui_vars, ui16_assist_level_factor);
	m_eeprom_data.ui8_number_of_assist_levels =
			ui_vars->ui8_number_of_assist_levels;
	m_eeprom_data.ui8_startup_motor_power_boost_feature_enabled =
			ui_vars->ui8_startup_motor_power_boost_feature_enabled;
	m_eeprom_data.ui8_startup_motor_power_boost_always =
			ui_vars->ui8_startup_motor_power_boost_always;
	m_eeprom_data.ui8_startup_motor_power_boost_limit_power =
			ui_vars->ui8_startup_motor_power_boost_limit_power;
	COPY_ARRAY(&m_eeprom_data, ui_vars,
			ui16_startup_motor_power_boost_factor);
	m_eeprom_data.ui8_startup_motor_power_boost_time =
			ui_vars->ui8_startup_motor_power_boost_time;
	m_eeprom_data.ui8_startup_motor_power_boost_fade_time =
			ui_vars->ui8_startup_motor_power_boost_fade_time;
	m_eeprom_data.ui8_motor_temperature_min_value_to_limit =
			ui_vars->ui8_motor_temperature_min_value_to_limit;
	m_eeprom_data.ui8_motor_temperature_max_value_to_limit =
			ui_vars->ui8_motor_temperature_max_value_to_limit;
	m_eeprom_data.ui16_battery_voltage_reset_wh_counter_x10 =
			ui_vars->ui16_battery_voltage_reset_wh_counter_x10;
	m_eeprom_data.ui8_lcd_power_off_time_minutes =
			ui_vars->ui8_lcd_power_off_time_minutes;
	m_eeprom_data.ui8_lcd_backlight_on_brightness =
			ui_vars->ui8_lcd_backlight_on_brightness;
	m_eeprom_data.ui8_lcd_backlight_off_brightness =
			ui_vars->ui8_lcd_backlight_off_brightness;
	m_eeprom_data.ui16_battery_pack_resistance_x1000 =
			ui_vars->ui16_battery_pack_resistance_x1000;
	m_eeprom_data.ui8_offroad_feature_enabled =
			ui_vars->ui8_offroad_feature_enabled;
	m_eeprom_data.ui8_offroad_enabled_on_startup =
			ui_vars->ui8_offroad_enabled_on_startup;
	m_eeprom_data.ui8_offroad_speed_limit =
			ui_vars->ui8_offroad_speed_limit;
	m_eeprom_data.ui8_offroad_power_limit_enabled =
			ui_vars->ui8_offroad_power_limit_enabled;
	m_eeprom_data.ui8_offroad_power_limit_div25 =
			ui_vars->ui8_offroad_power_limit_div25;
	m_eeprom_data.ui32_odometer_x10 = ui_vars->ui32_odometer_x10;
	m_eeprom_data.ui8_walk_assist_feature_enabled =
			ui_vars->ui8_walk_assist_feature_enabled;
	COPY_ARRAY(&m_eeprom_data, ui_vars, ui8_walk_assist_level_factor);

  m_eeprom_data.ui8_torque_sensor_calibration_feature_enabled = ui_vars->ui8_torque_sensor_calibration_feature_enabled;
  m_eeprom_data.ui8_torque_sensor_calibration_pedal_ground = ui_vars->ui8_torque_sensor_calibration_pedal_ground;
  for (uint8_t i = 0; i < 8; i++) {
    m_eeprom_data.ui16_torque_sensor_calibration_table_left[i][0] = ui_vars->ui16_torque_sensor_calibration_table_left[i][0];
    m_eeprom_data.ui16_torque_sensor_calibration_table_left[i][1] = ui_vars->ui16_torque_sensor_calibration_table_left[i][1];
    m_eeprom_data.ui16_torque_sensor_calibration_table_right[i][0] = ui_vars->ui16_torque_sensor_calibration_table_right[i][0];
    m_eeprom_data.ui16_torque_sensor_calibration_table_right[i][1] = ui_vars->ui16_torque_sensor_calibration_table_right[i][1];
  }

  m_eeprom_data.ui8_street_mode_function_enabled =
      ui_vars->ui8_street_mode_function_enabled;
  m_eeprom_data.ui8_street_mode_enabled =
      ui_vars->ui8_street_mode_enabled;
  m_eeprom_data.ui8_street_mode_enabled_on_startup =
      ui_vars->ui8_street_mode_enabled_on_startup;
  m_eeprom_data.ui8_street_mode_speed_limit =
      ui_vars->ui8_street_mode_speed_limit;
  m_eeprom_data.ui8_street_mode_power_limit_div25 =
      ui_vars->ui8_street_mode_power_limit_div25;
  m_eeprom_data.ui8_street_mode_throttle_enabled =
      ui_vars->ui8_street_mode_throttle_enabled;
  m_eeprom_data.ui8_street_mode_hotkey_enabled =
      ui_vars->ui8_street_mode_hotkey_enabled;

  m_eeprom_data.ui8_pedal_cadence_fast_stop =
      ui_vars->ui8_pedal_cadence_fast_stop;
  m_eeprom_data.ui8_coast_brake_adc =
      ui_vars->ui8_coast_brake_adc;
  m_eeprom_data.ui8_adc_lights_current_offset =
      ui_vars->ui8_adc_lights_current_offset;
  m_eeprom_data.ui8_throttle_virtual_step =
      ui_vars->ui8_throttle_virtual_step;
  m_eeprom_data.ui8_torque_sensor_filter =
      ui_vars->ui8_torque_sensor_filter;
  m_eeprom_data.ui8_torque_sensor_adc_threshold =
      ui_vars->ui8_torque_sensor_adc_threshold;
  m_eeprom_data.ui8_coast_brake_enable =
      ui_vars->ui8_coast_brake_enable;

	flash_write_words(&m_eeprom_data, sizeof(m_eeprom_data) / sizeof(uint32_t));
}

void eeprom_init_defaults(void)
{
  memset(&m_eeprom_data, 0, sizeof(m_eeprom_data));
  memcpy(&m_eeprom_data,
      &m_eeprom_data_defaults,
      sizeof(m_eeprom_data_defaults));

  eeprom_init_variables();
  set_conversions();
  // prepare torque_sensor_calibration_table as it will be used at begin to init the motor
  prepare_torque_sensor_calibration_table();

  flash_write_words(&m_eeprom_data, sizeof(m_eeprom_data) / sizeof(uint32_t));
}