#include "encoder.h"

static int16_t delta = 0;
static bool flag = false;

void enc_check()
{
    static uint8_t UpState = 0;
    static uint8_t DownState = 0;
    static uint8_t OldState = 0;

    uint8_t NewState = (digital_read(PORT_ENC_A, PIN_ENC_A)>>PIN_ENC_A) |
                        (digital_read(PORT_ENC_B, PIN_ENC_B)>>(PIN_ENC_B-1));

    if(NewState != OldState){

        switch(OldState){
            case 0:
                if(NewState == 2) DownState++;
                if(NewState == 1) UpState++;
            break;

            case 1:
                if(NewState == 0) DownState++;
                if(NewState == 3) UpState++;
            break;

            case 2:
                if(NewState == 3) DownState++;
                if(NewState == 0) UpState++;
            break;

            case 3:
                if(NewState == 1) DownState++;
                if(NewState == 2) UpState++;
            break;
        }


        OldState = NewState;

    if(UpState >= 4){
        delta++;
        UpState = 0;
        flag = true;
    }

    if(DownState >= 4){
        delta--;
        DownState = 0;
        flag = true;
    }


    }
    else{
        flag = false;
    }
}

//-----------------------------------------------------------------------------

bool enc_available()
{
    return flag;
}

//-----------------------------------------------------------------------------

int8_t enc_get_delta()
{
    int16_t tmp = delta;
    
    delta = 0;
    flag = false;

    return tmp;
}
