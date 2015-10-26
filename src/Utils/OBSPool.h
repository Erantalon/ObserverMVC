/*
*  Copyright (c) 2015, João Pascoal
*  All rights reserved.
*
*  This source code is licensed under the GNU General Public License found in the
*  LICENSE file in the root directory of this source tree.
*
*/

/*
Utility class for pooling objects. Due to its templated architecture, there's one
singleton instance for each class which makes use of the pool.
*/

#pragma once
#ifndef OBS_POOL_H_
#define OBS_POOL_H_

#include "..\stdafx.h"
#include <vector>
#include "IOBSPool.h"
#include "OBSPoolManager.h"

namespace observer_mvc { namespace utils {

	template<class T>
	class OBSPool : public IOBSPool
	{

	private:
		std::vector<T*>			m_pool;				// Vector containing idle pointers ready to be re-used.

	private:
		static OBSPool<T>*		sm_instance;		// Singleton instance (one for each template class)

	private:

		//When a new ObserverMVC pool is create, it registers itself into the pool manager
		OBSPool()
		{
			this->m_pool = std::vector<T*>();
			OBSPoolManager::getInstance()->registerPool(this);
		}

	public:

		/**
		Get singleton instance of this class (for each templated class)

		@return Singleton instance of templated pool
		*/
		static OBSPool<T>*	getInstance()
		{
			if (sm_instance == NULL)
			{
				sm_instance = new OBSPool<T>();
			}

			return sm_instance;
		}

		/**
		Retrieve an idle pointer of templated class or create a new one
		if the pool is empty;

		@return A pointer of template class
		*/
		T* retrievePtr()
		{
			T* object = NULL;

			// If there's idle pointers in it, just return the first one and remove it from the pool
			if (m_pool.size() > 0)
			{
				object = m_pool[0];
				m_pool.erase(m_pool.begin());
			}
			// Otherwise, if the pool is empty, create a new pointer.
			else
			{
				object = new T();
			}

			return object;
		}
		
		/**
		Put a template class pointer back into its class' pool.

		@param p_objectPtr - Pointter from a template class which won't be used anymore
		@return
		*/
		void putPtr(T* p_objectPtr)
		{
			// Just put it at the head of pool
			m_pool.insert(m_pool.begin(), p_objectPtr);
		}

		/**
		Clear all idle pointers within the pool
		@return
		*/
		void clear()
		{
			// Delete all idle pointers and clear the pool vector
			for (size_t i = 0; i < this->m_pool.size(); i++)
			{
				T* object = m_pool[i];
				delete object;
			}
			this->m_pool.clear();
		}
	};

	template<class T>
	OBSPool<T>*	OBSPool<T>::sm_instance = NULL;
}};
#endif
