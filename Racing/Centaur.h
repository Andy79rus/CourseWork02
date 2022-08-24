#pragma once
#include "Ground_Transport.h"

namespace Racing
{
	class Centaur : public Ground_Transport
	{
	public:
		Centaur(double distance);

	protected:
		void set_rest_duration() override;
	};
}