#pragma once

#include <WAL/.BuildInfo>
#include <WAL/Utils.h>

#include <WAL/AbstractObject.h>
#include <WAL/Singleton.h>

#include <WAL/Event.h>



namespace WAL {

	class C_Event;



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
		std::unordered_map<std::string, C_Event> name2EventMap;



	protected:
		I_Window(const S_WindowDesc& desc);



	public:
		virtual void Release() override;

		virtual size_t Proc(void* param) { return 0; }

		S_WindowDesc GetDesc() { return m_Desc; }

		bool IsHasEvent(const std::string& name) { return name2EventMap.find(name) != name2EventMap.end(); }
		C_Event* GetEvent(const std::string& name) { return &name2EventMap[name]; }

	};

}