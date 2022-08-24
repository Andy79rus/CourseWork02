#pragma once
#include "Transport.h"
namespace Racing
{
	class Air_transport : public Transport
	{
	public:
		void do_racing() override;

	protected:
		Air_transport();

		virtual void distance_reduction(double distance);
		void set_distance_to_reach(double dr);
		double get_distance_to_reach();

	private:
		double distance_to_reach = 0.0;
	};
}