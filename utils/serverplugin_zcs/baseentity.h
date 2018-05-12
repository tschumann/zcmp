//===== Copyright © 1996-2008, Valve Corporation, All rights reserved. ======//
//
// Purpose: 
//
// $NoKeywords: $
//
//===========================================================================//
#ifndef BASEENTITY_H
#define BASEENTITY_H
#ifdef _WIN32
#pragma once
#endif

#include "eiface.h"

class VirtualEmpty {};

// TODO: variant_t is in the Source SDK in variant_t.h - presumably ACE Team didn't modify it
#define variant_t void*

namespace Zeno
{
	class CBaseEntity
	{
	public:
		static bool AcceptInput(CBaseEntity *pObject, const char *szInputName, CBaseEntity *pActivator, CBaseEntity *pCaller, variant_t Value, int outputID);
	};
}

#endif	// BASEENTITY_H