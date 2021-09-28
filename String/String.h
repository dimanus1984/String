//#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
protected:
	char* str;	// Указатель на строку в динамической памяти.
	unsigned int size;	// Размер строки в байтах.
public:
	const char* get_str()const;
	char* get_str();
	int get_size()const;

	//			Constructors:
	explicit String(unsigned int size = 80);	// Default constructor.
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//			Operators:
	String& operator=(const String& other);	// Оператор присваивания.
	String& operator=(String&& other);

	void clear();	// Очистка строки.

	String& operator+=(const String& other);	// Конкатенация оператор+=

	friend bool operator==(const String& left, const String& right);	// Проверка на равенство.
	friend bool operator!= (const String& left, const String& right);	// Проверка на неравенство.

	const char& operator[](int i)const;
	char& operator[](int i);

	//			Methods:
	void print()const;
};

String operator+(const String& left, const String& right);

ostream& operator<<(ostream& os, const String& obj);