#include "Header.h"

int pos(char *s, char c)
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c) return i;
		i++;
	}
	return -1;
}

Poly &Poly::convert(char * str) 
{
	std::string s;
	char c;
	int i = 0;
	char op[] = "+-";
	char neiz[] = "xyz";
	while (str[i] != '\0')
	{
		while (str[i] != neiz)
		{
			s += c;
		}
	}
}

void Poly::insertTOP(Mono m)
{
	Link *p = new Link;
	p->n = h;
	h = p;
}

void Poly::insertIND(int ind)
{
	int index = 0;
	Link *p = new Link;
	Link *k;
	while ((index != ind - 1) && (k->n != NULL))
	{
		k = k->n;
	}
	p->n = k->n;
	k->n = p;
}