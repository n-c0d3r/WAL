#pragma once

#include <WAL/.BuildInfo>
#include <WAL/Utils.h>

#include <WAL/AbstractObject.h>
#include <WAL/Singleton.h>



namespace WAL {

	class I_FlagManager :
		public I_AbstractObject
	{

	public:
		virtual void Release();

		virtual void SetupValues() {}

	};

}