#pragma once
#include "headers.h"

class String
{
private:
	char *m_stringRep;
	size_t lenght;

public:
	String(const char* str);
	String(size_t len, char s);
	String(size_t len);

	const char * getStrRep();
	char & getAt(size_t pos);

	String& AddCharAt(size_t pos, char c);
	String& DelCharAt(size_t pos);

	String& ConcatStr(const String& str);
	String& ConcatStr(const char* str);
	void operator()(const char *str);

	String &operator=(const String& str);
	String &operator+ (const String& str);
	String &operator+ (const char *str);

	String& AddStrAt(const String& str, size_t pos);
	String& AddStrAt(const char* str, size_t pos);

	//static String Format(const char* specs, ...);


	String& DelStrAt(size_t beg, size_t end);
	size_t SubStr(const String& what);
	size_t SubStr(const char* what);
	String& Replace(const String& what, const String& rep);
	String& Replace(const char* what, const char* rep);

	~String() { delete[] m_stringRep; }
};



