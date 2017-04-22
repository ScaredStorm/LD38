#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <chrono>

template<typename Engine = std::minstd_rand>
class Random
{
public:
	Random()
	{
		seed(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
	}

	Random(unsigned int s)
	{
		seed(s);
	}

	void seed(unsigned int s)
	{
		engine.seed(s);
	}

	int range(int min, int max)
	{
		std::uniform_int_distribution<int> ud(min, max);
		return ud(engine);
	}
	float rangeReal(float min, float max)
	{
		std::uniform_real_distribution<float> ud(min, max);
		return ud(engine);
	}

private:
	Engine engine;
};

#endif /* RANDOM_H */
