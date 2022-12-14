#include "Window.h"

#ifdef WIN32
#include "Windows/Windows.h"
#endif



namespace WAL {

	I_Window::I_Window(const S_WindowDesc& desc) :
		m_Desc(desc)
	{



	}

	void I_Window::Release() {

		I_AbstractObject::Release();

	}

}