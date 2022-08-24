#pragma once
#include "Ground_Transport.h"

namespace Racing
{
	class Speed_Camel : public Ground_Transport
	{
	public:
		Speed_Camel(double distance);

	protected:
		void set_rest_duration() override;
	};
}