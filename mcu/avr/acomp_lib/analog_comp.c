#include "inc/analog_comp.h"

void acomp_enable()
{
    digital_write(ACSR, ACD, LOW);
}

void acomp_disable()
{
    digital_write(ACSR, ACD, HIGH);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

bool acomp_output_state_check()
{
    return digital_read(ACSR, ACO);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void acomp_int_enable()
{
    digital_write(ACSR, ACIE, HIGH);
}

void acomp_int_disable()
{
    digital_write(ACSR, ACIE, LOW);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void acomp_int_mode(enum acomp_int_mode_t mode)
{
    ACSR &= 0b11111100;
    ACSR |= mode;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void acomp_mux_input(enum neg_inp_t inp)
{
    if(inp == ACOMP_AIN1) {
        digital_write(ADCSRB, ACME, LOW);
        digital_write(ADCSRA, ADEN, LOW);
    } else {
        digital_write(ADCSRB, ACME, HIGH);
        digital_write(ADCSRA, ADEN, LOW);
        ADMUX &= 0b11110000;
        ADMUX |= inp;
    }
}
