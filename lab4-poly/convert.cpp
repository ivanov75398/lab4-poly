#include "Header.h"

List* convert(string s)
{
	List* result;
	result = new List;
	int size = s.size();
	double kof = 0.0;
	int x, y, z, i, st;
	x = 0;
	y = 0;
	z = 0;
	i = 0;
	st = 0;
	string temp = "";
	s += '+';
	if (s[i] == '+')
	{
		temp += s[i];
		i++;
	}
	if (s[i] == '+')
	{
		temp += s[i];
		i++;
	}
	while (i < size)
	{
		if (st == 0)
		{
			kof = atof(temp.c_str());
		}
		if (st == 1) // степень x
		{
			x = atoi(temp.c_str());
		}
		if (st == 2) // степень y
		{
			y = atoi(temp.c_str());
		}
		if (st == 3) // степень z
		{
			z = atoi(temp.c_str());
		}
		if ((s[i] == '+') || (s[i] == '-')) // добавляем моном
		{
			Mono newMono(x, y, z, kof);
			(*result).insertLast(newMono);
			temp = s[i];
			x = y = z = 0;
			kof = 0.0;
			st = 0;
			continue;
		}
		if (s[i] == 'x')
		{
			temp = "";
			st = 1;
			i++;
			continue;
		}
		if (s[i] == 'y')
		{
			temp = "";
			st = 2;
			i++;
			continue;
		}
		if (s[i] == 'z')
		{
			temp = "";
			st = 3;
			i++;
			continue;
		}
		temp += s[i];
		i++;
	}
	return result;
}