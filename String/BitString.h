#pragma warning(disable : 4996)
#pragma once
#include "String.h"
class BitString : public String
{
public:
	BitString();			// ����������� ��� ����������.
	BitString(char* str);	// �����������, ����������� � �������� ��������� �-������.
	BitString(BitString& other);	// ����������� �����������.
	~BitString();
	const BitString& operator=(const BitString& b);
	const BitString operator+(const BitString& b);
	bool operator==(const BitString& b);
	void print();
};