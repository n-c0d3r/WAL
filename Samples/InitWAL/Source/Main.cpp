#include <WAL/WAL.h>



int main() {

	WAL::I_API* api = WAL::I_API::Create();

	WAL::I_Window* standardWindow = WAL::I_StandardWindow::Create({

		L"First Window",

		900,
		500,

		WAL::E_WindowVisibility::Visible

	});

	WAL::I_Window* standardWindow2 = WAL::I_StandardWindow::Create({

		L"Second Window",

		900,
		500,

		WAL::E_WindowVisibility::Visible

	});

	while (true) {

		api->CheckMessage();

	}

	return 0;
}