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

//! clanDisplay="Display"
//! header=display.h

#ifndef header_program_attribute
#define header_program_attribute

#ifdef CL_API_DLL
#ifdef CL_GL_EXPORT
#define CL_API_GL __declspec(dllexport)
#else
#define CL_API_GL __declspec(dllimport)
#endif
#else
#define CL_API_GL
#endif

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Core/System/sharedptr.h"
#include "../Core/Text/string_types.h"

#include "api_display.h"

class CL_ProgramAttribute_Impl;

//: OpenGL program object vertex attribute information class.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_ProgramAttribute
{
//! Construction:
public:
	//: Constructs a program attribute.
	//param name: Name of attribute.
	//param size: Attribute size.
	//param type: OpenGL attribute type.
	CL_ProgramAttribute();
	
	CL_ProgramAttribute(const CL_StringRef &name, int size, int type);
	
	~CL_ProgramAttribute();

//! Attributes:
public:
	//: Get attribute name.
	const CL_StringRef &get_name() const;

	//: Get attribute size.
	int get_size() const;

	//: Get attribute OpenGL type.
	int get_type() const;

//! Operations:
public:

//! Implementation:
private:
	CL_SharedPtr<CL_ProgramAttribute_Impl> impl;
};

#endif
