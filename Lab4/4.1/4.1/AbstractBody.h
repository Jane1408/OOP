#pragma once

class CAbstractBody
{
public:
	CAbstractBody();
	~CAbstractBody();

	double GetWeight() const;
	double GetDensity() const;
	double GetVolume() const;
	virtual std::string GetInfo() = 0;
protected:
	virtual void SetWeight(double weight);
	virtual void SetDensity();
	virtual void SetVolume();
	virtual void SetVolume(double volume);

	double m_weight;
	double m_density;
	double m_volume;
};

