/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

#include "stdafx.h"
#include "INotifier.h"

#include "OBSManager.h"

namespace observer_mvc { namespace modules {

	INotifier::INotifier(int p_id) :
		m_id(p_id) {}

	/**
	Dispatch a notification through the Manager for whichever notifier (view or controller) is associated with it

	@param p_notification - Notification object which will be dispatched to one or more mvc modules
	@return
	*/
	void INotifier::sendNotification(INotification* p_notification)
	{
		OBSManager::getInstance()->notify(p_notification);
	}

}};