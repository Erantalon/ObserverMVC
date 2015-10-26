/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

/*
Due to OBSPool (see OBSPool.h) is a template class, there's a risk to create so many
pools and lose the track of them and its idle pointers. To avoid this, this class
manages all created pools and offers an easy way to clear all pools at once, if
it's necessary.
*/

#pragma once
#ifndef OBS_POOL_MANAGER_H_
#define OBS_POOL_MANAGER_H_

#include <vector>

#include "..\stdafx.h"
#include "IOBSPool.h"

namespace observer_mvc { namespace utils {
	
	class DLL_API OBSPoolManager
	{

	private:
		std::vector<IOBSPool*>	m_poolList;			// Pool list. Every created pool is added at this vector

	private:
		static OBSPoolManager*	sm_instance;		// Singleton instance

	private:
		OBSPoolManager();

	public:
		static OBSPoolManager* getInstance();		// Returns the singleton instance
		void registerPool(IOBSPool* p_pool);		// Register a new pool
		void clearAllPools();						// Clear all registered pools
	};

}};
#endif