#ifndef MATHS_H
#define MATHS_H

extern float PI;

template<typename T>
T to_radians(T degrees)
{
	return degrees * PI / 180;
}

template<typename T>
T to_degrees(T radians)
{
	return radians * 180 / PI;
}

template<typename T>
T sign(T val)
{
	return (T(0) < val) - (val < T(0));
}

#endif /* MATHS_H */