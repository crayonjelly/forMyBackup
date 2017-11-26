#pragma once


namespace OBJKIND
{
	enum Enum
	{
		NONE,
		MAPBUFFER,
		PIXELBUFFER,
		BACKGROUND,
		CLOUD,
		TERRAIN,
		OTUS,
		GEDDY,
		GAWK,
		FRUIT_BLUE,
		END
	};
}

namespace LAYER
{
	enum Enum
	{
		SKY3,
		SKY2,
		SKY1,
		BACK3,
		BACK2,
		BACK1,
		//---
		TERRAIN3,
		TERRAIN2,
		TERRAIN1,
		PIXELDC,		//디버그용
		FRUIT,
		TEAM,
		NPC,
		OTUS,
		GRAB_LIGHT,
		ARM,
		GRAB_HEAVY,
		GRAB_TEAM,
		COINBOX,
		FRONT_TERRAIN,
		//---
		FRONT1,
		FRONT2,
		FOG,
		MASK,
		UI,
		END
	};
}
