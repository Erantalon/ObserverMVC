/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

#pragma once
#ifndef OBS_MANAGER_H_
#define OBS_MANAGER_H_

#include "..\stdafx.h"

#include <map>

#include "OBSModel.h"
#include "OBSView.h"
#include "OBSController.h"

namespace observer_mvc { namespace modules {

	typedef std::map<int, OBSModel*> OBSModelMap;
	typedef std::map<int, OBSView*> OBSViewMap;
	typedef std::map<int, OBSController*> OBSControllerMap;
	typedef std::map<int, std::vector<OBSView*>> OBSViewEventMap;

	class OBSManager
	{

	private:
		OBSModelMap			m_modelMap;				// Model table
		OBSViewMap			m_viewMap;				// View table
		OBSControllerMap	m_controllerMap;		// Controller table

		OBSViewEventMap		m_viewEventMap;			// Table containing all registered view events

	private:
		static OBSManager* sm_instance;		// Singleton instance

	private:
		OBSManager();
		~OBSManager();

	public:
		static OBSManager* getInstance();							// Returns the singleton instance of MVC_Manager class
		static void clear();										// Clear all module maps

		void registerModel(int p_id, OBSModel* p_model);				// Register a new model
		void registerView(int p_id, OBSView* p_view);					// Register a new view
		void registerController(int p_id, OBSController* p_view);		// Register a new controller

		void registerViewEvent(int p_eventId, OBSView* p_view);		// Register a new event associated with a specific view

		OBSModel* retrieveModel(int p_id);								// Retrieve a model by its id
		OBSView* retrieveView(int p_id);								// Retrieve a view by its id
		OBSController* retrieveController(int p_id);					// Retriecve a controller by its id

		void notify(INotification* p_notification);					// Send a notification for whichever module is associated with
	};


}};
#endif