#pragma once

#include "Window.h"



namespace WAL {

	class I_StandardWindow :
		public I_Window
	{

	private:
		



	protected:
		I_StandardWindow(const S_WindowDesc& desc);



	public:
		static I_StandardWindow* Create(const S_WindowDesc& desc);
		virtual void Release() override;

	};

}