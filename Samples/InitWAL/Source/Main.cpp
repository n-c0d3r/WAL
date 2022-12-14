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

		WAL::HN_Log::Info("Destroy");

	});
	
	while (true) {

		api->CheckMessage();

	}

	return 0;
}