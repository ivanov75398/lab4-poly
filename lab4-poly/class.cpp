#include "Header.h"

Mono::Mono(int stX, int stY, int stZ, double _koef)
{
	koef = _koef;
	if ((stX<0)||(stX>20)||(stY<0)||(stY>20)||(stZ<0)||(stZ>20))
	{
		throw - 1;
	}
	sv = 400 * stX + 20 * stY + stZ;
}

bool Mono::operator==(const Mono &b)
{
	return (sv == b.sv);
}

Mono & Mono::operator=(const Mono &b)
{
	koef = b.koef;
	sv = b.sv;
	return *this;
}

bool Mono::operator>(const Mono &b)
{
	return (sv > b.sv);
}

bool Mono::operator<(const Mono &b)
{
	return (sv < b.sv);
}

List::List(const List &b)
{
	if (b.h == NULL) { throw - 1; }
	Link * p;
	p = b.h;
	while (p != NULL)
	{
		this->insert(p->val);
		p = p->n;
	}
}

List::~List()
{
	while (h != NULL)
	{
		del();
	}
}

Mono List::del()
{
	if (h == NULL)
	{
		return NULL;
	}
	Mono M;
	Link *p;
	p = h;
	M = p->val;
	h = h->n;
	delete p;
	return M;
}

void List::insert(Mono monom)
{
	Link * p;
	p = new Link;
	p->val = monom;
	p->n = h;
	h = p;
}

void List::insertLast(Mono monom)
{
	Link * p;
	p = new Link;
	p->val = monom;
	p->n = NULL;
	Link * t;
	if (h == NULL)
	{
		h = p;
		return;
	}
	t = h;
	while (t->n != NULL)
	{
		t = t->n;
	}
	t->n = p;
}

int List::getSize()
{
	Link *p;
	int size = 0;
	p = h;
	while (h != NULL)
	{
		size++;
		p = p->n;
	}
	return size;
}

List List::operator+(const List &b)
{
	List res;
	Link *p1;
	Link *p2;
	p1 = h;
	p2 = b.h;
	while ((p1 != NULL) && (p2 != NULL))
	{
		if (p1->val > p2->val)
		{
			res.insertLast(p2->val);
			p2 = p2->n;
			continue;
		}
		if (p1->val < p2->val)
		{
			res.insertLast(p1->val);
			p1 = p1->n;
			continue;
		}
		else    //иначе равны
		{
			double newkoef;
			int svertka;
			svertka = p1->val.getSvert();
			newkoef = p1->val.getKoef() + p2->val.getKoef();			
			if (newkoef == 0.0)
			{
				p1 = p1->n;
				p2 = p2->n;
				continue;
			}
			Mono newMonon;
			newMonon.setKoef(newkoef);
			newMonon.setSvert(svertka);
			res.insertLast(newMonon);
			p1 = p1->n;
			p2 = p2->n;
			continue;
		}
	}
	while (p1 != NULL)
	{
		res.insertLast(p1->val);
		p1 = p1->n;
		continue;
	}
	while (p2 != NULL)
	{
		res.insertLast(p2->val);
		p2 = p2->n;
		continue;
	}
	return res;
}

List List::operator-(const List &b)
{
	List res;
	Link *p1;
	Link *p2;
	p1 = h;
	p2 = b.h;
	while ((p1 != NULL) && (p2 != NULL))
	{
		if (p1->val > p2->val)
		{
			res.insertLast(p2->val);
			p2 = p2->n;
			continue;
		}
		if (p1->val < p2->val)
		{
			res.insertLast(p1->val);
			p1 = p1->n;
			continue;
		}
		else    //иначе равны
		{
			double newkoef;
			int svertka;
			svertka = p1->val.getSvert();
			newkoef = p1->val.getKoef() - p2->val.getKoef();
			if (newkoef == 0.0)
			{
				p1 = p1->n;
				p2 = p2->n;
				continue;
			}
			Mono newMonon;
			newMonon.setKoef(newkoef);
			newMonon.setSvert(svertka);
			res.insertLast(newMonon);
			p1 = p1->n;
			p2 = p2->n;
			continue;
		}
	}
	while (p1 != NULL)
	{
		res.insertLast(p1->val);
		p1 = p1->n;
		continue;
	}
	while (p2 != NULL)
	{
		res.insertLast(p2->val);
		p2 = p2->n;
		continue;
	}
	return res;
}

List List::operator*(const List &b)
{
	List res;
	Link *p1;
	Link *p2;
	p1 = h;
	p2 = b.h;
	while ((p1 != NULL) && (p2 != NULL))
	{
		while (p2 != NULL)
		{
			double newkoef;
			int svertka;
			svertka = p1->val.getSvert() + p2->val.getSvert();
			newkoef = p1->val.getKoef() * p2->val.getKoef();
			Mono newMonon;
			newMonon.setKoef(newkoef);
			newMonon.setSvert(svertka);
			res.insertLast(newMonon);
			p2 = p2->n;
			cout << newMonon << endl;
		}
		p1 = p1->n;
		p2 = b.h;
	}
	return res;
}

void List::show()
{
	Link *p;
	p = h;
	while (p != NULL)
	{
		cout << p->val << endl;
		p = p->n;
	}
}