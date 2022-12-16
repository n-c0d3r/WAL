#pragma once

#include <WAL/.BuildInfo>
#include <WAL/Utils.h>

#include <WAL/Event.h>



namespace WAL {

	class C_Event;



	enum class E_WindowVisibility {

		Visible,
		Hidden

	};

	struct S_WindowDesc {

		std::wstring title;
		UL::U32 width;
		UL::U32 height;
		E_WindowVisibility visibility;

	};



	class I_Window :
		public UL::I_AbstractObject
	{

	private:
		S_WindowDesc m_Desc;
		std::unordered_map<std::string, C_Event> name2EventMap;

	protected:
		UL::U32x2 m_MousePosition;
		UL::U32x2 m_Size;
		bool m_Minimized = false;  // is the application minimized?
		bool m_Maximized = false;  // is the application maximized?
		bool m_Resizing = false;   // are the resize bars being dragged?



	protected:
		I_Window(const S_WindowDesc& desc);



	public:
		virtual void Release() override;

		virtual size_t Proc(void* param) { return 0; }

		S_WindowDesc GetDesc() { return m_Desc; }

		bool IsHasEvent(const std::string& name) { return name2EventMap.find(name) != name2EventMap.end(); }
		C_Event* GetEvent(const std::string& name) { return &name2EventMap[name]; }
		UL::U32x2 GetMousePosition() { return m_MousePosition; }
		UL::U32x2 GetSize() { return m_Size; }
		bool IsMinimized() { return m_Minimized; }
		bool IsMaximized() { return m_Maximized; }
		bool IsResizing() { return m_Resizing; }

	};

}