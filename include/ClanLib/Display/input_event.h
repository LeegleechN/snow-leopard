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
**    Harry Storbacka
*/

//! clanDisplay="Input"
//! header=display.h

#ifndef header_input_event
#define header_input_event

#include "api_display.h"
#include "input_device.h"
#include "../Core/Math/point.h"

class CL_InputEvent_Impl;

//: Input event class.
//- !group=Display/Input!
//- !header=display.h!
class CL_API_DISPLAY CL_InputEvent
{
public:
	//: Event types.
	enum Type
	{
		no_key            = 0,
		pressed           = 1,
		released          = 2,
		pointer_moved     = 4,
		axis_moved        = 5,
		ball_moved        = 6
	};

	//: Tablet axis id's.
	enum TabletAxisID
	{
		x_axis            = 0,
		y_axis            = 1,
		z_axis            = 2,
		tilt_x            = 3,
		tilt_y            = 4,
		rotation_pitch    = 6,
		rotation_roll     = 7,
		rotation_yaw      = 8
	};

//! Construction:
public:
	//: Constructs a 'NoKey' key.
	CL_InputEvent();

	~CL_InputEvent();

//! Attributes:
public:

//! Operations:
public:
	//: Key or axis identifier.
	int id;

	//: Character sequence generated by event.
	//- <p>A key press can generate one, none or multiple characters,
	//- the reason for this are deadkeys, ie. press ^ + a and get �, so
	//- the first press would generate no key and the second one, in
	//- case that the second key being pressed doesn't support the ^ it
	//- would generate two characters (ie. ^ + 5 => "", "^5")</p>
	CL_String str;

	//: Event type.
	Type type;

	//: Device that event originates from.
	CL_InputDevice device;
	
	//: Mouse position at event time.
	CL_Point mouse_pos;

	//: Axis position.
	double axis_pos;

	//: The repeat count for this event.
	//- <p>The variable contains the number of times the keystroke is
	//- autorepeated as a result of the user holding down the key.</p>
	int repeat_count;

	//: State of modifier keys.
	bool alt;
	bool shift;
	bool ctrl;

//! Implementation:
private:
	CL_SharedPtr<CL_InputEvent_Impl> impl;
};

#endif
