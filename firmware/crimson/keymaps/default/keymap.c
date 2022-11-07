#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_all(
		KC_SPC, KC_SPC, KC_SPC, KC_ENT, KC_SPC, KC_SPC, KC_SPC),

	[1] = LAYOUT_all(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	
};

/* OLED */

#ifdef OLED_DRIVER_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _ADJ:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    return false;
}
#endif

/*static const char PROGMEM test[] = {

// 'Untitled-1', 128x32px
 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x80, 0x00, 0x3e, 0x1e, 0x03, 0xf8, 0x07, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x80, 0x00, 0x3e, 0x1e, 0x01, 0xf8, 0x07, 0xff, 0x07, 0xff, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x80, 0x00, 0x3e, 0x1e, 0x01, 0xf8, 0x07, 0xfe, 0x07, 0xff, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x01, 0xf8, 0x07, 0xfe, 0x03, 0xff, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x01, 0xf0, 0x07, 0xfc, 0x03, 0xff, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x11, 0xf0, 0x87, 0xfc, 0x03, 0xff, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x10, 0xf0, 0x87, 0xfc, 0x21, 0xff, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x10, 0xf0, 0x87, 0xf8, 0x61, 0xff, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x10, 0xf1, 0x87, 0xf8, 0x61, 0xff, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x18, 0xe1, 0x87, 0xf8, 0xf0, 0xff, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x18, 0x61, 0x87, 0xf0, 0xf0, 0xff, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x18, 0x61, 0x87, 0xf0, 0xf8, 0x7f, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x18, 0x63, 0x87, 0xe1, 0xf8, 0x7f, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x1c, 0x43, 0x87, 0xe0, 0x00, 0x7f, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x1c, 0x03, 0x87, 0xe0, 0x00, 0x3f, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x1c, 0x03, 0x87, 0xc0, 0x00, 0x3f, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x1c, 0x07, 0x87, 0xc0, 0x00, 0x3f, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x1e, 0x07, 0x87, 0x83, 0xfe, 0x1f, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x1e, 0x07, 0x87, 0x87, 0xfe, 0x1f, 0x00, 0x01, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x1e, 0x07, 0x87, 0x87, 0xff, 0x0f, 0x00, 0x01, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x1e, 0x07, 0x87, 0x0f, 0xff, 0x0f, 0x00, 0x01, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x0f, 0xfe, 0x1e, 0x1e, 0x0f, 0x87, 0x0f, 0xff, 0x0f, 0x00, 0x01, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};



void oled_task_user(void) {

// oled_write_P(PSTR("Hello World!"), false);

//oled_write_P(test, false);

oled_write_raw_P(test, sizeof(test));

}
#endif */

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRB |= (1 << 4); PORTB &= ~(1 << 4);
	} else {
		DDRB &= ~(1 << 4); PORTB &= ~(1 << 4);
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}