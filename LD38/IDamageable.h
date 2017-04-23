#ifndef IDAMAGEABLE_H
#define IDAMAGEABLE_H

#include <algorithm>

template<typename T = int>
class IDamageable
{
public:
	virtual void heal(const T& amount)
	{
		// no clamp function in c++14
		m_health = std::max(std::min((m_health + amount), m_maxHealth), 0);
	}

	virtual void takeDamage(const T& amount)
	{
		m_health = std::max(std::min((m_health - amount), m_maxHealth), 0);
	}

	virtual T& getHealth()
	{
		return m_health;
	}

	virtual T& getMaxHealth()
	{
		return m_maxHealth;
	}

protected:
	T m_health;
	T m_maxHealth;
};

#endif /* IDAMAGEABLE_H */