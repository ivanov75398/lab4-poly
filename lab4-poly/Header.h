#pragma once

#include <iostream>
#include <string>

class Mono {
	int koe;	//коэффициент
	int sv;		//свертка степеней
public:
	Mono() { koe = 0; sv = 0; }
	Mono(int _koe, int _sv) { koe = _koe; sv = _sv; }
	//Mono(const Mono &b) { koe = b.koe; sv = b.sv; }
	Mono operator + (const Mono &b) { koe += b.koe; sv += b.sv; }
	Mono operator - (const Mono &b) { koe -= b.koe; sv -= b.sv; }
};

struct Link {
	Link *n;
	Mono *val;
};

class Poly {
	Link *h;
public:
	Poly() { h == NULL; }
	void insertTOP(Mono m);		//вставить в начало
	void insertIND(int ind);	//вставить ind-ое место
	Poly &convert(char * str);
};