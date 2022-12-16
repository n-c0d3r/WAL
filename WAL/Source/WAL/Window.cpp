#include "Window.h"
#include "Event.h"

#ifdef WIN32
#include "Windows/Windows.h"
#endif



namespace WAL {

	I_Window::I_Window(const S_WindowDesc& desc) :
		m_Desc(desc),
		name2EventMap({

			{ "DESTROY", C_Event()},

			{ "RESIZE", C_Event()},
			{ "ENTER_SIZE_MOVE", C_Event()},
			{ "EXIT_SIZE_MOVE", C_Event()},

			{ "MOUSE_MOVE", C_Event()},
			{ "MOUSE_RBTN_DOWN", C_Event()},
			{ "MOUSE_RBTN_UP", C_Event()},
			{ "MOUSE_MBTN_DOWN", C_Event()},
			{ "MOUSE_MBTN_UP", C_Event()},
			{ "MOUSE_LBTN_DOWN", C_Event()},
			{ "MOUSE_LBTN_UP", C_Event()}

		}),
		m_MousePosition({0, 0}),
		m_Size({desc.width, desc.height}),
		m_Minimized(false),
		m_Maximized(false)
	{



	}

	void I_Window::Release() {



	}

}