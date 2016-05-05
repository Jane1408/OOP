// Car.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Car.h"
#include "CarCommands.h"

int main()
{
	CCar car;
	std::string command;
	std::string error;
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		std::cin >> command;
		IteractionWithCar(command, car);
		error = car.GetError();
		if (!error.empty())
			std::cout << error << std::endl;
	}
    return 0;
}

