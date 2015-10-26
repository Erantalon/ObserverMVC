/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

/*
A "Notifier" is the representation of every MVC module (model, view and controller).
*/

#pragma once
#ifndef I_NOTIFIER_H_
#define I_NOTIFIER_H_

#include "..\stdafx.h"

#include "..\Comm\INotification.h"

using namespace observer_mvc::comm;

namespace observer_mvc { namespace modules {

	class DLL_API INotifier
	{

	protected:
		int m_id;												// Every notifier has an id for further identification in Manager (OBSManager.h)

	protected:
		INotifier(int p_id);

	public:

		virtual void onRegister() = 0;							// It should be implemented for each specific notifier. It's triggered when the notifier is registered in the Manager
		virtual void onLeave() = 0;								// It should be implemented for each specific notifier. It's triggered when the notifier is unregistered from the Manager

		int getId() { return m_id; }							// Returns the notifier id
		void sendNotification(INotification* p_notification);	// Sends a notification to another notifiers which are able to receive it
	};
}};
#endif