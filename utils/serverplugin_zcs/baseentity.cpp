//===== Copyright © 1996-2008, Valve Corporation, All rights reserved. ======//
//
// Purpose: 
//
// $NoKeywords: $
//
//===========================================================================//

#include "baseentity.h"

namespace Zeno
{

	bool CBaseEntity::AcceptInput(CBaseEntity *pObject, const char *szInputName, CBaseEntity *pActivator, CBaseEntity *pCaller, variant_t Value, int outputID)
	{
		// get this
		void **pThis = *(void ***)&pObject;
		// get the vtable as an array of void *
		void **vtable = *(void ***)pThis;
		// the method we want is 32nd in the vtable
		void *pMethod = vtable[32]; 

		// use a union to get the address as a function pointer
		union
		{
			bool (VirtualEmpty::*mfpnew)(const char *, CBaseEntity *, CBaseEntity *, variant_t, int);
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
	 
		return (bool) (reinterpret_cast<VirtualEmpty*>(pThis)->*u.mfpnew)(szInputName, pActivator, pCaller, Value, outputID);
	}
}