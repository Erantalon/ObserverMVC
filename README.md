# ObserverMVC
ObserverMVC is a library for helping developers to create applications based on MVC software architectural pattern. It provides a bunch of classes which can be extended to implement the main modules (models, views and controllers) and a set of functions
to register those custom modules. There's no direct dependecy between ObserverMVC modules (unless the developer desires to do so), but they communicate with each other through an underlying message system based on Observer Design Pattern.

## Supporting
Note that currently this library has only been tested on Windows 8.1 and onwards. The project has been developed under Visual Studio 2015 Community. It can be built into Dynamic-link Library or Static Library for both x86 and x64 platforms.

The current solution is only available for Visual Studio 2015 C++.

## Using it

### Building
ObserverMVC is a library to be used in any other C++ projects. After download the solution, open it at your own solution and build it. The .dll/.lib files will be generated at `Build/` folder located at root directory and specified by solution configuration and solution platform.

| Solution Configuration     | Platform | Directory                                                          |
|----------------------------|----------|--------------------------------------------------------------------|
| DLL_Debug                  | x86      | `Build/Win32/DLL_Debug/`                                           |
| DLL_Release                | x86      | `Build/Win32/DLL_Release/`                                         |
| LIB_Debug                  | x86      | `Build/Win32/LIB_Debug/`                                           |
| LIB_Release                | x86      | `Build/Win32/LIB_Release/`                                         |
| DLL_Debug                  | x64      | `Build/x64/DLL_Debug/`                                             |
| DLL_Release                | x64      | `Build/x64/DLL_Release/`                                           |
| LIB_Debug                  | x64      | `Build/x64/LIB_Debug/`                                             |
| LIB_Release                | x64      | `Build/x64/LIB_Release/`                                           |

### Linking and including
After build the ObserverMVC solution, you can copy the .dll/.lib to another folder of your own choice or just use the one created by ObserverMVC solution. Just don't forget to linking it in your own project. And, finally, add `src/` folder as an Include Folder of your project.

## Documentation
Soon.
