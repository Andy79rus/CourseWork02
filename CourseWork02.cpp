#include <iostream>
#include <windows.h>
#include <iomanip>
#include <regex>
#include "Race.h"
#include "ErrorEx.h"

double set_race_distance()
{
	std::string user_input;;
	bool correct = false;
	double result = 0.0;
	do
	{
		std::cout << "Укажите длину дистанции гонки (должна быть положительна): ";
		std::cin >> user_input;

		try
		{
			result = std::stod(user_input);
			if (result > 0) correct = true;
		}
		catch (std::invalid_argument)
		{}

		if (!correct) std::cout << "Неправильный ввод! Введено неправильное числовое значение (Требуется: положительное число)." << std::endl;
	} while (!correct);

	return result;
}

int user_input_request(std::string msg_string, int input1, int input2)
{
	std::string user_input;
	bool correct = false;
	int result = 0;
	do
	{
		std::cout << msg_string << ": ";
		std::cin >> user_input;

		std::regex reg("^[0-9]{1,1}$");
		if (std::regex_match(user_input, reg))
		{
			try
			{
				result = std::stoi(user_input);
				if ((result >= input1) && (result <= input2)) correct = true;
			}
			catch (std::invalid_argument)
			{}
		}
		if (!correct)
		{
			std::cout << "Неправильный ввод! Введено неправильное числовое значение (Требуется: целое число";
			(input1 == input2) ? (std::cout << " " << input1 << ")." << std::endl) : (std::cout << " от " << input1 << " до " << input2 << ")." << std::endl);
		}
	} while (!correct);

	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Racing::Race Racing;

	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	do
	{
		Racing.reset();
		std::cout << "1. Гонка для наземного транспорта." << std::endl;
		std::cout << "2. Гонка для воздушного транспорта." << std::endl;
		std::cout << "3. Гонка для наземного и воздушного транспорта (смешанная)." << std::endl;
		Racing.set_race_type(user_input_request("Выберите тип гонки (1, 2, 3)", 1, 3));
		Racing.set_distance(set_race_distance());

		do
		{
			std::cout << "Гонка ";
			switch (Racing.get_race_type())
			{
			case 1: std::cout << "для наземного транспорта. ";
				break;
			case 2: std::cout << "для воздушного транспорта. ";
				break;
			case 3: std::cout << "для наземного и воздушного транспорта (смешанная). ";
				break;
			}
			std::cout << "Расстояние: " << Racing.get_distance() << std::endl;
			if (Racing.get_counter_racers() > 0)
			{
				std::cout << "Зарегистрированные транспортные средства: ";
				std::cout << Racing.print_registred_transport();
			}
			if (Racing.get_counter_racers() < 2)
			{
				std::cout << "Должно быть зарегистрировано хотя бы 2 траспортных средства." << std::endl;
				std::cout << "1. Зарегистрировать транспорт." << std::endl;
				user_input_request("Выберите действие", 1, 1);
			}
			std::cout << "1. Ботинки-вездеходы (наземный)." << std::endl;
			std::cout << "2. Метла (воздушный)." << std::endl;
			std::cout << "3. Верблюд (наземный)." << std::endl;
			std::cout << "4. Кентавр (наземный)." << std::endl;
			std::cout << "5. Орел (воздушный)." << std::endl;
			std::cout << "6. Верблюд-быстроход (наземный)." << std::endl;
			std::cout << "7. Ковер-самолет (воздушный)." << std::endl;
			std::cout << "0. Закончить регистрацию." << std::endl;
			Racing.set_racer(user_input_request("Выберите транспорт или 0 для окончания процесса регистрации", 0, 7));
			try
			{
				Racing.choose_racers_to_add();
			}
			catch (TransportException& ex)
			{
				std::cout << ex.what() << std::endl;
			}
			// проверяем, что число транспорта на гонку не менее двух
			if (Racing.get_counter_racers() >= 2)
			{
				std::cout << "1. Зарегистрировать транспорт." << std::endl;
				std::cout << "2. Начать гонку." << std::endl;
				if (user_input_request("Выберите действие", 1, 2) == 2)
				{
					//начинаем гонку
					Racing.set_racer(0);
				}
				else Racing.set_racer(-1); //пробуем дальше добавлять транспорт для гонки
			}

			// если добавили все семь транспортов, то остается только начать гонку
			if (7 == Racing.get_counter_racers())
			{
				std::cout << "Достигнут максимум регистраций транспорта - 7 единиц. Начинаем гонку!" << std::endl;
				Racing.set_racer(0);
			}

		} while (0 != Racing.get_racer());

		Racing.do_racing();

		std::cout << "Результаты гонки:" << std::endl;
		std::cout.setf(std::ios_base::fixed);
		std::cout << std::setprecision(2);

		for (int i = 0; i < Racing.get_counter_racers(); ++i)
			std::cout << *(Racing.print_results() + i) << std::endl;
		std::cout << std::endl;

		std::cout << "1. Провести еще одну гонку." << std::endl;
		std::cout << "2. Выйти." << std::endl;

	} while (!static_cast<bool>(user_input_request("Выберите действие", 1, 2) - 1));

	std::cout << "Завершаем работу." << std::endl;
	std::cout << "До свидания!" << std::endl;

	return 0;
}