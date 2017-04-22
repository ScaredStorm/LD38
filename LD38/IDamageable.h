#ifndef IDAMAGEABLE_H
#define IDAMAGEABLE_H

#include <algorithm>

template<typename T>
class IDamageable
{
public:
	virtual void heal(T amount)
	{
		// no clamp function in c++14
		m_health = std::max(std::min((m_health - amount), m_maxHealth), 0);
	}

	virtual void takeDamage(T amount)
	{

	}

protected:
	T m_health;
	T m_maxHealth;
};

#endif /* IDAMAGEABLE_H */