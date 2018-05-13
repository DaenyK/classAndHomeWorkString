#include "string.h"

/*void main2()
{
	/*String s("hello");
	cout << s.getStrRep() << endl;

	String s1(5, 'a');
	cout << s1.getStrRep() << endl;

	s1.getAt(0) = 'z';
	cout << s1.getStrRep() << endl;

	s1.AddCharAt(2, 'q');
	cout << s1.getStrRep() << endl;

	s1.DelCharAt(0);
	cout << s1.getStrRep() << endl;

	String s7("hello");
	String s8("world");
	s7 = s8;
	cout << s7.getStrRep() << endl;

	/*s7.ConcatStr(s8);
	cout << s7.getStrRep() << endl;

	s7.ConcatStr("howareyou");
	cout << s7.getStrRep() << endl;
	s7 + s8;
	s7 + "helllo";

	s7.AddStrAt(s8, 2);


	s7.AddStrAt("wakawaka", 2);
	cout << s7.getStrRep() << endl;

	double d;

	auto str = to_string(42.5);

	system("pause");
}*/

void main()
{
	setlocale(LC_ALL, "Rus");
	short nz, answer;
	do
	{
		cout << "выберите задание:" << endl
			<< "1 -  удаление диапазона символов с beg до end" << endl
			<< "2 - поиск подстроки what  в вызывающем объекте. Результат – позиция первого вхождения\n";
		cout << "3 - поиск подстроки 2-ым способом(char)\n";
		cout << "4 - в вызывающей строке заменяются все вхождения what на rep" << endl
			<< "5 - замена 2-ым способом(char)\n0 - для выхода\n";

		cin >> nz;
		system("cls");

		switch (nz)
		{
		case 1:
		{
			int start, end;
			cout << "введите начало диапазона: "; cin >> start;
			cout << "введите конец диапазона: "; cin >> end;
			String s("helloworld");
			cout << s.getStrRep() << endl;

			s.DelStrAt(start, end);
			cout << s.getStrRep() << endl;
		}break;

		case 2:
		{
			String s("helloworld");
			String what("owo");
			cout << "даны строка: " << s.getStrRep() << " и подстрока: " << what.getStrRep() << endl;
			int result = s.SubStr(what);
			cout << "Результат – позиция первого вхождения: " << result << endl;
		}break;

		case 3:
		{
			String s("helloworld");
			char* what = "rld";
			cout << "даны строка: " << s.getStrRep() << " и подстрока: " << what << endl;
			int result = s.SubStr(what);
			cout << "Результат – позиция первого вхождения: " << result << endl;
		}break;

		case 4:
		{
			String s("helloworld");
			String what("hello");
			String rep("yellow");
			cout << "даны строка: " << s.getStrRep() << " и подстрока: " << what.getStrRep() << endl
				<< "которая будет заменена на подстроку: " << rep.getStrRep() << endl;
			s.Replace(what, rep);
			cout << "Результат: " << s.getStrRep() << endl;
			//все работает, только при завершении компиляции выдает ошибку на счет памяти
		}break;

		case 5:
		{
			String s("helloworld");
			char*what = "hello";
			char*rep = "yellow";
			cout << "даны строка: " << s.getStrRep() << " и подстрока: " << what << endl
				<< "которая будет заменена на подстроку: " << rep << endl;
			s.Replace(what, rep);
			cout << "Результат: " << s.getStrRep() << endl;
		}break;
		}

		cout << endl;
		cout << "хотите продолжить?1/0 ";
		cin >> answer;
		system("cls");
	} while (answer != 0);
	system("pause");

}