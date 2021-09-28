#include "BitString.h"

BitString::BitString()  // Конструктор без параметров.
{
	//String();
	str = NULL;
	size = 0;
}

BitString::BitString(char* str) :String(str) // Конструктор, принимающий в качестве параметра С-строку.
{
	int i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != '0') && (str[i] != '1')) {
			str[0] = '\0';
			size = 0;
			break;
		}
		i++;
	}
	cout << "BitConstructor:\t\t" << this << endl;
}

BitString::BitString(BitString& other) :String(other)	// Конструктор копирования.
{
	str = new char;
	size = other.size;
	//strcpy(this->str, other.str);
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];	// Поэлементное, побайтовое копирование.
	cout << "BitCopyConstructor:\t" << this << endl;
}

BitString::~BitString()
{
	String::~String();
	cout << "BitDestructor:\t\t" << this << endl;
}

const BitString& BitString::operator=(const BitString& b)
{
	if (str) free(str);
	if (b.str)
	{
		str = strdup(b.str);
		size = b.size;
	}
	else
	{
		str = NULL;
		size = 0;
	}
	return b;
}

const BitString BitString::operator+(const BitString& b)
{
	int m, p = 0, a1, a2;
	if (size > b.size) m = size; else m = b.size;
	char* r = new char[m + 1];
	memset(r, '0', m);
	r[m] = 0;
	int n1 = size - 1, n2 = b.size - 1;
	for (int n = m - 1; n >= 0; n--)
	{
		if (n1 >= 0) a1 = str[n1] - '0';
		else a1 = 0;
		if (n2 >= 0) a2 = b.str[n2] - '0';
		else a2 = 0;
		switch (a1 + a2 + p)
		{
		case 3:
			r[n] = 1;
			p = 2;
			break;
		case 2:
			r[n] = '0';
			p = 1;
			break;
		case 1:
			r[n] = '1';
			p = 0;
			break;
		case 0:
			r[n] = '0';
			p = 0;
			break;
		}
		n1--;
		n2--;
	}
	return r;
}

bool BitString::operator==(const BitString& b)
{
	int l;
	if (size > b.size) l = size; else l = b.size;
	int r = 1;;
	int n1 = size - 1, n2 = b.size - 1, k;
	k = l - 1;
	while (k >= 0)
	{

		if ((n1 >= 0) && (n2 >= 0) && (str[n1] != b.str[n2])) return 0;
		if ((n1 < 0) && (b.str[n2] != '0')) return 0;
		if ((n2 < 0) && (str[n1] != '0')) return 0;
		k--; n1--; n2--;
	}
	return 1;
}

void BitString::print()
{
	String::print();
}