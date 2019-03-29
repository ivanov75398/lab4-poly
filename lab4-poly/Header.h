#pragma once

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Mono {
	double koef;	//коэффициент
	int sv;		//свертка степеней
public:
	Mono(int stX = 1, int stY = 1, int stZ = 1, double _koef = 1);
	bool operator==(const Mono &b);
	Mono & operator=(const Mono &b);
	bool operator>(const Mono &b);
	bool operator<(const Mono &b);
	void setKoef(double _koef) { koef = _koef; }
	double getKoef(void) { return koef; }
	friend ostream & operator<<(ostream &os, const Mono &b)
	{
		cout << b.koef << "/" << b.sv << "   /   " << endl;
		return os;
	}
	void setSvert(int _sv) { sv = _sv; }
	int getSvert(void) { return sv; }
};

struct Link {
	Link *n;
	Mono val;
};

class List {
	Link *h;
public:
	List() { h = NULL; }
	List(const List &b);
	~List();
	void insert(Mono monom);
	void insertLast(Mono monom);
	Mono del();
	int getSize();
	List operator+(const List &b);
	List operator-(const List &b);
	List operator*(const List &b);
	void show();
};

List* convert(string s);