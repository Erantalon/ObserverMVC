/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

/*
This file contains all functions which will be exported to the dll. Some lib classes are already exported (Model, View and Controller for example)
for client instantiations but the functions below are the only way to access MVC_Manager functions since the manager itself will not be exported.
*/

#pragma once
#ifndef OBSERVER_MVC_H_
#define OBSERVER_MVC_H_
#include "Modules\OBSManager.h"
#include "Utils\OBSPool.h"

// Exported functions for register and retrieve ObserverMVC modules
namespace observer_mvc { namespace modules {
		
	DLL_API void registerModel(int p_id, OBSModel* p_model);						// Register a model
	DLL_API void registerView(int p_id, OBSView* p_view);							// Register a view
	DLL_API void registerController(int p_id, OBSController* p_controller);			// Register a controller
	DLL_API OBSModel* retrieveModel(int p_id);										// Retrieve a model
	DLL_API OBSView* retrieveView(int p_id);										// Retrieve a view
	DLL_API OBSController* retrieveController(int p_id);							// Retrieve a controller
	DLL_API void clearManager();													// Clear all mvc modules from the manager and delete the current singleton instance
}};

// Exported functions for make use of ObserverMVC utilities (pool)
namespace observer_mvc { namespace utils { namespace pool {

	/**
	Retrieve a pointer from the class' pool
	@return A pointer from <T> class
	*/
	template<class T>
	DLL_API T* get()
	{
		// Access (or create, if necessary) the class <T> pool and retrieve an idle pointer from it
		OBSPool<T>* pool = OBSPool<T>::getInstance();
		T* object = pool->retrievePtr();
		return object;
	}

	/**
	Put back a pointer to its class' pool

	@param p_objectPtr - Controller id
	@return Controller associated the param id
	*/
	template<class T>
	DLL_API void put(T* p_objectPtr)
	{
		// Access (or create, if necessary) the class <T> pool and put back the pointer into it
		OBSPool<T>* pool = OBSPool<T>::getInstance();
		pool->putPtr(p_objectPtr);
	}

	DLL_API void clear();		// Clear all created pools
}}};
#endif
