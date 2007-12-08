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

//! clanCore="I/O Data"
//! header=core.h

#ifndef header_security_identifier
#define header_security_identifier

#include "../api_core.h"
#include "../System/databuffer.h"

//: Security identifier.
//- !group=Core/IO Data!
//- !header=core.h!
class CL_API_CORE CL_SecurityIdentifier
{
//! Construction:
public:
	//: Security identifier types.
	enum Type
	{
		type_user,
		type_group,
		type_domain,
		type_alias,
		type_well_known_group,
		type_deleted_account,
		type_invalid,
		type_unknown,
		type_computer
	};

	CL_SecurityIdentifier(const CL_String &name);
	
	CL_SecurityIdentifier(const CL_String &name, Type type);
	
#ifdef WIN32
	CL_SecurityIdentifier(const PSID sid);
#else
	CL_SecurityIdentifier(unsigned int sid, Type type);
#endif
	
	CL_SecurityIdentifier(const CL_SecurityIdentifier &copy);
	
	~CL_SecurityIdentifier();
	
	static CL_SecurityIdentifier get_thread_user();
	
	static CL_SecurityIdentifier get_thread_group();

//! Attributes:
public:
	//: Get friendly name of security identifier.
	CL_String get_name() const;
	
	//: Get domain name identifier belongs to.
	CL_String get_domain_name() const;

	//: Get security identifier type.
	Type get_type() const;
	
//! Operations:
public:
	CL_SecurityIdentifier &operator =(const CL_SecurityIdentifier &copy);

//! Implementation:
private:
#ifdef WIN32
	CL_DataBuffer sid;
#else
	unsigned int sid;
#endif
	
	Type type;
};

#endif