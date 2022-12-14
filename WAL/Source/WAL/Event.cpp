#include "Event.h"



namespace WAL {

	C_Event::C_Event() {



	}

	void C_Event::Invoke() {

		for (auto f : m_ListenerList) {

			f(this);

		}

	}

	std::list<std::function<void(C_Event*)>>::iterator C_Event::AddListener(std::function<void(C_Event*)> listener) {

		m_ListenerList.push_back(std::move(listener));

		return std::next(m_ListenerList.end(), -1);
	}
	void C_Event::RemoveListener(std::list<std::function<void(C_Event*)>>::iterator i) {

		m_ListenerList.erase(i);

	}

}