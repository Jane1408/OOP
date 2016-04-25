#pragma once

enum class Gearbox { BACK = -1, NEUTRAL = 0, FIRST = 1, SECOND = 2, THIRD = 3, FOURTH = 4, FIFTH = 5 };

enum class MovementDirection {BACKWARD = -1, STANDING = 0, FORWARD = 1};

static const std::map <Gearbox, std::pair<unsigned, unsigned>> SPEED_RANGE = {
	{ Gearbox::BACK, {0, 20} },
	{ Gearbox::NEUTRAL, {0, 150} },
	{ Gearbox::FIRST, {0, 30} },
	{ Gearbox::SECOND, {20, 50} },
	{ Gearbox::THIRD, {30, 60} },
	{ Gearbox::FOURTH, {40, 90} },
	{ Gearbox::FIFTH, {50, 150} }
};

class CCar
{
public:
	CCar();
	~CCar() = default;
	bool TurnOn(); //включение
	bool IsTurnedOn(); //уже включена
	bool TurnOff();
	unsigned GetSpeed();
	Gearbox GetGear();
	MovementDirection GetMovementDirection();
	bool SetSpeed(unsigned const& speed);
	bool SetGear(Gearbox const& gear);
	
private:
	bool m_isTurnedOn; //состояние
	unsigned m_currentSpeed;
	Gearbox m_gearState;
	MovementDirection m_movementDirection;
	void SetMovementDirection();
};

