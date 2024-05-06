# button
Button component implemented by OOPC. Event-driven, highly scalable; Applicable to RTOS.

## 读取引脚电平值的示例
以stm32平台作为演示
```c
uint32_t Button_readPin(Button * const me)
{
    uint32_t level;
    switch(me->id)
    {
        case 1:
            level = HAL_GPIO_ReadPin(GPIOx, GPIO_PIN_N);
            break;
        case 2:
            level = HAL_GPIO_ReadPin(GPIOy, GPIO_PIN_N);
            break;
    }
    return level;
}
```

以瑞萨mcu平台作为演示
```c
uint32_t Button_readPin(Button *const me)
{
    bsp_io_level_t level;
    switch (me->id)
    {
        case 1:
            g_ioport.p_api->pinRead(&g_ioport_ctrl, BSP_IO_PORT_XX_PIN_YY, &level);
            break;
        case 2:
            g_ioport.p_api->pinRead(&g_ioport_ctrl, BSP_IO_PORT_XX_PIN_ZZ, &level);
            break;
    }
    return level;
}
```


## 应用示例
```c
//button1 事件处理函数
void onButton1Event(uint32_t _event)
{
    switch(_event)
    {
        case BUTTON_EVENT_RELEASE_UP:
            //TODO
            break;
        case BUTTON_EVENT_PRESS_DOWN:
            //TODO
            break;
    }
}

//button2 事件处理函数
void onButton2Event(uint32_t _event)
{
    switch(_event)
    {
        case BUTTON_EVENT_RELEASE_UP:
            //TODO
            break;
        case BUTTON_EVENT_PRESS_DOWN:
            //TODO
            break;		
    }
}

//多个按键实例
int main(void)
{
    /*...初始化代码...*/

    Button button1;
    Button_ctor(&button1, 1, button_tick, 0, RELEASE, 1);
    Button_setOnEventListener(&button1, onButton1Event);
    Button button2;
    Button_ctor(&button2, 2, button_tick, 0, RELEASE, 1);
    Button_setOnEventListener(&button2, onButton2Event);

    while(1)
    {
        //TODO
    }
}


void tick_loop()
{
    //TODO
    Button_tick(&button1, Button_readPin);
    Button_tick(&button2, Button_readPin);
}

```






