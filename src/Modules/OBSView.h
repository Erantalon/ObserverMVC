/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

/*
A "View" is one of the three main modules of this lib. It's responsible to retrieve data from the models to change whatever is needed to show
in the screen to user. Each view can be registered to receive one or more types of notifications (the view events) and can dispatch notifications
to other mvc modules (views and controllers)
*/

#pragma once
#ifndef OBS_VIEW_H_
#define OBS_VIEW_H_

#include "..\stdafx.h"

#include <vector>

#include "INotifier.h"
#include "..\Comm\INotification.h"

using namespace observer_mvc::comm;

namespace observer_mvc { namespace modules {

	class DLL_API OBSView : public INotifier
	{

	protected:
		std::vector<int> m_eventList;				// List containing all view event ids which this view is registered to

	protected:
		OBSView(int p_id);							// Protected constructor to avoid further instantiation

	public:
		~OBSView();

	public:
		const std::vector<int>& getEventList() { return m_eventList; }			// Return the list with all registered view events
		void registerEvent(int p_eventId);										// Register a new view event id to be able to receive notifications containing the specficied id
		virtual void handleNotification(INotification* p_notification) = 0;		// Receive notification from the mvc manager
	};
}};
#endif