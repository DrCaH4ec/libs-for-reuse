#ifndef _DIGITAL_IO_AVR_H_
#define _DIGITAL_IO_AVR_H_

//-----------------------------------------------------------------------------
#define INPUT       0
#define OUTPUT      1

//here you need to use DDRx
#define pin_mode(ddr, pin, state) *ddr = state ? *ddr|(1<<pin) : *ddr&(~(1<<pin))
//-----------------------------------------------------------------------------
#define HIGH    1
#define LOW     0
#define PULL_UP 1   //for input mode only

//here you need to use PORTx
#define digital_write(port, pin, val) port = val ? port|(1<<pin) : port&(~(1<<pin))
//-----------------------------------------------------------------------------

//here you need to use PINx
#define digital_read(port, pin) ( port & ( 1 << pin ) )
//-----------------------------------------------------------------------------

/*_DIGITAL_IO_AVR_H_*/
#endif
