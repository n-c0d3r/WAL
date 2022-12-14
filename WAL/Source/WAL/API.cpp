#include "API.h"

#ifdef WIN32
#include "Windows/API.h"
#endif



namespace WAL {

	I_API* I_API::Create() {

#ifdef WIN32
		try {

			HN_Log::Info("<WAL> Choose Windows API");

			return new Windows::C_API();
		}
		catch (I_Exception& e) {

			HN_Log::Exception(e);

			HN_Log::Error("<WAL> Initializing Windows API failed");

			return 0;
		}
#endif

		HN_Log::Error("<WAL> No OS API is supported");

		return 0;
	}
	void I_API::Release() {

		I_AbstractObject::Release();

	}

	void I_API::InternalInit() {



	}

}