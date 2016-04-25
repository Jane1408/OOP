// Car.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Car.h"

enum class CommandsList { TurnOn, TurnOff, SetSpeed, SetGear, Info, Help };

static const std::map <std::string, CommandsList> MAP_OF_COMMANDS= {
	{ "TurnOn", CommandsList::TurnOn },
	{ "TurnOff", CommandsList::TurnOff },
	{ "SetSpeed", CommandsList::SetSpeed },
	{ "SetGear", CommandsList::SetGear },
	{ "Info", CommandsList::Info },
	{ "Help", CommandsList::Help }
};

static const std::map <std::string, Gearbox> MAP_OF_GEARBOX_STATES = {
	{ "back", Gearbox::BACK },
	{ "neutral", Gearbox::NEUTRAL },
	{ "first", Gearbox::FIRST },
	{ "second", Gearbox::SECOND },
	{ "third", Gearbox::THIRD },
	{ "fourth", Gearbox::FOURTH },
	{ "fifth", Gearbox::FIFTH }
};

static const std::map <MovementDirection, std::string> MAP_OF_MOVEMENT_DIRECTIONS_FOR_INFO = {
	{ MovementDirection::BACKWARD, "backward" },
	{ MovementDirection::STANDING, "standing" },
	{ MovementDirection::FORWARD, "forward" }
};

static const std::map <Gearbox, std::string> MAP_OF_GEARBOX_STATES_FOR_INFO = {
	{ Gearbox::BACK, "back" },
	{ Gearbox::NEUTRAL, "neutral" },
	{ Gearbox::FIRST, "first" },
	{ Gearbox::SECOND, "second" },
	{ Gearbox::THIRD, "third" },
	{ Gearbox::FOURTH, "fourth" },
	{ Gearbox::FIFTH, "fifth" }
};


void ShowInfo(CCar & car)
{
	std::string engineCondition;
	engineCondition = (car.IsTurnedOn() == true ? "Engine active!" : "Engine disabled");
	std::cout << engineCondition << std::endl;
	std::cout << "Movement Direction: " << MAP_OF_MOVEMENT_DIRECTIONS_FOR_INFO.find(car.GetMovementDirection())-> second << std::endl;
	std::cout << "Current Speed: " << car.GetSpeed() << std::endl;
	std::cout << "Gearbox state: " << MAP_OF_GEARBOX_STATES_FOR_INFO.find(car.GetGear())->second << std::endl;
}

void ShowHelp()
{
	std::cout << "Using commands: " << std::endl;
	std::cout << "TurnOn - to start engine" << std::endl;
	std::cout << "TurnOff - to finish engine" << std::endl;
	std::cout << "SetSpeed <value> - to set speed" << std::endl;
	std::cout << "SetGear <value> - to set gear" << std::endl;
	std::cout << "Info - show information about the car" << std::endl;
}

int main()
{
	CCar car;
	std::string command;
	unsigned speedValue;
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		std::cin >> command;
		if (MAP_OF_COMMANDS.find(command) != MAP_OF_COMMANDS.end())
		{
			switch (MAP_OF_COMMANDS.find(command)->second)
			{
			case CommandsList::TurnOn:
				car.TurnOn();
				break;
			case CommandsList::TurnOff:
				car.TurnOff();
				break;
			case CommandsList::SetSpeed:
				std::cin >> speedValue;
				car.SetSpeed(speedValue);
				break;
			case CommandsList::SetGear:
				std::cin >> command;
				if (MAP_OF_GEARBOX_STATES.find(command) != MAP_OF_GEARBOX_STATES.end())
				{
					car.SetGear(MAP_OF_GEARBOX_STATES.find(command)->second);
				}
				else
				{
					std::cout << "Invalid gear " << command << std::endl;
				}
				break;
			case CommandsList::Info:
				ShowInfo(car);
				break;
			case CommandsList::Help:
				ShowHelp();
				break;
			}
		}
		else
		{
			std::cout << "Invalid command"  << std::endl;
		}
	}
    return 0;
}

