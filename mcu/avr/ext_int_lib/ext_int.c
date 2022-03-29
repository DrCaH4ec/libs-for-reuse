#include "inc/ext_int.h"

static void (*handler_0) (void);
static void (*handler_1) (void);

ISR(INT0_vect) {
    handler_0();
}

ISR(INT1_vect) {
    handler_1();
}


void ext_int0_sense_control(enum sense_control_t sense)
{
    EICRA &= 0xfc;
    EICRA |= sense;
}

//-----------------------------------------------------------------------------

void ext_int1_sense_control(enum sense_control_t sense)
{
    EICRA &= 0xf3;
    EICRA |= (sense<<2);
}

//-----------------------------------------------------------------------------

void ext_int0_status(enum ext_int_stat_t status)
{
    EIMSK &= ~(1<<INT0);
    EIMSK |= (status<<INT0);
}

//-----------------------------------------------------------------------------

void ext_int1_status(enum ext_int_stat_t status)
{
    EIMSK &= ~(1<<INT1);
    EIMSK |= (status<<INT1);
}

//-----------------------------------------------------------------------------

void ext_int0_attach_handler(void (*foo)(void))
{
    handler_0 = foo;
}

//-----------------------------------------------------------------------------

void ext_int1_attach_handler(void (*foo)(void))
{
    handler_1 = foo;
}
