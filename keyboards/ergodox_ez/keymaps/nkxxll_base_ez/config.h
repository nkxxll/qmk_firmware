/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 5

#undef TAPPING_TERM
#define TAPPING_TERM 200

#define PERMISSIVE_HOLD

#define QUICK_TAP_TERM 0

#define COMBO_TERM 10

#define USB_SUSPEND_WAKEUP_DELAY 0
#define HOLD_ON_OTHER_KEY_PRESS
#define FIRMWARE_VERSION u8"qBW9L/YBrZZ"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define HCS(report) host_consumer_send(record->event.pressed ? report : 0); return false

