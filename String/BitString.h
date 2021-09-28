#pragma warning(disable : 4996)
#pragma once
#include "String.h"
class BitString : public String
{
public:
	BitString();			// Конструктор без параметров.
	BitString(char* str);	// Конструктор, принимающий в качестве параметра С-строку.
	BitString(BitString& other);	// Конструктор копирования.
	~BitString();
	const BitString& operator=(const BitString& b);
	const BitString operator+(const BitString& b);
	bool operator==(const BitString& b);
	void print();
};