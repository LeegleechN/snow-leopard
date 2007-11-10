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
**    (if your name is missing here, please add it)
*/

//! clanDisplay="Image Providers"
//! header=display.h

#ifndef header_jpeg_provider
#define header_jpeg_provider

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_display.h"
#include "../pixel_buffer.h"
#include "../../Core/Text/string_types.h"
#include "../../Core/IOData/virtual_directory.h"

class CL_VirtualDirectory;

//: Image provider that can load JPEG (.jpg) files.
//- !group=Display/Image Providers!
//- !header=display.h!
class CL_API_DISPLAY CL_JPEGProvider
{
//! Construction:
public:
	//: Called to load an image with this provider type.
	//param name: Name of the file to load.
	//param directory: Directory that file name is relative to.
	static CL_PixelBuffer load(
		const CL_String &filename,
		CL_VirtualDirectory directory = CL_VirtualDirectory());

	//: Save the given PixelBuffer into a JPEG
	//param buffer: The CL_PixelBuffer to save, format doesn't matter its converted if needed
	//param filename: File name of JPEG.
	//param directory: Directory that the file name is relative to.
	//param quality: The quality level of the JPEG (0-100), 100 being best quality.
	static void save(
		CL_PixelBuffer buffer,
		const CL_String &filename,
		CL_VirtualDirectory directory = CL_VirtualDirectory(),
		int quality = 85);
};

#endif
