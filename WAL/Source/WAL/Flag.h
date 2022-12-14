#pragma once

#include <WAL/.BuildInfo>
#include <WAL/Utils.h>



namespace WAL {

	using Flag32 = U32;
	using Flag64 = U64;

}



#define WAL_BEGIN_FLAGS(Name) \
struct S_##Name {

#define WAL_END_FLAGS(Name) \
};\
extern S_##Name Name;

#define WAL_DEFINE_FLAGS(Name) S_##Name Name;

#define WAL_FLAG32(Name) WAL::Flag32 Name = 0;
#define WAL_FLAG64(Name) WAL::Flag64 Name = 0;