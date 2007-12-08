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

//! clanCore="System"
//! header=core.h

#ifndef header_static_memory_pool
#define header_static_memory_pool

#include "../api_core.h"
#include "memory_pool.h"

//: Static memory pool.
//- !group=Core/System!
//- !header=core.h!
//- !hide!
class CL_API_CORE CL_StaticMemoryPool : public CL_MemoryPool
{
//! Construction:
public:
	CL_StaticMemoryPool(
		void *buffer,
		size_t size,
		CL_MemoryPool *alternative_pool = 0);

	~CL_StaticMemoryPool();

//! Operations:
public:
	void *alloc(size_t size);
	
	void free(void *data);
	
//! Implementation:
private:
	void *pool_buffer;
	
	size_t size;
	
	CL_MemoryPool *alternative_pool;

	size_t next;
};

#endif