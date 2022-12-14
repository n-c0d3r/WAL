#include "Helper.h"



namespace WAL {

	namespace Windows {

		namespace HN {

			std::unordered_map<WindowHandle, I_Window*> handle2WindowMap;

			WindowHandle CreateBasicWindow(
				const S_WindowDesc& desc,
				I_Window* window
			) {

				std::wstringstream ss;
				ss << rand() % 0xFFFFFFFF;

				std::wstring className;
				ss >> className;

				className = L"WINDOWCLASS_" + className;



				WNDCLASSEX wc;
				wc.cbClsExtra = NULL;
				wc.cbSize = sizeof(WNDCLASSEX);
				wc.cbWndExtra = NULL;
				wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
				wc.hCursor = LoadCursor(NULL, IDC_ARROW);
				wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
				wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
				wc.hInstance = NULL;
				wc.lpszClassName = className.c_str();
				wc.lpszMenuName = L"";
				wc.style = NULL;
				wc.lpfnWndProc = [](WindowHandle handle, UINT msg, WPARAM wparam, LPARAM lparam)->LRESULT{

					if (handle2WindowMap.find(handle) == handle2WindowMap.end()) 
						return DefWindowProc(handle, msg, wparam, lparam);
				
					I_Window* window = handle2WindowMap[handle];

					S_WindowProcParam procParam = {

						msg,
						wparam,
						lparam

					};

					return window->Proc(&procParam);
				};

				if (!::RegisterClassEx(&wc))
					return 0;

				/* Create Window */
				WindowHandle handle = CreateWindowEx(WS_EX_WINDOWEDGE, className.c_str(), desc.title.c_str(),
					WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, desc.width, desc.height,
					NULL, NULL, NULL, NULL);

				if (!handle)
				{
					std::cout << GetLastError() << std::endl;
				}

				SetWindowVisibility(handle, desc.visibility);

				handle2WindowMap[handle] = window;

				return handle;
			}

			void DestroyWindow(WindowHandle handle) {

				handle2WindowMap.erase(handle);

				::DestroyWindow(handle);

			}

			void SetWindowVisibility(WindowHandle handle, E_WindowVisibility visibility) {

				switch (visibility)
				{
				case WAL::E_WindowVisibility::Visible:
					::ShowWindow(handle, SW_SHOW);
					break;

				case WAL::E_WindowVisibility::Hidden:
					::ShowWindow(handle, SW_HIDE);
					break;

				default:
					break;
				}

				UpdateWindow(handle);

			}

		}

	}

}