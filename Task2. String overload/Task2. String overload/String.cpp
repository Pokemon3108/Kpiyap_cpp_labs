#include "pch.h"
#include "String.h"

String::String(const char * string)
{
	str = new char[strlen(string) + 1];
	for (unsigned int i = 0; i <= strlen(string); ++i)
		str[i] = string[i];
}

std::istream& operator>>(std::istream& s, String& string)
{
    rewind(stdin);
    char c;
	s.get(c);
    s.putback(c);
	size_t size = s.rdbuf()->in_avail();
	String temp(size);
	s.getline(temp.str, size);
	string = temp;
	return s;
}

std::ostream& operator<<(std::ostream& s, String& string)
{
	for (unsigned int i = 0; i < strlen(string.str); ++i)
		putchar(string[i]);
	return s;
}

char& String::operator[](int n)
{
	return str[n];
}

String String::operator()(int start, int end)
{
	String temp(end - start + 2);
	strncpy(temp.str, str + start, end - start+1);
	temp.str[end - start + 1] = '\0';
	return temp;
}  

bool String::operator==(const String& string) const
{
	return (!strcmp(str, string.str));
}

bool String::operator==(const char* const_string) const
{
	return (!strcmp(str, const_string));
}


bool operator==(const char * const_string, const String& string)
{
	return (!strcmp(const_string, string.str));
}

bool String::operator!=(const String& string) const
{
	return (strcmp(str, string.str));
}

bool String::operator!=(const char* const_string) const
{
	return (strcmp(str, const_string));
}

bool operator!=(const char* const_string, const String& string)
{
	return (strcmp(const_string, string.str));
}

bool String::operator > (const String& string) const
{
	return (strcmp(str, string.str) > 0) ? true : false;
}

bool String::operator > (const char* const_string) const
{
	return (strcmp(str, const_string) > 0) ? true : false;
}

bool operator>(const char* const_string, const String& string)
{
	return (strcmp(const_string, string.str) > 0) ? true : false;
}

bool String::operator < (const String& string) const
{
	return (strcmp(str, string.str) < 0) ? true : false;
}

bool String::operator<(const char* const_string) const
{
	return (strcmp(str, const_string) < 0) ? true : false;
}


bool operator < (const char* const_string, const String& string)
{
	return (strcmp(const_string, string.str) < 0) ? true : false;
}

String String::operator+(String& string) const
{
	String temp(strlen(string.str)+strlen(str)+2);
	strcat(temp.str, str);
	strcat(temp.str, string.str);
	return temp;
}

String String::operator+(const char* const_string) const
{
	String temp(const_string);
	return (str + temp);
}


String operator+(const char* const_string, String& string)
{
	String temp(const_string);
	return (temp + string);
	
}


String& String::operator=(String string) 
{
	delete[]str;
	str = new char[strlen(string.str) + 1];
	for (unsigned int i = 0; i < strlen(string.str)+1; ++i)
		str[i] = string[i];
	return *this;
}

String& String::operator=(const char* const_string)
{
	String temp(const_string);
	*this = temp;
	return *this;
}

String& String::operator+=(String& string)
{
	*this = *this + string;
	return *this;
}

String& String::operator+=(const char* const_string)
{
	*this = *this + const_string;
	return *this;
}

String& String::operator++()
{
	for (unsigned int i = 0; i < strlen(str); ++i) str[i]++;
	return *this;
}

String& String::operator--()
{
	for (unsigned int i = 0; i < strlen(str); ++i) str[i]--;
	return *this;
}

String String::operator++(int)
{
	String temp=*this;
	++(*this);
	return temp;
}

String  String::operator--(int)
{
	String temp = *this;
	--(*this);
	return temp;
}

