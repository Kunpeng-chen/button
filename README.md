# button
Button component implemented by OOPC. Event-driven, highly scalable; Applicable to RTOS.

## 读取引脚电平值的模版
以stm32平台作为演示
```c
uint32_t Button_readPin(Button * const me)
{
	switch(me->id)
	{
		case 1:
			return HAL_GPIO_ReadPin(GPIOx, GPIO_PIN_N); 
		case 2:
			return HAL_GPIO_ReadPin(GPIOy, GPIO_PIN_N); 
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
                        //TODO
			break;
		case DOWN:
                        //TODO
			break;
	}
}

//button2 事件处理函数
void onButton2Event(uint32_t _event)
{
	switch(_event)
	{
		case UP:
                        //TODO
			break;
		case DOWN:
                        //TODO
			break;		
	}
}

//多个按键实例
Button button1;
Button_ctor(&button1, 1, button_tick, 0, RELEASE, 1);
Button_setOnEventListener(&button1, onButton1Event);
Button button2;
Button_ctor(&button2, 2, button_tick, 0, RELEASE, 1);
Button_setOnEventListener(&button2, onButton2Event);

void tick_loop()
{
	...
	Button_tick(&button1, Button_readPin);
	Button_tick(&button2, Button_readPin);
	...
}

```






