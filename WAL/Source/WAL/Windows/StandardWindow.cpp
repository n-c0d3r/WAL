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
			UL::I_AbstractObject::Release();

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

				m_Size = { LOWORD(procParam.lparam), HIWORD(procParam.lparam) };

				if (procParam.wparam == SIZE_MINIMIZED)
				{
					m_Minimized = true;
					m_Maximized = false;
				}
				else if (procParam.wparam == SIZE_MAXIMIZED)
				{
					m_Minimized = false;
					m_Maximized = true;
					GetEvent("RESIZE")->Invoke();
				}
				else if (procParam.wparam == SIZE_RESTORED)
				{

					// Restoring from minimized state?
					if (m_Minimized)
					{
						m_Minimized = false;
						GetEvent("RESIZE")->Invoke();
					}

					// Restoring from maximized state?
					else if (m_Maximized)
					{
						m_Maximized = false;
						GetEvent("RESIZE")->Invoke();
					}
					else if (m_Resizing)
					{
						GetEvent("RESIZE")->Invoke();
					}
					else
					{
						GetEvent("RESIZE")->Invoke();
					}
				}

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_ENTERSIZEMOVE:
			{

				m_Resizing = true;

				GetEvent("ENTER_SIZE_MOVE")->Invoke();

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_EXITSIZEMOVE:
			{

				m_Resizing = false;

				GetEvent("EXIT_SIZE_MOVE")->Invoke();

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_MOUSEMOVE:
			{

				m_MousePosition = { LOWORD(procParam.lparam), HIWORD(procParam.lparam) };

				GetEvent("MOUSE_MOVE")->Invoke();

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_LBUTTONDOWN:
			{

				GetEvent("MOUSE_LBTN_DOWN")->Invoke();

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_MBUTTONDOWN:
			{

				GetEvent("MOUSE_MBTN_DOWN")->Invoke();

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_RBUTTONDOWN:
			{

				GetEvent("MOUSE_RBTN_DOWN")->Invoke();

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_LBUTTONUP:
			{

				GetEvent("MOUSE_LBTN_UP")->Invoke();

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_MBUTTONUP:
			{

				GetEvent("MOUSE_MBTN_UP")->Invoke();

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
				break;
			}
			case WM_RBUTTONUP:
			{

				GetEvent("MOUSE_RBTN_UP")->Invoke();

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

			default:

				return ::DefWindowProc(m_WindowHandle, procParam.msg, procParam.wparam, procParam.lparam);
			}

			return NULL;
		}

	}

}