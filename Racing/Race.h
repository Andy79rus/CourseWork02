#pragma once
#include "Transport.h"
#include "All_Terrain_Boots.h"
#include "Broom.h"
#include "Camel.h"
#include "Centaur.h"
#include "Eagle.h"
#include "Magic_Carpet.h"
#include "Speed_Camel.h"
#include "ErrorEx.h"
#include <sstream>

#ifdef RACINGLIBRARYDYNAMIC_EXPORTS
#define RACING_API __declspec(dllexport)
#else
#define RACING_API __declspec(dllimport)
#endif

namespace Racing
{
	class Race
	{
	public:
		RACING_API Race();
		RACING_API ~Race();
		RACING_API void set_race_type(int rt);
		RACING_API int get_race_type();
		RACING_API void set_distance(double ds);
		RACING_API double get_distance();
		RACING_API int get_counter_racers();
		RACING_API std::string print_registred_transport();
		RACING_API void set_racer(int r);
		RACING_API int get_racer();
		RACING_API void choose_racers_to_add();
		RACING_API void do_racing();
		RACING_API std::string* print_results() const;
		RACING_API void reset();

	private:
		Race& operator=(const Race& r) = delete;
		Race(const Race& r) = delete;

		bool search_transport(Transport* arr[], int counter, Transport* Tr);
		void sort_results();

		const int racers = 7;

		Transport** arr = nullptr;
		std::string* results_to_print;
		double distance = 0.0;
		int race_type = 0;
		int racer = -1;
		Transport* tmp = nullptr;
		int counter_racers = 0;
	};
}