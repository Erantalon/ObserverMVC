/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

/*
A "Controller" is one of the three main modules of this lib. It's responsible to change directly mvc models data and dispatch
notifications to other controllers and views.
*/

#pragma once
#ifndef OBS_CONTROLLER_H_
#define OBS_CONTROLLER_H_

#include "..\stdafx.h"

#include "INotifier.h"

namespace observer_mvc { namespace modules {

	class DLL_API OBSController : public INotifier
	{
	protected:
		OBSController(int p_id) : INotifier(p_id) {}				// Protected constructor to avoid further instantiation

	public:
		virtual void update(INotification* p_notification) = 0;		// Each controller implementation shall implement this function. It receives notifications from other modules and process them to act properly upon other mvc modules
	};

}};
#endif