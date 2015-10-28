/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

// ObserverMVC.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ObserverMVC.h"

#include "Modules\OBSManager.h"
#include "Utils\OBSPoolManager.h"

namespace observer_mvc { namespace modules {
	/**
	Register a model into the manager

	@param p_id - Model id
	@param p_model - Model which will be associated with the param id
	@return
	*/
	DLL_API void registerModel(int p_id, OBSModel* p_model)
	{
		OBSManager::getInstance()->registerModel(p_id, p_model);
	}

	/**
	Register a view into the manager

	@param p_id - View id
	@param p_view - View which will be associated with the param id
	@return
	*/
	DLL_API void registerView(int p_id, OBSView* p_view)
	{
		OBSManager::getInstance()->registerView(p_id, p_view);
	}

	/**
	Register a controller into the manager

	@param p_id - Controller id
	@param p_controller - Controller which will be associated with the param id
	@return
	*/
	DLL_API void registerController(int p_id, OBSController* p_controller)
	{
		OBSManager::getInstance()->registerController(p_id, p_controller);
	}

	/**
	Retrieve a model from the manager

	@param p_id - Model id
	@return Model associated the param id
	*/
	DLL_API OBSModel* retrieveModel(int p_id)
	{
		return OBSManager::getInstance()->retrieveModel(p_id);
	}

	/**
	Retrieve a view from the manager

	@param p_id - View id
	@return View associated the param id
	*/
	DLL_API OBSView* retrieveView(int p_id)
	{
		return OBSManager::getInstance()->retrieveView(p_id);
	}

	/**
	Retrieve a controller from the manager

	@param p_id - Controller id
	@return Controller associated the param id
	*/
	DLL_API OBSController* retrieveController(int p_id)
	{
		return OBSManager::getInstance()->retrieveController(p_id);
	}

	/**
	Removes a model from the manager. It can also delete the pointer

	@param p_id - it's an integer, representing the module id
	@param p_autoDelete - flag indicating if the pointer will be deleted
	@return True, if model was removed from manager. False, otherwise.
	*/
	DLL_API bool removeModel(int p_id, bool p_autoDelete)
	{
		return OBSManager::getInstance()->removeModel(p_id, p_autoDelete);
	}

	/**
	Removes a view from the manager. It can also delete the pointer

	@param p_id - it's an integer, representing the module id
	@param p_autoDelete - flag indicating if the pointer will be deleted
	@return True, if view was removed from manager. False, otherwise.
	*/
	DLL_API bool removeView(int p_id, bool p_autoDelete)
	{
		return OBSManager::getInstance()->removeView(p_id, p_autoDelete);
	}

	/**
	Removes a controller from the manager. It can also delete the pointer

	@param p_id - it's an integer, representing the module id
	@param p_autoDelete - flag indicating if the pointer will be deleted
	@return True, if controller was removed from manager. False, otherwise.
	*/
	DLL_API bool removeController(int p_id, bool p_autoDelete)
	{
		return OBSManager::getInstance()->removeController(p_id, p_autoDelete);
	}

	/**
	Clear all mvc modules from the manager and delete the current singleton instance
	@return
	*/
	DLL_API void clearManager()
	{
		OBSManager::clear();
	}
}};

namespace observer_mvc { namespace utils { namespace pool {
	
	/**
	Clear all OBSPool instances, and their pooled pointers, from the pool manager
	@return
	*/
	DLL_API void clear()
	{
		OBSPoolManager::getInstance()->clearAllPools();
	}
}}};
