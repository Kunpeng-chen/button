#include "button.h"

void Button_ctor(Button * const me, 
	             uint8_t _id,
		     uint8_t _tick, 
		     uint8_t _totalTicks, 
		     uint8_t _status, 
		     uint32_t _pinLevel)
{
	/* first call superclass’ ctor */
	Device_ctor(&me->super, _status);
	
	me->id = _id;
	me->tick = _tick;
	me->totalTicks = _totalTicks;
        me->lastPinLevel = _pinLevel;
	me->onButtonEventFunc = NULL;
}

void Button_setOnEventListener(Button * const me, void (* _callback)(uint32_t))
{
	me->onButtonEventFunc = _callback;
}

void Button_onEventFunc(Button * const me, uint32_t _event)
{
	me->onButtonEventFunc(_event);
}

void Button_tick(Button * const me, uint32_t (* pinLevelReadFunc)(Button * const))
{
	me->totalTicks += me->tick;
	
	uint32_t pinLevel = pinLevelReadFunc(me);
	if (pinLevel != me->lastPinLevel)
	{
		if (pinLevel)
		{
			me->super.status = RELEASE;
			Button_onEventFunc(me, UP);
		}
		else
		{
			me->super.status = PRESSED;
			Button_onEventFunc(me, DOWN);
		}

		me->lastPinLevel = pinLevel;
	}
}
