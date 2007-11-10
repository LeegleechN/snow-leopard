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

//! clanCore="I/O Data"
//! header=core.h

#ifndef header_virtual_file_system
#define header_virtual_file_system

#include "../api_core.h"
#include "../System/sharedptr.h"
#include "file.h"
class CL_IODevice;
class CL_VirtualDirectory;
class CL_VirtualFileSystem_Impl;
class CL_VirtualFileSource;
class CL_VirtualDirectoryListing;

//: Virtual File System (VFS).
//- !group=Core/IO Data!
//- !header=core.h!
class CL_API_CORE CL_VirtualFileSystem
{
//! Construction:
public:
	//: Constructs a file system.
	CL_VirtualFileSystem();

	CL_VirtualFileSystem(CL_VirtualFileSource *provider);

	CL_VirtualFileSystem(const CL_String &path, bool is_zip_file = false);

	~CL_VirtualFileSystem();

//! Attributes:
public:
	//: Returns true if the file system is null.
	bool is_null() const { return impl.is_null(); }

	//: Returns the root directory for the file system.
	CL_VirtualDirectory get_root_directory();

	//: Returns true if a path is a mount point.
	bool is_mount(const CL_String &mount_point);

	//: Return directory listing for path.
	CL_VirtualDirectoryListing get_directory_listing(const CL_String &path_rel);

	//: Returns the file source for this file system.
	CL_VirtualFileSource *get_provider();

//! Operations:
public:
	//: Opens a virtual directory.
	CL_VirtualDirectory open_directory(const CL_String &path);

	//: Opens a file.
	//param: mode = CL_File::OpenMode modes
	//param: access = CL_File::AccessFlags flags
	//param: share = CL_File::ShareFlags flags
	//param: flags = CL_File::Flags flags
	//return: The CL_IODevice
	CL_IODevice open_file(const CL_String &filename,
		CL_File::OpenMode mode = CL_File::open_existing,
		unsigned int access = CL_File::access_read | CL_File::access_write,
		unsigned int share = CL_File::share_all,
		unsigned int flags = 0);

	//: Mounts a file system at mount point.
	//- This is only available if CL_VirtualFileSystem was set
	//- Filenames starting with "mount_point" at the start will be replaced by the filesystem specified by "fs"
	//- (ie the the base_path is ignored)
	//- For example:
	//-  CL_VirtualFileSystem new_vfs(new MyFileSource(cl_text("Hello")));
	//-  vfs.mount(cl_text("ABC"), new_vfs);
	//param: mount_point = Mount alias name to use
	//param: fs = Filesystem to use
	void mount(const CL_String &mount_point, CL_VirtualFileSystem fs);

	//: Mounts a file system at mount point.
	//- Filenames starting with "mount_point" at the start will be replaced by the path specified by "path" 
	//- (ie the the base_path is ignored)
	//param: mount_point = Mount alias name to use
	//param: path = Path which "mount_point" should point to
	//param: is_zip_file = false, create as a CL_VirtualFileSource_File, else create as a CL_VirtualFileSource_Zip
	void mount(const CL_String &mount_point, const CL_String &path, bool is_zip_file);

	//: Unmount a file system.
	//param: mount_point = The mount point to unmount
	void unmount(const CL_String &mount_point);

//! Implementation:
private:
	//- !hide!
	class CL_NullVFS { };
	explicit CL_VirtualFileSystem(class CL_NullVFS null_fs);

	CL_SharedPtr<CL_VirtualFileSystem_Impl> impl;

	friend class CL_VirtualDirectory;
	
	friend class CL_VirtualDirectory_Impl;
};

#endif
