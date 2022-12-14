#include "Race.h"

namespace Racing
{
	Race::Race()
	{
		arr = new Transport * [racers] { nullptr };
		results_to_print = new std::string[racers];
	}

	Race::~Race()
	{
		for (int i = 0; i < racers; ++i)
		{
			delete arr[i];
			arr[i] = nullptr;
		}
		delete[] arr;
		arr = nullptr;

		delete[] results_to_print;
		results_to_print = nullptr;
	}

	void Race::reset()
	{
		for (int i = 0; i < racers; ++i)
		{
			arr[i] = nullptr;
			results_to_print[i] = "";
		}
		distance = 0.0;
		race_type = 0;
		racer = -1;
		tmp = nullptr;
		counter_racers = 0;
	}

	void Race::set_race_type(int rt)
	{
		race_type = rt;
	}

	int Race::get_race_type()
	{
		return race_type;
	}

	void Race::set_distance(double ds)
	{
		distance = ds;
	}

	double Race::get_distance()
	{
		return distance;
	}

	int Race::get_counter_racers()
	{
		return counter_racers;
	}

	std::string Race::print_registred_transport()
	{
		std::stringstream result;
		for (int i = 0; i < counter_racers - 1; ++i)
			result << arr[i]->get_name() << ", ";
		result << arr[counter_racers - 1]->get_name() << std::endl;
		return result.str();
	}

	void Race::set_racer(int r)
	{
		racer = r;
	}

	int Race::get_racer()
	{
		return racer;
	}

	void Race::choose_racers_to_add()
	{
		switch (racer)
		{
		case 1:
			tmp = new All_Terrain_Boots(distance);
			break;

		case 2:
			tmp = new Broom(distance);
			break;

		case 3:
			tmp = new Camel(distance);
			break;

		case 4:
			tmp = new Centaur(distance);
			break;

		case 5:
			tmp = new Eagle(distance);
			break;

		case 6:
			tmp = new Speed_Camel(distance);
			break;

		case 7:
			tmp = new Magic_Carpet(distance);
			break;

		case 0:
			if (counter_racers < 2)
			{
				//продолжаем добавлять транспорт для гонки до как минимум двух
				racer = -1;
			}
			break;

		default:
			break;
		}

		if (racer > 0)
		{
			//если гонка не смешанного типа, проверяем соответствие транспорта типу гонки
			if ((race_type != 3) && (tmp->get_transport_type() != race_type))
			{
				delete tmp;
				tmp = nullptr;
				throw TransportException("Попытка зарегистрировать неправильный тип транспортного средства!");
			}
			// был ли такой транспорт у нас уже зарагистрирован, если нет, то добавляем
			if (!search_transport(arr, counter_racers, tmp))
			{
				arr[counter_racers] = tmp;
				++counter_racers;
				std::string info_str;
				info_str += tmp->get_name();
				info_str += " зарегистрирован на гонку!";
				throw TransportException(info_str);
			}
			else
			{
				std::string info_str;
				info_str += tmp->get_name();
				info_str += " уже зарегистрирован";
				delete tmp;
				tmp = nullptr;
				throw TransportException(info_str);
			}
		}
	}

	void Race::do_racing()
	{
		//проводим гонку
		for (int i = 0; i < counter_racers; ++i)
		{
			arr[i]->do_racing();
		}
		sort_results();
	}

	std::string* Race::print_results() const
	{
		for (int i = 0; i < counter_racers; ++i)
		{
			std::stringstream result;
			result << (i + 1) << ". " << arr[i]->get_name() << ". Время: " << arr[i]->get_racing_time();
			results_to_print[i] = result.str();
		}
		return results_to_print;
	}

	bool Race::search_transport(Transport* arr[], int counter, Transport* Tr)
	{
		if (0 == counter) return false;

		bool exist = false;
		int i = 0;
		while (!exist && i < counter)
		{
			if (arr[i]->get_name() == Tr->get_name()) exist = true;
			++i;
		}
		return exist;
	}

	void Race::sort_results()
	{
		//сортируем результаты гонки
		for (int i = 1; i < counter_racers; ++i)
			for (int j = i - 1; j >= 0; --j)
			{
				if (arr[j]->get_racing_time() > arr[j + 1]->get_racing_time())
					std::swap(*(arr + j), *(arr + j + 1));
			}
	}
}