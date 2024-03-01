#ifndef BUTTON_H
#define BUTTON_H

#include "device.h" // Base class interface

//Generate 1 tick per 1ms
#define button_tick  10  

enum {
	PRESSED,
	RELEASE,
};

typedef enum {
	BUTTON_EVENT_RELEASE_UP,
	BUTTON_EVENT_PRESS_DOWN,
	BUTTON_EVENT_LONG_PRESS,
	BUTTON_EVENT_DOUBLE_CLICK
}Button_Event;

// button class properties
typedef struct {
	// The button subclass inherits the device parent class
        Device super; 

        // properties
	uint8_t id;
	uint8_t tick;
	uint8_t totalTicks; //totalTicks is used to extend long press and short press
	uint32_t lastPinLevel;
	void (*onButtonEventFunc)(uint32_t);
} Button;

// button class operation and interface
void Button_ctor(Button * const me, uint8_t _id, uint8_t _tick, uint8_t _totalTicks, uint8_t status, uint32_t pinLevel);
void Button_setOnEventListener(Button * const me, void (* _callback)(uint32_t));
void Button_onEventFunc(Button * const me, uint32_t _event);
void Button_tick(Button * const me, uint32_t(* pinLevelReadFunc)(Button * const));

#endif /* BUTTON_H */
