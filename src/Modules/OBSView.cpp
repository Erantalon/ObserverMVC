/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

#include "stdafx.h"
#include "OBSView.h"

#include "OBSManager.h"

namespace observer_mvc { namespace modules {

	OBSView::OBSView(int p_id) : INotifier(p_id)
	{
		// Instantiate the view event list
		this->m_eventList = std::vector<int>();
	}

	OBSView::~OBSView()
	{
		this->m_eventList.clear();
	}

	/**
	Register itself in the MVC Manager to be able to receive notifications with the specific id

	@param p_eventId - View event id which will make this view be able to receive notifications with this type from the manager
	@return
	*/
	void OBSView::registerEvent(int p_eventId)
	{
		// Store the id within the view event list
		this->m_eventList.push_back(p_eventId);

		// Bind the view with view event id in the mvc manager
		OBSManager::getInstance()->registerViewEvent(p_eventId, this);
	}

}};