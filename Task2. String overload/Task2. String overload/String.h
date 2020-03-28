#pragma once

class String
{
private:
	char* str;
	
public:
	String(): str(nullptr)
	{ }
	
	String(int length)
	{
		str = new char[length + 1];
	    *str='\0';
	}
	String(const String& obj)
	{
		str = new char[strlen(obj.str)+1] {};
		for (unsigned int i = 0; i < strlen(obj.str); ++i)
			str[i] = obj.str[i];
	}
	String(const char*string);

	~String()
	{
		delete[] str;
	}

	friend std::istream& operator >> (std::istream&s, String& string) ;
	friend std::ostream& operator << (std::ostream&s, String& string) ;

	char& operator [] (int n);
	String operator() (int start, int end);

    bool operator == (const String& string) const;
	bool operator == (const char* const_string) const;
	friend bool operator == (const char* const_string, const String& string);

	bool operator != (const String& string) const;
	bool operator != (const char* const_string) const;
	friend bool operator != (const char* const_string, const String& string);

	bool operator > (const String& string) const;
	bool operator > (const char* const_string) const;
	friend bool operator > (const char* const_string, const String& string);

	bool operator < (const String& string) const;
	bool operator < (const char* const_string) const;
	friend bool operator < (const char* const_string, const String& string);

	String operator + (String& string) const;
	String operator + (const char* const_string) const;
	friend String operator + (const char* const_string, String& string);

    String& operator = (String string);
	String& operator = (const char* const_string);

	String& operator += (String& string);
	String& operator += (const char* const_string);

	String& operator ++ ();
	String& operator -- ();
	String operator ++ (int);
	String operator --(int);

	
};



