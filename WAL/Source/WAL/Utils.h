#pragma once

#include <WAL/.BuildInfo>

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <exception>
#include <random>
#include <sstream>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "Types.h"
#include "Log.h"
#include "Exception.h"

namespace WAL {

#ifdef WIN32
	using WindowHandle = HWND;
#endif

}