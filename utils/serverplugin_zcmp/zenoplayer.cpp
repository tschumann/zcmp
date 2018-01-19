//===== Copyright © 1996-2008, Valve Corporation, All rights reserved. ======//
//
// Purpose: 
//
// $NoKeywords: $
//
//===========================================================================//

#include "zenoplayer.h"

namespace zenoclash
{

	void CBasePlayer::ZenoCombat( CBaseEntity *pObject, BOOL bOn )
	{
		// get the this pointer
		void **pThis = *(void ***)&pObject;
		// get the vtable as an array of void *
		void **vtable = *(void ***)pThis;
		// the method we want is 416th in the vtable
		void *pMethod = vtable[416]; 

		// use a union to get the address as a function pointer
		union
		{
			void (VirtualEmpty::*mfpnew)(BOOL);
			void *addr;
		} u; 
		
		u.addr = pMethod;
	 
		(void)(reinterpret_cast<VirtualEmpty*>(pThis)->*u.mfpnew)(bOn);
	}
}