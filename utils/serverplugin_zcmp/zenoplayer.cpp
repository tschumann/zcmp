//===== Copyright © 1996-2008, Valve Corporation, All rights reserved. ======//
//
// Purpose: 
//
// $NoKeywords: $
//
//===========================================================================//

#include "zenoplayer.h"

void CZenoPlayer::ZenoCombat(CBaseEntity *pObject, BOOL on)
{
	// get this
	void **pThis = *(void ***)&pObject;
	// get the vtable as an array of void *
	void **vtable = *(void ***)pThis;
	// the method we want is 416th in the vtable
	void *pMethod = vtable[416]; 

	// use a union to get the address as a function pointer
	union
	{
		void (VirtualEmpty::*mfpnew)(BOOL);
	#ifndef __linux__
		void *addr;
	} u; 
	
	u.addr = pMethod;
	#else // GCC's member function pointers all contain this pointer adjustor - you'd probably set it to 0 
		struct
		{
			void *addr;
			intptr_t adjustor;
		} s;
	} u;
	
	u.s.addr = pMethod;
	u.s.adjustor = 0;
	#endif
 
	(void) (reinterpret_cast<VirtualEmpty*>(pThis)->*u.mfpnew)(on);
}