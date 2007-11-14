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

#ifndef header_service
#define header_service

#include "../api_core.h"
#include "../System/sharedptr.h"
#include "../Signals/signal_v1.h"

class CL_Event;
class CL_Service_Impl;

//: Service/daemon class.
//- !group=Core/System!
//- !header=core.h!
class CL_API_CORE CL_Service
{
//! Construction:
public:
	//: Constructs a service object.
	CL_Service(const CL_String &service_name);
	
	~CL_Service();

//! Attributes:
public:
	//: Returns the event object flagged when system requests the service to stop.
	CL_Event &get_stop_event();
	
	//: Returns the event object flagged when system requests the service to reload.
	CL_Event &get_reload_event();

	//: Returns the service name.
	const CL_String &get_service_name() const;

	//: Signal invoked when service is started.
	CL_Signal_v1<std::vector<CL_String> &> &sig_service_run();

//! Operations:
public:
	//: Process command line and run service.
	int main(int argc, char **argv);

//! Implementation:
private:
	CL_SharedPtr<CL_Service_Impl> impl;
};

#endif