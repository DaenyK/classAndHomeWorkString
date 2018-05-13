#include "string.h"

String::String(const char * str)
{
	this->lenght = strlen(str);

	this->m_stringRep = new char[lenght + 1];
	for (int i = 0; i <= lenght; i++)
		this->m_stringRep[i] = str[i];
	//this->m_stringRep[strlen(str)+1] = '/0';
}

String::String(size_t len, char s)
{
	this->lenght = len;

	this->m_stringRep = new char[lenght + 1];
	for (int i = 0; i < len; i++)
		this->m_stringRep[i] = s;
	this->m_stringRep[len] = '\0';
}

String::String(size_t len)
{
	this->lenght = len;

	this->m_stringRep = new char[lenght + 1];
	this->m_stringRep[len] = '\0';
}

const char * String::getStrRep()
{
	return m_stringRep;
}

char & String::getAt(size_t pos)
{
	return m_stringRep[pos];
}

String & String::AddCharAt(size_t pos, char c)
{
	char * tmp;
	this->lenght += 2;
	tmp = new char[lenght];

	for (int i = 0; i < pos; i++)
		tmp[i] = this->m_stringRep[i];
	tmp[pos] = c;

	for (int i = pos + 1; i < lenght; i++)
		tmp[i] = this->m_stringRep[i - 1];

	this->m_stringRep = tmp;

	return *this;
}

String & String::DelCharAt(size_t pos)
{
	for (int i = pos; i < lenght; i++)
		this->m_stringRep[i] = this->m_stringRep[i + 1];
	this->lenght -= 1;

	return *this;
}

String & String::ConcatStr(const String & str)
{
	char *tmp;
	int tmp_lenght = this->lenght + str.lenght;
	tmp = new char[tmp_lenght + 1];

	for (int i = 0; i < this->lenght; i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = 0; i < str.lenght; i++)
		tmp[i + lenght] = str.m_stringRep[i];

	tmp[tmp_lenght] = '\0';
	delete[]this->m_stringRep;
	this->m_stringRep = tmp;
	this->lenght = tmp_lenght;
	return *this;

}

String & String::ConcatStr(const char * str)
{
	int tmp_lenght = this->lenght + strlen(str);
	char *tmp = new char[tmp_lenght + 1];

	for (int i = 0; i < this->lenght; i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = 0; i < strlen(str); i++)
		tmp[i + lenght] = str[i];

	tmp[tmp_lenght] = '\0';
	delete[]this->m_stringRep;
	this->m_stringRep = tmp;
	this->lenght = tmp_lenght;
	return *this;

}

void String::operator()(const char * str)
{
	for (int i = 0; i < strlen(str); i++)
		this->m_stringRep[i] = str[i];
}//оператор круглых скобок

String & String::operator=(const String & str)
{
	char*tmp;
	this->lenght = str.lenght;
	tmp = new char[this->lenght];
	for (int i = 0; i < lenght; i++)
		tmp[i] = str.m_stringRep[i];
	tmp[lenght] = '\0';
	delete[]this->m_stringRep;
	m_stringRep = tmp;
	return *this;
}

String & String::operator+(const char * str)
{
	ConcatStr(str);
	return *this;
}

String & String::operator+(const String & str)
{
	ConcatStr(str);
	return *this;
}

String & String::AddStrAt(const String & str, size_t pos)
{
	int tmp_lenght = lenght + str.lenght;
	char *tmp = new char[tmp_lenght + 1];
	tmp[tmp_lenght] = '\0';
	for (int i = 0; i < pos; i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = 0; i < str.lenght; i++)
		tmp[pos + i] = str.m_stringRep[i];
	for (int i = pos; i < this->lenght; i++)
		tmp[i + str.lenght] = this->m_stringRep[i];
	delete[]this->m_stringRep;
	this->m_stringRep = tmp;
	this->lenght = tmp_lenght;
	return *this;
}

String & String::AddStrAt(const char * str, size_t pos)
{
	int tmp_lenght = lenght + strlen(str);
	char *tmp = new char[tmp_lenght + 1];
	tmp[tmp_lenght] = '\0';
	for (int i = 0; i < pos; i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = 0; i < strlen(str); i++)
		tmp[pos + i] = str[i];
	for (int i = pos; i < this->lenght; i++)
		tmp[i + strlen(str)] = this->m_stringRep[i];
	delete[]this->m_stringRep;
	this->m_stringRep = tmp;
	this->lenght = tmp_lenght;
	return *this;
}

String & String::DelStrAt(size_t beg, size_t end)
{
	int j = 0;
	for (int i = beg; i < this->lenght; i++)
	{
		this->m_stringRep[beg + j] = this->m_stringRep[end + 1 + j];
		j++;
	}
	this->lenght -= (end - beg + 1);

	return *this;
}

size_t String::SubStr(const String & what)
{
	int a, w = 0;
	for (int i = 0; i < this->lenght; i++)
	{
		if (this->m_stringRep[i] == what.m_stringRep[w])
		{
			w++;
			if (w == what.lenght)
				a = i - w + 1;
		}
	}
	return a;
}

size_t String::SubStr(const char * what)
{
	int a, w = 0;
	for (int i = 0; i < this->lenght; i++)
	{
		if (this->m_stringRep[i] == what[w])
		{
			w++;
			if (w == strlen(what))
				a = i - w + 1;
		}
	}
	return a;
}

String & String::Replace(const String & what, const String & rep)
{
	int beg, w = 0;

	for (int i = 0; i < this->lenght; i++)
	{
		if (this->m_stringRep[i] == what.m_stringRep[w])
		{
			w++;
			if (w == what.lenght)
				beg = i - w + 1;
		}
	}//проверка на правильность подстроки
	
	char *tmp; int tmpLen;
	tmpLen = this->lenght + (rep.lenght - what.lenght);
	tmp = new char[tmpLen];
	w = 0;
	for (int i = 0; i < beg; i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = beg; i < rep.lenght+beg; i++)
		tmp[i] = rep.m_stringRep[i-beg];
	int j = beg + what.lenght;
	for (int i = beg+rep.lenght; i < tmpLen; i++)
		tmp[i] = this->m_stringRep[j++];

	tmp[tmpLen] = '\0';
	delete[]this->m_stringRep;
	this->lenght = tmpLen;
	this->m_stringRep = tmp;
	return *this;
}

String & String::Replace(const char * what, const char * rep)
{
	int beg, w = 0;

	for (int i = 0; i < this->lenght; i++)
	{
		if (this->m_stringRep[i] == what[w])
		{
			w++;
			if (w == strlen(what))
				beg = i - w + 1;
		}
	}//проверка на правильность подстроки

	char *tmp; int tmpLen;
	tmpLen = this->lenght + (strlen(rep )- strlen(what));
	tmp = new char[tmpLen];
	w = 0;
	for (int i = 0; i < beg; i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = beg; i < strlen(rep) + beg; i++)
		tmp[i] = rep[i - beg];
	int j = beg + strlen(what);
	for (int i = beg + strlen(rep); i < tmpLen; i++)
		tmp[i] = this->m_stringRep[j++];

	tmp[tmpLen] = '\0';
	delete[]this->m_stringRep;
	this->lenght = tmpLen;
	this->m_stringRep = tmp;
	return *this;
}

//String String::Format(const char * specs, ...)
//{
//	{
//		int ival;
//		double dval;
//
//		va_list ap; 									//Указатель на список параметров
//		va_start(ap, format);						 	//Настроились на список параметров
//		for (char *p = format;*p;p++) 					//
//		{
//			if (*p == '%') 									//Если встретится символ %
//			{
//				switch (*++p) 								//То анализируем следующий за этим симолом символ
//				{
//				case 'd':  ival = va_arg(ap, int); 			//Если это символ d, то значит параметр int
//					cout << ival << " ";break; 					//Выводим параметр типа int на экран
//				case 'f':  dval = va_arg(ap, double); 		//Если это символ f значит параметр double
//					cout << dval << " ";break; 					//Выводим параметр типа double на экран
//				}
//			}
//			else cout << *p << " ";
//		}
//		va_end(ap);
//}

