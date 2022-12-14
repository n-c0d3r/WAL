#include "StandardWindow.h"

#include "Helper.h"



namespace WAL {

	namespace Windows {

		C_StandardWindow::C_StandardWindow(const S_WindowDesc& desc) :
			I_StandardWindow(desc),

			m_WindowHandle(0)
		{

			m_WindowHandle = HN::CreateBasicWindow(
				desc,
				this
			);

		}

		void C_StandardWindow::Release() {

			if (HN::handle2WindowMap.find(m_WindowHandle) != HN::handle2WindowMap.end()) {

				HN::DestroyWindow(m_WindowHandle);

			}

			I_StandardWindow::Release();

		}

		size_t C_StandardWindow::Proc(void* vparam) {

			S_WindowProcParam procParam = *((S_WindowProcParam*)vparam);

			switch (procParam.msg)
			{
			case WM_CREATE:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}

			case WM_DESTROY:
			{

				GetEvent("DESTROY")->Invoke();

				HN::handle2WindowMap.erase(m_WindowHandle);

				Release();

				::PostQuitMessage(0);
				break;
			}
			case WM_SIZE:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_ENTERSIZEMOVE:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_EXITSIZEMOVE:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_MOUSEMOVE:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_LBUTTONDOWN:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_MBUTTONDOWN:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_RBUTTONDOWN:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_LBUTTONUP:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_MBUTTONUP:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_RBUTTONUP:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_KEYDOWN:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_KEYUP:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_MOUSELEAVE:
			{

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}

			default:

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
			}

			return NULL;
		}

	}

}