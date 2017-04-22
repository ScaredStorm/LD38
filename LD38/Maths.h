#ifndef MATHS_H
#define MATHS_H

float PI = 3.14159265359f;

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

#endif /* GLOBALS_H */