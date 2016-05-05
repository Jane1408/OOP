#pragma once

enum class Gearbox { BACK = -1, NEUTRAL = 0, FIRST = 1, SECOND = 2, THIRD = 3, FOURTH = 4, FIFTH = 5 };

enum class MovementDirection {BACKWARD = -1, STANDING = 0, FORWARD = 1};

extern const std::map<Gearbox, std::pair<unsigned, unsigned>> SPEED_RANGE;

class CCar
{
public:
	CCar();
	~CCar() = default;
	bool TurnOn(); 
	bool IsTurnedOn() const; 
	bool TurnOff();
	std::string GetError() const;
	unsigned GetSpeed() const;
	Gearbox GetGear() const;
	MovementDirection GetMovementDirection() const;
	bool SetSpeed(unsigned const& speed);
	bool SetGear(Gearbox const& gear);
	
private:
	std::string m_errorString;
	bool m_isTurnedOn;
	unsigned m_currentSpeed;
	Gearbox m_gearState;
	MovementDirection m_movementDirection;
	void SetMovementDirection();
};

