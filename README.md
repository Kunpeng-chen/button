# button
Button component implemented by OOPC. Event-driven, highly scalable; Applicable to RTOS.

//模版
uint32_t Button_readPin(Button * const me)
{
	switch(me->id)
	{
		case 1:
			return 0; 
		case 2:
			return 0;
	}
}

/*
应用示例
Button button1;
Button_ctor(&button1, 1, 10, 0, RELEASE, 2);
Button_setOnEventListener(&button1, onButton1Event);
Button_tick(&button1, Button_readPin);
*/
void onButton1Event(uint32_t _event)
{
	switch(_event)
	{
		case UP:
			break;
		case DOWN:
			break;
	}
}

/*
应用示例
Button button2;
Button_ctor(&button2, 2, 10, 0, RELEASE, 2);
Button_setOnEventListener(&button2, onButton2Event);
Button_tick(&button2, Button_readPin);
*/
void onButton2Event(uint32_t _event)
{
	switch(_event)
	{
		case UP:
			break;
		case DOWN:
			break;		
	}
}
