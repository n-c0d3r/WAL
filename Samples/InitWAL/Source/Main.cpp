#include <WAL/WAL.h>



int main() {

	WAL::I_API* api = WAL::I_API::Create();

	WAL::I_Window* standardWindow = WAL::I_StandardWindow::Create({

		L"First Window",

		900,
		500,

		WAL::E_WindowVisibility::Visible

	}); 

	standardWindow->GetEvent("DESTROY")->AddListener([](WAL::C_Event* e) {



	});

	standardWindow->GetEvent("RESIZE")->AddListener([standardWindow](WAL::C_Event* e) {

		std::stringstream output;

		output << standardWindow->GetSize().x;
		output << " ";
		output << standardWindow->GetSize().y;

	});

	standardWindow->GetEvent("MOUSE_MOVE")->AddListener([standardWindow](WAL::C_Event* e) {

		std::stringstream output;

		output << standardWindow->GetMousePosition().x;
		output << " ";
		output << standardWindow->GetMousePosition().y;

		UL::HN_Log::Info(output.str());

	});
	
	while (true) {

		api->CheckMessage();

	}

	return 0;
}