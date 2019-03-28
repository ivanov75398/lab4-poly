#include "Header.h"

int main()
{
	Mono M1(2, 4, 6, 8.3);
	Mono M2(1, 4, 6, -9.7);
	List A, B, C;
	A.insert(M1);
	B.insert(M2);
	C = (A + B);
	C.show();

	string S1 = "3x^1+2x^2y^4-x^3+0.2y^1+23z^17";
	string S2 = "x^1+0.3y^2z^5+22z^2+33x^16z^1";
	List L1, L2, LRes;

	LRes = L1 + L2;
	LRes.show();
	cout << endl;

	LRes = L1 * L2;
	LRes.show();
	cout << endl;

	return 0;
}