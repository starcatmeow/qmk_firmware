#include "chocopad.h"

#define _BASE 0
#define _FN1 1
#define _FN2 2

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_X1 MO(_FN1)
#define KC_X2 MO(_FN2)
#define KC_RST RESET
#define KC_BSTP BL_STEP
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_X1_0 LT(MO(_FN1), KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = KC_KEYMAP(
  //,----+----+----+----.
       7 ,  8 ,  9 ,BSPC,
  //|----+----+----+----|
       4 ,  5 ,  6 ,SLSH,
  //|----+----+----+----|
       1 ,  2 ,  3 ,ASTR,
  //|----+----+----+----|
     X1_0, DOT,MINS,PLUS
  //`----+----+----+----'
  ),

  [_FN1] = KC_KEYMAP(
  //,----+----+----+----.
     RTOG,RHUI,RSAI,RVAI,
  //|----+----+----+----|
     RMOD,RHUD,RSAD,RVAD,
  //|----+----+----+----|
     BSTP,    ,    ,    ,
  //|----+----+----+----|
         ,    ,    , ENT
  //`----+----+----+----'
  ),

  [_FN2] = KC_KEYMAP(
  //,----+----+----+----.
     RTOG,RHUI,RSAI,RVAI,
  //|----+----+----+----|
     RMOD,RHUD,RSAD,RVAD,
  //|----+----+----+----|
         ,    ,    ,RST ,
  //|----+----+----+----|
     BSTP,    ,    ,
  //`----+----+----+----'
  )

};
