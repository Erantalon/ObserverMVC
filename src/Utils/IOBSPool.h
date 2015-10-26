/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

/*
Interface for a basic pool.
*/

#pragma once
#ifndef I_OBS_POOL_H_
#define I_OBS_POOL_H_
namespace observer_mvc { namespace utils {

	class IOBSPool
	{
	public:
		virtual void clear() = 0;			// Every pool should clear all its idle pointers when it's needed
	};
}};
#endif