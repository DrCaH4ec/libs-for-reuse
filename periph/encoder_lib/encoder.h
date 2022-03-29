#ifndef _ENCODER_H_
#define _ENCODER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "defines.h"
#include "digitalio_avr.h"

void enc_check();

bool enc_available();

int8_t enc_get_delta();



/*_ENCODER_H_*/
#endif
