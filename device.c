#include "device.h"

// Constructor
void Device_ctor(Device * const me, uint8_t _status)
{
	me->status = _status;
}

void Device_delete(Device * const me)
{
	
}
