#ifndef BUTTON_H
#define BUTTON_H

#include "device.h" // Base class interface

enum {
	PRESSED,
	RELEASE,
};

typedef enum {
	NONE,
	UP,
	DOWN,
	SINGAL,
	DOUBLE,
	LONG,
}Button_Event;

// button class properties
typedef struct {
	// The button subclass inherits the device parent class
        Device super; 

        // properties
	uint8_t id;
	uint8_t tick;
	uint8_t totalTicks;
	uint32_t lastPinLevel;
	void (*onButtonEventFunc)(uint32_t);
} Button;

// button class operation and interface
void Button_ctor(Button * const me, uint8_t _id, uint8_t _tick, uint8_t _totalTicks, uint8_t status, uint32_t pinLevel);
void Button_setOnEventListener(Button * const me, void (* _callback)(uint32_t));
void Button_onEventFunc(Button * const me, uint32_t _event);
void Button_tick(Button * const me, uint32_t(* pinLevelReadFunc)(Button * const));

#endif /* BUTTON_H */
