#ifndef _BTOPS_H_
#define _BTOPS_H_

#define SET_BIT(reg, bit) reg |= ( 1 << bit )
#define CLEAR_BIT(reg, bit) reg &= ~( 1 << bit )
#define TOGLE_BIT(reg, bit) reg ^= ( 1 << bit )

#define READ_BIT(reg, bit) ( reg & ( 1 << bit ) )

/*_BTOPS_H_*/
#endif