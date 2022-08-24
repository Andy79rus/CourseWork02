#pragma once
#include "Ground_Transport.h"

namespace Racing
{
	class All_Terrain_Boots : public Ground_Transport
	{
	public:
		All_Terrain_Boots(double distance);

	protected:
		void set_rest_duration() override;
	};
}