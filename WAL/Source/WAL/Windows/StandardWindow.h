#pragma once

#include <WAL/StandardWindow.h>



namespace WAL {

	namespace Windows {

		class C_StandardWindow :
			public I_StandardWindow
		{

		private:
			WindowHandle m_WindowHandle;



		public:
			C_StandardWindow(const S_WindowDesc& desc);



		public:
			virtual void Release() override;

			virtual size_t Proc(void* param) override;

			WindowHandle GetWindowHandle() { return m_WindowHandle; }

		};

	}

}