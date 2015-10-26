/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

/*
Basic implementation of a Notification. A notification is a message which can be sent from every notifier in this lib to
other notifiers which are able to receive it.  

Further implementations of this class shall store specific data accordingly to their types to match properly what the notification receivers are
expecting to receive.

For security, users can't instantiante objects of this class.
*/

#pragma once
#ifndef INOTIFICATION_H_
#define INOTIFICATION_H_

#include "..\stdafx.h"

namespace observer_mvc { namespace comm {

	class DLL_API INotification
	{
	
	protected:
		int		m_type;												// Notification type

	protected:
		INotification(int p_type) : m_type(p_type) {}				// Protected constructor to avoid further instantiation 

	public:
		int getType() { return m_type; }							// Return the notification type
	};

}};
#endif