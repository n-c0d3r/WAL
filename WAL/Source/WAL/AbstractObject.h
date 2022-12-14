#pragma once

#include <WAL/.BuildInfo>



namespace WAL {

	class I_AbstractObject {

	public:
		virtual void Release() { delete this; }

	};

}