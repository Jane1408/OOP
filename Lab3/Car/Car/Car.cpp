#include "stdafx.h"
#include "Car.h"


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
		return true;
	}
	return false;
}

bool CCar::IsTurnedOn()
{
	return m_isTurnedOn;
}

bool CCar::TurnOff()
{
	if (m_isTurnedOn && (m_gearState == Gearbox::NEUTRAL) && (m_currentSpeed == 0))
	{
		m_isTurnedOn = false;
		return true;
	}
	return false;
}

unsigned CCar::GetSpeed()
{
	return m_currentSpeed;
}

Gearbox CCar::GetGear()
{
	return m_gearState;
}

MovementDirection CCar::GetMovementDirection()
{
	return m_movementDirection;
}

bool CCar::SetSpeed(unsigned const & speed)
{
	if (!m_isTurnedOn)
		return false;
	if ((m_gearState == Gearbox::NEUTRAL) && (speed > m_currentSpeed))
		return false;
	if ((speed < SPEED_RANGE.find(m_gearState)->second.first) || (speed > SPEED_RANGE.find(m_gearState)->second.second))
		return false;
	m_currentSpeed = speed;
	SetMovementDirection();
	return true;
}

bool CCar::SetGear(Gearbox const & gear)
{
	if (!m_isTurnedOn)
		return false;
	if ((m_currentSpeed < SPEED_RANGE.find(gear)->second.first) || (m_currentSpeed > SPEED_RANGE.find(gear)->second.second))
		return false;
	if (gear == Gearbox::BACK && m_movementDirection == MovementDirection::FORWARD)
		return false;
	if (m_movementDirection == MovementDirection::BACKWARD && (gear != Gearbox::NEUTRAL && m_movementDirection != MovementDirection::STANDING))
		return false;
	m_gearState = gear;
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
