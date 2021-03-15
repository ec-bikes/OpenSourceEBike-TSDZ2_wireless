using Toybox.WatchUi;
using Toybox.System;


var fieldDataID = 4;

// 1 - battery voltage
// 2 - battery current
// 3 - battery SOC
// 4 - battery used energy
// 5 - motor current
// 6 - motor power
// 7 - motor PWM
// 8 - motor speed
// 9 - motor temperature
// 10 - cadence
// 11 - human power
// 12 - assist level
// 13 - odometer

class DataField extends WatchUi.SimpleDataField {
  hidden var ant_device;
  var fieldData = 1;

  function initialize(device) {
    SimpleDataField.initialize();

      switch (fieldDataID) {
        case 1:
          label = "bat voltage";
          break;

        case 2:
          label = "bat current";
          break;

        case 3:
          label = "bat SOC";
          break;

        case 4:
          label = "bat used energy";
          break;

        case 5:
          label = "mot current";
          break;

        case 6:
          label = "mot power";
          break;

        case 7:
          label = "mot PWM";
          break;

        case 8:
          label = "mot speed";
          break;

        case 9:
          label = "mot temperature";
          break;

        case 10:
          label = "cadence";
          break;

        case 11:
          label = "human power";
          break;

        case 12:
          label = "assist level";
          break;

        case 13:
          label = "odometer";
          break;
      }

    ant_device = device;
  }

  function compute(info) {

    if (!ant_device.opened) {
      ant_device.maybe_open();
//      return "Idle";
      return ant_device.getData(fieldDataID);
    } else if (ant_device.searching) {
//      return "Searching...";
      return ant_device.getData(fieldDataID);
    }

    var return_value = "---";
//    switch (fieldDataID) {
//      case 1:
//      case 4:
//      case 2:
//      case 5:
//      case 13:
//        return_value = ant_device.getData(fieldDataID).format("%.1f");
//        break;
//
//      case 3:
//      case 6:
//      case 7:
//      case 8:
//      case 9:
//      case 10:
//      case 11:
//      case 12:
//        return_value = ant_device.getData(fieldDataID);
//        break;
//    }

return_value = ant_device.getData(fieldDataID);

    return return_value;
  }
}
