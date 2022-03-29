#ifndef _ANALOG_COMP_H_
#define _ANALOG_COMP_H_

#include <avr/io.h>
#include <stdbool.h>

#include "digitalio_avr.h"

void acomp_enable();
void acomp_disable();

bool acomp_output_state_check();

void acomp_int_enable();
void acomp_int_disable();


enum acomp_int_mode_t {
    ACOMP_TOGGLE_OUTPUT = 0,
    ACOMP_RESERVED,
    ACOMP_FALLING_EDGE,
    ACOMP_RISING_EDGE
};

void acomp_int_mode(enum acomp_int_mode_t mode);


enum neg_inp_t {
    ACOMP_ADC_0 = 0,
    ACOMP_ADC_1,
    ACOMP_ADC_2,
    ACOMP_ADC_3,
    ACOMP_ADC_4,
    ACOMP_ADC_5,
    ACOMP_ADC_6,
    ACOMP_ADC_7,
    ACOMP_AIN1
};

void acomp_mux_input(enum neg_inp_t inp);


/*_ANALOG_COMP_H_*/
#endif
