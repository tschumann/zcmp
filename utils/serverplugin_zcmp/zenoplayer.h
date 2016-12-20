//===== Copyright © 1996-2008, Valve Corporation, All rights reserved. ======//
//
// Purpose: 
//
// $NoKeywords: $
//
//===========================================================================//
#ifndef ZENOPLAYER_H
#define ZENOPLAYER_H
#ifdef _WIN32
#pragma once
#endif

#include "eiface.h"

class VirtualEmpty {};

namespace zenoclash
{
	class CBasePlayer
	{
	public:
		static void ZenoCombat(CBaseEntity *pThisPtr, BOOL on);
	};
}

#endif	// ZENOPLAYER_H