#include "StandardWindow.h"

#ifdef WIN32
#include "Windows/Windows.h"
#endif



namespace WAL {

	I_StandardWindow::I_StandardWindow(const S_WindowDesc& desc) :
		I_Window(desc)
	{



	}

	I_StandardWindow* I_StandardWindow::Create(const S_WindowDesc& desc) {

#ifdef WIN32
		return new Windows::C_StandardWindow(desc);
#endif

		return 0;
	}
	void I_StandardWindow::Release() {

		I_Window::Release();

	}

}