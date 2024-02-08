# button
Button component implemented by OOPC. Event-driven, highly scalable; Applicable to RTOS.

## 读取引脚电平值的模版
```c
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
```



## 应用示例
```c
//button1 事件处理函数
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

//button2 事件处理函数
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

//多个按键实例
Button button1;
Button_ctor(&button1, 1, 10, 0, RELEASE, 2);
Button_setOnEventListener(&button1, onButton1Event);
Button button2;
Button_ctor(&button2, 2, 10, 0, RELEASE, 2);
Button_setOnEventListener(&button2, onButton2Event);

void timer_loop()
{
	...
	Button_tick(&button1, Button_readPin);
	Button_tick(&button2, Button_readPin);
	...
}

```






