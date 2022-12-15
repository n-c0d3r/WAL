#pragma once

#include <WAL/.BuildInfo>

#include <iostream>



namespace WAL {

	using U8 = std::uint8_t;
	using U16 = std::uint16_t;
	using U32 = std::uint32_t;
	using U64 = std::uint64_t;

	using I8 = std::int8_t;
	using I16 = std::int16_t;
	using I32 = std::int32_t;
	using I64 = std::int64_t;

	using B8 = bool;

	struct U8x2 {

		U8 x;
		U8 y;

	};

	struct U8x3 {

		U8 x;
		U8 y;

	};

	struct U8x4 {

		U8 x;
		U8 y;

	};

	struct U16x2 {

		U16 x;
		U16 y;

	};

	struct U16x3 {

		U16 x;
		U16 y;

	};

	struct U16x4 {

		U16 x;
		U16 y;

	};

	struct U32x2 {

		U32 x;
		U32 y;

	};

	struct U32x3 {

		U32 x;
		U32 y;

	};

	struct U32x4 {

		U32 x;
		U32 y;

	};

	struct U64x2 {

		U64 x;
		U64 y;

	};

	struct U64x3 {

		U64 x;
		U64 y;

	};

	struct U64x4 {

		U64 x;
		U64 y;

	};

}