/*
 * FSM.c
 *
 *	Машина состояний (FSM) и конечные автоматы
 *
 *
 *
 */


#include <stdio.h>
#include <conio.h>


enum states { READY, PREPFRE, WAIT, CHANGE, RETURN };
enum signals { ONE_RUBL, TWO_RUBLS, CANCEL, NONE };

enum signals GetUserSignal(void)
{
    char Choice;
    while(1)
    {
        printf("1.Put 1 rubl\n2.Put 2 rubl\n0.Cancel\n");
        Choice = getch();
        switch(Choice)
        {
        case '1':
            return ONE_RUBL;
        case '2':
            return TWO_RUBLS;
        case '0':
            return CANCEL;
        }
    }
}

int main(int argc, char **argv)
{
    enum states state = READY;
    while (1)
    {
        switch (state)
        {
        case READY:
            printf("Ready\n");
            enum signals user_signal = GetUserSignal();
            if(user_signal == TWO_RUBLS)
            {
                state = PREPFRE;
            }
            if(user_signal == ONE_RUBL)
            {
                state = WAIT;
            }
            break;
        case PREPFRE:
            printf("Preapare cofee\n");
            state = READY;
            break;
        case WAIT:
            printf("Wait\n");
            user_signal = GetUserSignal();
            if(user_signal == TWO_RUBLS)
            {
                state = CHANGE;
            }
            if(user_signal == ONE_RUBL)
            {
                state = PREPFRE;
            }
            if(user_signal == CANCEL)
            {
                state = RETURN;
            }
            break;
        case CHANGE:
            printf("Change 1 Rubl\n");
            state = PREPFRE;
            break;
        case RETURN:
            printf("Change 1 Rubl\n");
            state = READY;
            break;
        }
    }
    return 0;
}




