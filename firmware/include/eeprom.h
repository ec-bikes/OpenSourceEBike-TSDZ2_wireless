/*
 * Bafang LCD 850C firmware
 *
 * Copyright (C) Casainho, 2018.
 *
 * Released under the GPL License, Version 3
 */

#ifndef _EEPROM_H_
#define _EEPROM_H_

#include "state.h"

// For compatible changes, just add new fields at the end of the table (they will be inited to 0xff for old eeprom images).  For incompatible
// changes bump up EEPROM_MIN_COMPAT_VERSION and the user's EEPROM settings will be discarded.
#define EEPROM_MIN_COMPAT_VERSION 0x3B
#define EEPROM_VERSION 0x3B

typedef struct eeprom_data {
	uint8_t eeprom_version; // Used to detect changes in eeprom encoding, if != EEPROM_VERSION we will not use it

	uint8_t ui8_assist_level;
	uint16_t ui16_wheel_perimeter;
	uint8_t ui8_wheel_max_speed;
	uint8_t ui8_units_type;
	uint32_t ui32_wh_x10_offset;
	uint32_t ui32_wh_x10_100_percent;
	uint8_t ui8_battery_soc_enable;
	uint8_t ui8_time_field_enable;
	uint8_t ui8_target_max_battery_power_div25;
	uint8_t ui8_battery_max_current;
	uint8_t ui8_motor_max_current;
  uint8_t ui8_motor_current_min_adc;
  uint8_t ui8_field_weakening;
	uint8_t ui8_ramp_up_amps_per_second_x10;
	uint16_t ui16_battery_low_voltage_cut_off_x10;
	uint8_t ui8_motor_type;
	uint8_t ui8_motor_current_control_mode;
	uint8_t ui8_motor_assistance_startup_without_pedal_rotation;
	uint16_t ui16_assist_level_factor[ASSIST_LEVEL_NUMBER];
	uint8_t ui8_number_of_assist_levels;
	uint8_t ui8_startup_motor_power_boost_feature_enabled;
	uint8_t ui8_startup_motor_power_boost_always;
	uint8_t ui8_startup_motor_power_boost_limit_power;
	uint16_t ui16_startup_motor_power_boost_factor[ASSIST_LEVEL_NUMBER];
	uint8_t ui8_startup_motor_power_boost_time;
	uint8_t ui8_startup_motor_power_boost_fade_time;
	uint8_t ui8_temperature_limit_feature_enabled;
	uint8_t ui8_motor_temperature_min_value_to_limit;
	uint8_t ui8_motor_temperature_max_value_to_limit;
	uint16_t ui16_battery_voltage_reset_wh_counter_x10;
	uint8_t ui8_lcd_power_off_time_minutes;
	uint8_t ui8_lcd_backlight_on_brightness;
	uint8_t ui8_lcd_backlight_off_brightness;
	uint16_t ui16_battery_pack_resistance_x1000;
	uint8_t ui8_offroad_feature_enabled;
	uint8_t ui8_offroad_enabled_on_startup;
	uint8_t ui8_offroad_speed_limit;
	uint8_t ui8_offroad_power_limit_enabled;
	uint8_t ui8_offroad_power_limit_div25;
	uint32_t ui32_odometer_x10;
	uint8_t ui8_walk_assist_feature_enabled;
	uint8_t ui8_walk_assist_level_factor[ASSIST_LEVEL_NUMBER];

	uint8_t ui8_battery_soc_increment_decrement;
	uint8_t ui8_buttons_up_down_invert;
  uint8_t ui8_torque_sensor_calibration_feature_enabled;
  uint8_t ui8_torque_sensor_calibration_pedal_ground;
  uint16_t ui16_torque_sensor_calibration_table_left[8][2];
  uint16_t ui16_torque_sensor_calibration_table_right[8][2];

  uint8_t ui8_street_mode_function_enabled;
  uint8_t ui8_street_mode_enabled;
  uint8_t ui8_street_mode_enabled_on_startup;
  uint8_t ui8_street_mode_speed_limit;
  uint8_t ui8_street_mode_power_limit_div25;
  uint8_t ui8_street_mode_throttle_enabled;
  uint8_t ui8_street_mode_hotkey_enabled;

  uint8_t ui8_pedal_cadence_fast_stop;
  uint8_t ui8_coast_brake_adc;
  uint8_t ui8_adc_lights_current_offset;
  uint8_t ui8_throttle_virtual_step;
  uint8_t ui8_torque_sensor_filter;
  uint8_t ui8_torque_sensor_adc_threshold;
  uint8_t ui8_coast_brake_enable;

// FIXME align to 32 bit value by end of structure and pack other fields
} eeprom_data_t;

void eeprom_init(void);
void eeprom_init_variables(void);
void eeprom_write_variables(void);
void eeprom_init_defaults(void);

// *************************************************************************** //
// EEPROM memory variables default values
#define DEFAULT_VALUE_ASSIST_LEVEL                                  0
#define DEFAULT_VALUE_NUMBER_OF_ASSIST_LEVELS                       20
#define DEFAULT_VALUE_WHEEL_PERIMETER                               2100 // 27.5'' wheel: 2100mm perimeter
#define DEFAULT_VALUE_WHEEL_MAX_SPEED                               50
#define DEFAULT_VALUE_UNITS_TYPE                                    0 // 0 = km/h
#define DEFAULT_VALUE_WH_X10_OFFSET                                 0
#define DEFAULT_VALUE_HW_X10_100_PERCENT                            4000 // default to a battery of 400 Wh
#define DEFAULT_VALUE_BATTERY_MAX_CURRENT                           16 // 16 amps
#define DEFAULT_VALUE_MOTOR_MAX_CURRENT                             16 // 16 amps
#define DEFAULT_VALUE_CURRENT_MIN_ADC                               1 // 1 unit, 0.156 A
#define DEFAULT_VALUE_RAMP_UP_AMPS_PER_SECOND_X10                   80 // 8.0 amps per second ramp up
#define DEFAULT_VALUE_TARGET_MAX_BATTERY_POWER                      60 // e.g. 20 = 20 * 25 = 500, 0 is disabled
#define DEFAULT_VALUE_BATTERY_LOW_VOLTAGE_CUT_OFF_X10               420 // 52v battery, LVC = 42.0 (3.0 * 14)
#define DEFAULT_VALUE_MOTOR_CURRENT_CONTROL_MODE                    1 // 0 power; 1 torque
#define DEFAULT_VALUE_MOTOR_TYPE                                    0 // 0 = 48V
#define DEFAULT_VALUE_MOTOR_ASSISTANCE_WITHOUT_PEDAL_ROTATION       0 // 0 to keep this feature disable
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_1                         5 // 0.005 and each next increase +33%
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_2                         9
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_3                         12
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_4                         16
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_5                         21
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_6                         28
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_7                         37
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_8                         49
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_9                         65
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_10                        87
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_11                        115
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_12                        153
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_13                        204
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_14                        271
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_15                        360
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_16                        479
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_17                        637
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_18                        848
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_19                        1128
#define DEFAULT_VALUE_ASSIST_LEVEL_FACTOR_20                        1500
#define DEFAULT_VALUE_WALK_ASSIST_FEATURE_ENABLED                   1
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_1                    35
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_2                    40
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_3                    45
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_4                    50
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_5                    55
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_6                    60
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_7                    70
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_8                    80
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_9                    90
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_10                   90
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_11                   90
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_12                   90
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_13                   90
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_14                   90
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_15                   90
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_16                   90
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_17                   90
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_18                   90
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_19                   90
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_FACTOR_20                   90
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_FEATURE_ENABLED     0
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ALWAYS              1
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_1      5
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_2      8
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_3      12
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_4      18
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_5      27
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_6      41
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_7      62
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_8      93
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_9      140
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_10     140
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_11     140
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_12     140
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_13     140
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_14     140
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_15     140
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_16     140
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_17     140
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_18     140
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_19     140
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_20     140
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_TIME                20 // 2.0 seconds
#define DEFAULT_VALUE_STARTUP_MOTOR_POWER_BOOST_FADE_TIME           35 // 3.5 seconds
#define DEFAULT_VALUE_MOTOR_TEMPERATURE_FEATURE_ENABLE              0
#define DEFAULT_VALUE_MOTOR_TEMPERATURE_MIN_VALUE_LIMIT             75 // 75 degrees celsius
#define DEFAULT_VALUE_MOTOR_TEMPERATURE_MAX_VALUE_LIMIT             85 // 85 degrees celsius
#define DEFAULT_VALUE_BATTERY_VOLTAGE_RESET_WH_COUNTER_X10          584 // 52v battery, 58.4 volts at fully charged
#define DEFAULT_VALUE_LCD_POWER_OFF_TIME                            60 // 60 minutes, each unit 1 minute
#define DEFAULT_VALUE_BATTERY_PACK_RESISTANCE                       300 // 52v battery, 14S3P measured 300 milli ohms
#define DEFAULT_VALUE_OFFROAD_FEATURE_ENABLED                       0
#define DEFAULT_VALUE_OFFROAD_MODE_ENABLED_ON_STARTUP               0
#define DEFAULT_VALUE_OFFROAD_SPEED_LIMIT                           25
#define DEFAULT_VALUE_OFFROAD_POWER_LIMIT_ENABLED                   0
#define DEFAULT_VALUE_OFFROAD_POWER_LIMIT_DIV25                     10 //10 * 25 = 250W
#define DEFAULT_VALUE_ODOMETER_X10                                  0
#define DEFAULT_STREET_MODE_FUNCTION_ENABLE                         0 // disabled
#define DEFAULT_STREET_MODE_ENABLE_AT_STARTUP                       0 // disabled
#define DEFAULT_STREET_MODE_ENABLE                                  0 // disabled
#define DEFAULT_STREET_MODE_SPEED_LIMIT                             25 // 25 km/h
#define DEFAULT_STREET_MODE_POWER_LIMIT                             10 // 250W --> 250 / 25 = 10
#define DEFAULT_STREET_MODE_THROTTLE_ENABLE                         0 // disabled
#define DEFAULT_STREET_MODE_HOTKEY_ENABLE                           0 // disabled
#define DEFAULT_PEDAL_CADENCE_FAST_STOP_ENABLE                      0 // disabled
#define DEFAULT_COAST_BRAKE_ADC                                     15 // 15: tested by plpetrov user on 28.04.2020:
#define DEFAULT_FIELD_WEAKENING                                     1 // 1 enabled
#define DEFAULT_ADC_LIGHTS_CURRENT_OFFSET                           1
#define DEFAULT_THROTTLE_VIRTUAL_STEP                               5
#define DEFAULT_TORQUE_SENSOR_FILTER                                20 // 20%
#define DEFAULT_TORQUE_SENSOR_ADC_THRESHOLD                         20
#define DEFAULT_COAST_BRAKE_ENABLE                                  0 // disable

#define DEFAULT_TORQUE_SENSOR_CALIBRATION_FEATURE_ENABLE            0 // disabled
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_PEDAL_GROUND              0 // left pedal
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_1             0
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_1                157
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_2             10
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_2                207
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_3             15
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_3                230
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_4             19
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_4                241
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_5             25
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_5                250
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_6             40
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_6                260
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_7             54
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_7                266
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_WEIGHT_8             105
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_LEFT_ADC_8                279
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_1             0
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_1                161
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_2             15
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_2                233
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_3             19
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_3                245
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_4             25
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_4                258
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_5             30
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_5                266
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_6             40
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_6                276
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_7             54
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_7                284
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_WEIGHT_8             105
#define DEFAULT_TORQUE_SENSOR_CALIBRATION_RIGHT_ADC_8                300

// *************************************************************************** //

#endif /* _EEPROM_H_ */