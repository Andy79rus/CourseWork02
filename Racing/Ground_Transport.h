#pragma once
#include "Transport.h"

namespace Racing
{
	class Ground_Transport : public Transport
	{
	public:
		void do_racing() override;

	protected:
		Ground_Transport();

		void set_time_to_rest(int ttr);
		int get_time_to_rest();
		void set_full_distance(double distance);
		double get_full_distance();
		void set_rest_count(int rc);
		int get_rest_count();
		virtual void set_rest_duration();
		double get_rest_duration();
		double rest_duration = 0.0;

	private:
		int time_to_rest = 0;
		int rest_count = 0;
		double full_distance = 0.0;
	};
}