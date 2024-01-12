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

int GetUserSignal(void)
{
	static int flag = 0;
	char Choice;    
	while(1)
	{
		if (!flag)
		{
			printf("1.Put 1 rubl\n2.Put 2 rubl\n0.Cancel\n");
			flag = 1;
		}
		Choice = getch();
		switch(Choice)
		{
			case '1':
				flag = 0;
				return 0;
			case '2': 
				flag = 0;
				return 1;
			case '0':
				flag = 0;
				return 2;
		}
	}  
}

int main(int argc, char **argv)
{
	enum states 
	{ 
		READY	= 0,
		PREPFRE = 1, 
		WAIT	= 2, 
		CHANGE	= 3, 
		RETURN	= 4
	} 
	state = READY;
	enum user_signal_states 
	{
		RUBL_1 = 0,
		RUBL_2 = 1,
		CANCEL = 2
	}
	user_signal = CANCEL;
	while (1)
	{
		switch (state) 
		{
			case READY:
				printf("Ready\n");
				user_signal = GetUserSignal();        
				if(user_signal == RUBL_2)
				{
					state = PREPFRE;
				}
				if(user_signal == RUBL_1)
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
				if(user_signal == RUBL_2)
				{
					state = CHANGE;
				}
				if(user_signal == RUBL_1)
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




