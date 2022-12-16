#pragma once

#include <WAL/.BuildInfo>
#include <WAL/Utils.h>

#include <WAL/Window.h>



namespace WAL {

	namespace Windows {

		struct S_WindowProcParam {

			UINT msg;
			WPARAM wparam;
			LPARAM lparam;

		};

		namespace HN {

			extern std::unordered_map<WindowHandle, I_Window*> handle2WindowMap;

			typedef LRESULT (*FP_WndProc)(I_Window* window, UINT msg, WPARAM wparam, LPARAM lparam);

			WindowHandle CreateBasicWindow(
				const S_WindowDesc& desc,
				I_Window* window
			);

			void DestroyWindow(WindowHandle handle);

			void SetWindowVisibility(WindowHandle handle, E_WindowVisibility visibility);

		}

	}

}