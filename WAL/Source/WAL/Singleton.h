#pragma once

#include <WAL/.BuildInfo>



namespace WAL {

	template<class T>
	class TC_Singleton {

	protected:
		static T* m_Instance;



	public:
		TC_Singleton() {

			m_Instance = (T*)this;

		}

		static T* GetInstance() {
			return m_Instance;
		}

	};

	template<class T>
	T* TC_Singleton<T>::m_Instance = 0;

}