/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

#include "stdafx.h"
#include "OBSPoolManager.h"

namespace observer_mvc { namespace utils {

	OBSPoolManager* OBSPoolManager::sm_instance = NULL;

	OBSPoolManager::OBSPoolManager()
	{
		this->m_poolList = std::vector<IOBSPool*>();
	}

	/**
	Get singleton instance of this class

	@return Singleton instance of pool manager
	*/
	OBSPoolManager* OBSPoolManager::getInstance()
	{
		if (sm_instance == NULL)
		{
			sm_instance = new OBSPoolManager();
		}

		return sm_instance;
	}

	/**
	Register a new pool into the manager

	@param p_pool - An ObserverMVC pool
	@return
	*/
	void OBSPoolManager::registerPool(IOBSPool* p_pool)
	{
		this->m_poolList.push_back(p_pool);
	}

	/**
	Iterates through all registered pool and delete their idle pointers.
	@return
	*/
	void OBSPoolManager::clearAllPools()
	{
		for (int i = 0; i < this->m_poolList.size(); i++)
		{
			IOBSPool* pool = this->m_poolList[i];
			pool->clear();
			delete pool;
		}
		this->m_poolList.clear();
	}
}};