#pragma once

#include <WAL/.BuildInfo>
#include <WAL/Utils.h>

#include <WAL/AbstractObject.h>
#include <WAL/Singleton.h>



namespace WAL {



	class I_API :
		public I_AbstractObject,
		public TC_Singleton<I_API>
	{

	protected:
		std::string m_Name;



	protected:
		I_API(
			const std::string& name
		) : 
			TC_Singleton(),

			m_Name(name)
		{



		}



	public:
		static I_API* Create();
		virtual void Release() override;

		virtual bool CheckMessage() { return false; }

	protected:
		void InternalInit();

	public:
		std::string GetName() { return m_Name; }

	};

}