#include "API.h"

#ifdef WIN32
#include "Windows/API.h"
#endif



namespace WAL {

	I_API* I_API::Create() {

#ifdef WIN32
		try {

			UL::HN_Log::Info("<WAL> Choose Windows API");

			return new Windows::C_API();
		}
		catch (UL::I_Exception& e) {

			UL::HN_Log::Exception(e);

			UL::HN_Log::Error("<WAL> Initializing Windows API failed");

			return 0;
		}
#endif

		UL::HN_Log::Error("<WAL> No OS API is supported");

		return 0;
	}
	void I_API::Release() {



	}

	void I_API::InternalInit() {



	}

}