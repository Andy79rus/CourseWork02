#pragma once
#include <string>

namespace Racing
{
	class Transport
	{
	public:
		std::string get_name();
		double get_racing_time();
		virtual void do_racing();
		int get_transport_type();

	protected:
		int get_speed();
		void set_speed(int s);
		void set_name(std::string s);
		void set_transport_type(int tr_t);
		virtual void set_racing_time(double tm);

	private:
		int speed = 0;
		std::string name;
		int transport_type = 0;
		double racing_time = 0.0;
	};
}