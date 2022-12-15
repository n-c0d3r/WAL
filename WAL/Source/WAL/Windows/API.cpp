#include "API.h"



namespace WAL {

	namespace Windows {

		C_API::C_API() :
			I_API("Windows")
		{

			HN_Log::Info("<WAL> Start initializing Windows API");

			InternalInit();

			HN_Log::Info("<WAL> Windows API initialized");

		}

		void C_API::Release() {

			HN_Log::Info("<WAL> Start Releasing Windows API");

			I_API::Release();

			HN_Log::Info("<WAL> Windows API Released");

		}

		bool C_API::CheckMessage() {

			bool result = false;

			MSG msg = { 0 };

			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);

				result = true;

			}

			return result;
		}

	}

}