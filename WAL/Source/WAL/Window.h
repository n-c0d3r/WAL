#pragma once

#include <WAL/.BuildInfo>
#include <WAL/Utils.h>

#include <WAL/AbstractObject.h>
#include <WAL/Singleton.h>



namespace WAL {



	enum class E_WindowVisibility {

		Visible,
		Hidden

	};

	struct S_WindowDesc {

		std::wstring title;
		U32 width;
		U32 height;
		E_WindowVisibility visibility;

	};



	class I_Window :
		public I_AbstractObject
	{

	private:
		S_WindowDesc m_Desc;



	protected:
		I_Window(const S_WindowDesc& desc);



	public:
		virtual void Release() override;

		virtual size_t Proc(void* param) { return 0; }

		S_WindowDesc GetDesc() { return m_Desc; }

	};

}