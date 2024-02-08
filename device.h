#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct DeviceVtbl;
// Device class 
typedef struct {
	struct DeviceVtbl const *vptr;
	
	//properties
	uint8_t status;	
} Device;

// Device class virtual table
struct DeviceVtbl {
    void (*onEventFunc)(Device const * const me);
};

// Device class operation and interface
void Device_ctor(Device * const me, uint8_t _status); 
void Device_delete(Device * const me);

static inline void Device_onEventFunc(Device const * const me) 
{
    (*me->vptr->onEventFunc)(me);
}

#endif /* DEVICE_H */
