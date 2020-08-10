#ifdef OLED_DRIVER_ENABLE
#include QMK_KEYBOARD_H

extern uint8_t is_master;

// When add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);
const char *read_keylog(void);
const char *read_keylogs(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);

typedef struct {
  uint8_t state;
  char name[8];
} LAYER_DISPLAY_NAME;

#define LAYER_DISPLAY_MAX 5
const LAYER_DISPLAY_NAME layer_display_name[LAYER_DISPLAY_MAX] = {
  {0, "Base"},
  {2, "Code"},
  {4, "Fn"},
  {6, "Fn+Code"},
  {__UINT8_MAX__, "?"},
};
static uint8_t layer_name_idx;
static char layer_status_buf[24] = "Layer: Base\n";

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
void update_keymap_status(void) {
  snprintf(layer_status_buf, sizeof(layer_status_buf) - 1, "Layer:%s RGB: %d\n",
           layer_display_name[layer_name_idx].name, rgblight_config.mode);
}
#else
void update_keymap_status(void) {
  snprintf(layer_status_buf, sizeof(layer_status_buf) - 1, "Layer:%s\n",
           layer_display_name[layer_name_idx].name);
}
#endif

// declared in users/rs/rs.c
void rgb_mod_changed_keymap(void) {
  update_keymap_status();
}

// declared in users/rs/rs.c
void keylog_set_keymap(uint16_t keycode, keyrecord_t *record) {
  set_keylog(keycode, record);
}

uint32_t layer_state_set_user(uint32_t state) {
  for (layer_name_idx = 0; layer_name_idx < LAYER_DISPLAY_MAX; ++layer_name_idx) {
    if (state == 0 && layer_display_name[layer_name_idx].state == default_layer_state) {
      break;
    } else if (state != 0 && layer_display_name[layer_name_idx].state == state) {
      break;
    }
  }
  update_keymap_status();
  return state;
}

static inline void render_keymap_status(void) {
  oled_write_ln(layer_status_buf, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_keymap_status();
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
  } else {
    oled_write(read_logo(), false);
  }
}

#endif
