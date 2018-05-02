#include "string.h"

String::String(const char * str)
{
	this->lenght = strlen(str);

	this->m_stringRep = new char[lenght+1];
	for (int i = 0; i  <=lenght; i++)
		this->m_stringRep[i] = str[i];
	//this->m_stringRep[strlen(str)+1] = '/0';
}

String::String(size_t len, char s)
{
	this->lenght = len;

	this->m_stringRep = new char[lenght+1];
	for (int i = 0; i < len; i++)
		this->m_stringRep[i] = s;
	this->m_stringRep[len] = '\0';
}

String::String(size_t len)
{
	this->lenght = len;

	this->m_stringRep = new char[lenght+1];
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

	for (int i = pos+1; i < lenght; i++)
		tmp[i] = this->m_stringRep[i-1];
	
	this->m_stringRep = tmp;

	return *this;
}

String & String::DelCharAt(size_t pos)
{
	for (int i = pos;i < lenght;i++)
		this->m_stringRep[i] = this->m_stringRep[i + 1];
	this->lenght -= 1;

	return *this;
}

String & String::ConcatStr(const String & str)
{

}

void String::operator()(const char * str)
{
	for (int i = 0; i < strlen(str);i++)
		this->m_stringRep [i]= str[i];
}
