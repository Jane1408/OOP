#include "stdafx.h"
#include "Car.h"

static const std::map <Gearbox, std::pair<unsigned, unsigned>> SPEED_RANGE = {
	{ Gearbox::BACK,{ 0, 20 } },
	{ Gearbox::NEUTRAL,{ 0, 150 } },
	{ Gearbox::FIRST,{ 0, 30 } },
	{ Gearbox::SECOND,{ 20, 50 } },
	{ Gearbox::THIRD,{ 30, 60 } },
	{ Gearbox::FOURTH,{ 40, 90 } },
	{ Gearbox::FIFTH,{ 50, 150 } }
};

CCar::CCar()
	: m_isTurnedOn(false)
	, m_currentSpeed(0)
	, m_gearState(Gearbox::NEUTRAL)
	, m_movementDirection(MovementDirection::STANDING)
{
}

bool CCar::TurnOn()
{
	if (!m_isTurnedOn)
	{
		m_isTurnedOn = true;
		m_errorString = "";
		return true;
	}
	m_errorString = "car already turned on";
	return false;
}

bool CCar::IsTurnedOn() const
{
	return m_isTurnedOn;
}

bool CCar::TurnOff()
{
	if (!m_isTurnedOn)
	{
		m_errorString = "car cannot be turn off if car already turned on";
		return false;
	}
	else if (m_gearState != Gearbox::NEUTRAL)
	{
		m_errorString = "car cannot be turn off if gear is not neutral";
		return false;
	}
	else if (m_currentSpeed != 0)
	{
		m_errorString = "car cannot be turn off if speed is not zero";
		return false;
	}
	m_isTurnedOn = false;
	m_errorString = "";
	return true;
}

std::string CCar::GetError() const
{
	return m_errorString;
}

unsigned CCar::GetSpeed() const
{
	return m_currentSpeed;
}

Gearbox CCar::GetGear() const
{
	return m_gearState;
}

MovementDirection CCar::GetMovementDirection() const
{
	return m_movementDirection;
}

bool CCar::SetSpeed(unsigned const & speed)
{
	if (!m_isTurnedOn)
	{
		m_errorString = "car speed cannot be transferred when car is turned off";
		return false;
	}
	if ((m_gearState == Gearbox::NEUTRAL) && (speed > m_currentSpeed))
	{
		m_errorString = "car speed cannot be transferred to large value on neutral gear";
		return false;
	}
	if ((speed < SPEED_RANGE.find(m_gearState)->second.first) || (speed > SPEED_RANGE.find(m_gearState)->second.second))
	{
		m_errorString = "car speed cannot be transferred if speed out of gear range";
		return false;
	}
	m_currentSpeed = speed;
	SetMovementDirection();
	m_errorString = "";
	return true;
}

bool CCar::SetGear(Gearbox const & gear)
{
	if (!m_isTurnedOn)
	{
		m_errorString = "car gear cannot be transferred when car is turned off";
		return false;
	}
	if ((m_currentSpeed < SPEED_RANGE.find(gear)->second.first) || (m_currentSpeed > SPEED_RANGE.find(gear)->second.second))
	{
		m_errorString = "car gearbox cannot be transferred if speed out of range this gear";
		return false;
	}
	if (gear == Gearbox::BACK && m_movementDirection == MovementDirection::FORWARD)
	{
		m_errorString = "car gearbox cannot be transferred to back if car is moving forward";
		return false;
	}
	if (m_movementDirection == MovementDirection::BACKWARD && (gear != Gearbox::NEUTRAL && m_movementDirection != MovementDirection::STANDING))
	{
		m_errorString = "car gearbox cannot be transferred to this gear if car is moving backward";
		return false;
	}
	m_gearState = gear;
	m_errorString = "";
	return true;
}

void CCar::SetMovementDirection()
{
	if ((m_gearState != Gearbox::NEUTRAL) && (m_currentSpeed != 0))
	{
		if (m_gearState == Gearbox::BACK)
		{
			m_movementDirection = MovementDirection::BACKWARD;
		}
		else 
		{
			m_movementDirection = MovementDirection::FORWARD;
		}
	}
	else if (m_currentSpeed == 0)
	{
		m_movementDirection = MovementDirection::STANDING;
	}
}
