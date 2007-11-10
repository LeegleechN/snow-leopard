/*
**  ClanLib SDK
**  Copyright (c) 1997-2005 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
*/

//! clanDisplay="Display"
//! header=display.h

#ifndef header_display_target
#define header_display_target

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../Core/System/weakptr.h"

class CL_DisplayTargetProvider;
class CL_DisplayTarget_Impl;

//: Display target for clanDisplay.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_DisplayTarget
{
//! Construction:
public:
	//: Constructs a display target.
	CL_DisplayTarget();
	
	CL_DisplayTarget(CL_DisplayTargetProvider *provider);
	
	virtual ~CL_DisplayTarget();

//! Attributes:
public:
	//: Returns the provider for the display target.
	CL_DisplayTargetProvider *get_provider();

	//: Returns true if this display target is invalid.
	bool is_null() const;

//! Operations:
public:

//! Implementation:
private:
	CL_DisplayTarget(const CL_WeakPtr<CL_DisplayTarget_Impl> impl);

	CL_SharedPtr<CL_DisplayTarget_Impl> impl;

	friend class CL_Display;
};

#endif
