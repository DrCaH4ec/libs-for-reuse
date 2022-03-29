#ifndef _TIMER_1_H_
#define _TIMER_1_H_

#include <avr/io.h>

enum tim0_presc_t {
	TIM0_NO_CLK_SOURCE = 0, //Timer/Counter stopped
	TIM0_PRESC_1,
	TIM0_PRESC_8,
	TIM0_PRESC_64,
	TIM0_PRESC_256,
	TIM0_PRESC_1024,
	TIM0_EXT_T0_FALL,       //External clock source T0 pin. Clock on falling edge
	TIM0_EXT_T0_RISE        //External clock source T0 pin. Clock on rising edge
};

void tim0_set_prescaler(enum tim0_presc_t presc_type);



enum tim0_mode_t {                                          /*TOP*/
	TIM0_NORMAL = 0,        //Normal                        | 0xFF
	TIM0_PWM_PC,            //PWM, phase correct            | 0xFF
	TIM0_CTC,				//CTC 							| OCRA		
	TIM0_FAST_PWM,			//Fast PWM 						| 0xFF
	TIM0_RESERVED_0,		//Reserved(don't use)			| -
	TIM0_PWM_PC_OCRA,		//PWM, phase correct			| OCRA
	TIM0_RESERVED_1,		//Reserved(don't use)			| -
	TIM0_FAST_PWM_OCR,		//Fast PWM						| OCRA
};  

void tim0_waveform_gen_mode(enum tim0_mode_t mode);



//Additional information see in DATASHEET
enum tim0_comp_out_mode_t {
	TIM0_NORM_PORT_OP = 0,  //Normal port operation, OC1x disconnected
	TIM0_TOGGLE_OC0x,
	TIM0_CLEAR_OC0x,
	TIM0_SET_OC0x
};

void tim0_comp_out_mode_set_a(enum tim0_comp_out_mode_t mode);

void tim0_comp_out_mode_set_b(enum tim0_comp_out_mode_t mode);



#define TIM0_OUT_COMP_B     (1<<3)  //Output Compare B Match Interrupt Enable
#define TIM0_OUT_COMP_A     (1<<2)  //Output Compare A Match Interrupt Enable
#define TIM0_OVF            (1<<1)  //Overflow Interrupt Enable

void tim0_int_mask_set(uint8_t mask);

/*_TIMER_1_H_*/
#endif
