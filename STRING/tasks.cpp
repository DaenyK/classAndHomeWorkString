#include "string.h"

void main()
{
	String s("hello");
	cout << s.getStrRep() << endl;

	String s1(5, 'a');
	cout << s1.getStrRep() << endl;

	s1.getAt(0) = 'z';
	cout << s1.getStrRep() << endl;

	s1.AddCharAt(2, 'q');
	cout << s1.getStrRep() << endl;

	s1.DelCharAt(0);
	cout << s1.getStrRep() << endl;


	system("pause");
}