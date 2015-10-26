========================================================================
ObserverMVC Project Overview
========================================================================

ObserverMVC is a library for helping developers to create applications based on MVC 
software architectural pattern. It provides a bunch of classes which can be extended 
to implement the main modules (models, views and controllers) and a set of functions
to register those custom modules. There's no direct dependecy between ObserverMVC modules
(unless the developer desires to do so), but they communicate with each other through
an underlying message system based on Observer Design Pattern.

ObserverMVC is free software; you can redistribute it and/or modify	
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or (at
your option) any later version. See the file COPYING included with
this distribution for more information.

This file contains a summary of what you will find in each of the files that
make up your ObserverMVC application.

ObserverMVC.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

ObserverMVC.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

ObserverMVC.cpp
    This is the main DLL source file.

	When created, this DLL does not export any symbols. As a result, it
	will not produce a .lib file when it is built. If you wish this project
	to be a project dependency of some other project, you will either need to
	add code to export some symbols from the DLL so that an export library
	will be produced, or you can set the Ignore Input Library property to Yes
	on the General propert page of the Linker folder in the project's Property
	Pages dialog box.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named ObserverMVC.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
