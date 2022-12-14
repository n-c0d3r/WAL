#pragma once

#include <WAL/.BuildInfo>
#include <WAL/Utils.h>



namespace WAL {



	class C_Event :
		public UL::I_AbstractObject
	{

	private:
		std::list<std::function<void(C_Event*)>> m_ListenerList;



	public:
		C_Event();



	public:
		void Invoke();

		std::list<std::function<void(C_Event*)>>::iterator AddListener(std::function<void(C_Event*)> listener);
		void RemoveListener(std::list<std::function<void(C_Event*)>>::iterator i);

	};

}