/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

/*
A "Model" is one of the three main modules of this lib. It's responsible to store data and dispatch
notifications to other controllers and views.

The basic Model is a simple implementation of Notifier with no extra data wrapped around it, just for easy reading.
*/

#pragma once
#ifndef OBS_MODEL_H_
#define OBS_MODEL_H_

#include "..\stdafx.h"

#include "INotifier.h"

namespace observer_mvc { namespace modules {

	class DLL_API OBSModel : public INotifier
	{
	protected:
		OBSModel(int p_id) : INotifier(p_id) {}			// Protected constructor to avoid further instantiation
	};

}};
#endif