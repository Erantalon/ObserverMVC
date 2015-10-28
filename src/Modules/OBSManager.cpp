/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

#include "stdafx.h"
#include "OBSManager.h"

namespace observer_mvc { namespace modules {
	
	// Initialize manager singleton instance
	OBSManager* OBSManager::sm_instance = NULL;

	OBSManager::OBSManager()
	{
		this->m_modelMap		= OBSModelMap();
		this->m_viewMap			= OBSViewMap();
		this->m_controllerMap	= OBSControllerMap();
		this->m_viewEventMap	= OBSViewEventMap();
	}

	OBSManager::~OBSManager()
	{
		// Delete all model pointers and clear the model map itself
		for (OBSModelMap::iterator it = this->m_modelMap.begin(); it != this->m_modelMap.end(); ++it)
		{
			OBSModel* model = (OBSModel*)(it->second);
			delete model;
		}
		this->m_modelMap.clear();

		// Delete all view pointers and clear the view map and the viewEvent map afterwards
		for (OBSViewMap::iterator it = this->m_viewMap.begin(); it != this->m_viewMap.end(); ++it)
		{
			OBSView* view = (OBSView*)(it->second);
			delete view;
		}
		this->m_viewMap.clear();
		this->m_viewEventMap.clear();

		// Delete all controller pointers and clear the controller map itself
		for (OBSControllerMap::iterator it = this->m_controllerMap.begin(); it != this->m_controllerMap.end(); ++it)
		{
			OBSController* controller = (OBSController*)(it->second);
			delete controller;
		}
		this->m_controllerMap.clear();
	}

	/**
	Returns the singleton instance of this class.
	
	@return Singleton instance of OBSManager
	*/
	OBSManager* OBSManager::getInstance()
	{
		// If singleton instance is NULL, just create a new pointer
		if (sm_instance == NULL)
		{
			sm_instance = new OBSManager();
		}

		return sm_instance;
	}

	/**
	Delete current singleton instance. 
	This call will trigger the singleton destructor which will clean all module maps

	@return
	*/
	void OBSManager::clear()
	{
		if (sm_instance != NULL)
		{
			delete sm_instance;
			sm_instance = NULL;
		}
	}

	/**
	Register a new model into manager and bind it with an id

	@param p_id - it's an integer, representing the module id
	@param p_model - model module to be registered into the manager
	@return
	*/
	void OBSManager::registerModel(int p_id, OBSModel* p_model)
	{
		// Register the model into the model map and call "onRegister" function to inform that it was successfully registered
		this->m_modelMap[p_id] = p_model;
		p_model->onRegister();
	}

	/**
	Register a new view into manager and bind it with an id

	@param p_id - it's an integer, representing the module id
	@param p_view - view module to be registered into the manager
	@return
	*/
	void OBSManager::registerView(int p_id, OBSView* p_view)
	{
		// Register the view into the view map and call "onRegister" function to inform that it was successfully registered
		this->m_viewMap[p_id] = p_view;
		p_view->onRegister();
	}

	/**
	Register a new controller into manager and bind it with an id

	@param p_id - it's an integer, representing the module id
	@param p_controller - controller module to be registered into the manager
	@return
	*/
	void OBSManager::registerController(int p_id, OBSController* p_controller)
	{
		// Register the controller into the controller map and call "onRegister" function to inform that it was successfully registered
		this->m_controllerMap[p_id] = p_controller;
		p_controller->onRegister();
	}

	/**
	Removes a model from the manager. It can also delete the pointer

	@param p_id - it's an integer, representing the module id
	@param p_autoDelete - flag indicating if the pointer will be deleted
	@return True, if model was removed from manager. False, otherwise.
	*/
	bool OBSManager::removeModel(int p_id, bool p_autoDelete)
	{
		bool notifierFound = false;
		OBSModel* model = this->m_modelMap[p_id];
		if (model != NULL)
		{
			notifierFound = true;
			if (p_autoDelete)
			{
				delete model;
				model = NULL;
			}
		}

		this->m_modelMap.erase(p_id);

		return notifierFound;
	}

	/**
	Removes a view from the manager. It can also delete the pointer

	@param p_id - it's an integer, representing the view id
	@param p_autoDelete - flag indicating if the pointer will be deleted
	@return True, if view was removed from manager. False, otherwise.
	*/
	bool OBSManager::removeView(int p_id, bool p_autoDelete)
	{
		bool notifierFound = false;
		OBSView* view = this->m_viewMap[p_id];
		if (view != NULL)
		{
			notifierFound = true;
			if (p_autoDelete)
			{
				delete view;
				view = NULL;
			}
		}

		this->m_viewMap.erase(p_id);

		return notifierFound;
	}

	/**
	Removes a controller from the manager. It can also delete the pointer

	@param p_id - it's an integer, representing the controller id
	@param p_autoDelete - flag indicating if the pointer will be deleted
	@return True, if controller was removed from manager. False, otherwise.
	*/
	bool OBSManager::removeController(int p_id, bool p_autoDelete)
	{
		bool notifierFound = false;
		OBSController* controller = this->m_controllerMap[p_id];
		if (controller != NULL)
		{
			notifierFound = true;
			if (p_autoDelete)
			{
				delete controller;
				controller = NULL;
			}
		}

		this->m_controllerMap.erase(p_id);

		return notifierFound;
	}


	/**
	Register a new view event into manager and bind it with an already registered view

	@param p_eventId - it's an integer, representing the event id
	@param p_view - view module which will receive this event further
	@return
	*/
	void OBSManager::registerViewEvent(int p_eventId, OBSView* p_view)
	{
		std::vector<OBSView*> viewEventList = m_viewEventMap[p_eventId];
		viewEventList.push_back(p_view);
		m_viewEventMap[p_eventId] = viewEventList;
	}

	/**
	Retrieve a model from the model map and return it to the user

	@param p_id - it's an integer, representing the model id
	@return A model associated with the id parameter. If there's no model associated with it, it will return NULL
	*/
	OBSModel* OBSManager::retrieveModel(int p_id)
	{
		OBSModel* model = this->m_modelMap[p_id];
		return model;
	}

	/**
	Retrieve a view from the view map and return it to the user

	@param p_id - it's an integer, representing the view id
	@return A view associated with the id parameter. If there's no view associated with it, it will return NULL
	*/
	OBSView* OBSManager::retrieveView(int p_id)
	{
		OBSView* view = this->m_viewMap[p_id];
		return view;
	}

	/**
	Retrieve a controller from the controller map and return it to the user

	@param p_id - it's an integer, representing the controller id
	@return A controller associated with the id parameter. If there's no controller associated with it, it will return NULL
	*/
	OBSController* OBSManager::retrieveController(int p_id)
	{
		OBSController* controller = this->m_controllerMap[p_id];
		return controller;
	}

	/**
	Dispatch a notification for whichever module (view or controller) is associated with it

	@param p_notification - Notification object which will be dispatched to one or more mvc modules
	@return
	*/
	void OBSManager::notify(INotification* p_notification)
	{
		// Get the notification id
		int id = p_notification->getType();

		// Check if there are views related with this type of notifications
		if (this->m_viewEventMap.find(id) != this->m_viewEventMap.end())
		{
			std::vector<OBSView*> viewList = this->m_viewEventMap[id];
			for (std::vector<OBSView*>::iterator it = viewList.begin(); it != viewList.end(); ++it)
			{
				// Calls "handleNotification" for every view binded to this notification id
				(*it)->handleNotification(p_notification);
			}
		}

		// Check if there's a controller registered with this id
		if (this->m_controllerMap.find(id) != this->m_controllerMap.end())
		{
			OBSController* controller = this->m_controllerMap[id];
			if (controller != NULL)
			{
				// Fire the "update" function to make the controller process this notification
				controller->update(p_notification);
			}
		}
	}
}};