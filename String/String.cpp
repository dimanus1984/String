#include "String.h"

const char* String::get_str()const
{
	return str;
}

char* String::get_str()
{
	return str;
}

int String::get_size()const
{
	return size;
}

//				Constructors:

String::String(unsigned int size)	// Default constructor.
{
	this->size = size;
	this->str = new char[size] {};
	cout << (size == 80 ? "Default" : "Size") << "Constructor:\t" << this << endl;
}

String::String(const char* str)
{
	this->size = strlen(str) + 1;	// Измеряю длину строки.
	this->str = new char[size] {};	// Выделяю память.
	//strcpy(this->str, str);		// String copy.
	//strcpy_s(this->str, size, str);
	for (int i = 0; str[i]; i++)	//Копируем, то что получили как параметр в нашу строку.
		this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}

String::String(const String& other)	// Конструктор копирования принимает константную ссылку на объект.
{
	this->size = other.size;
	this->str = new char[size] {};
	//strcpy(this->str, other.str);
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];	// Поэлементное, побайтовое копирование.
	cout << "CopyConstructor:\t" << this << endl;
}

String::String(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}

String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}

//			Operators:
String& String::operator=(const String& other)
{
	// 1) Проверяю, не является ли this и other одним и тем же объектом:
	if (this == &other)return *this;
	// 2) В первую очередь удавляю старое значение обекта, и только после этого присваиваю ему новое значение.
	delete[] this->str;
	// 3) Выполняю копирование:
	this->size = other.size;		// Копирую размер.
	this->str = new char[size] {};	// Выделяю память.
	//strcpy(this->str, other.str);
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}

String& String::operator=(String&& other)	// Этот объект на момент вызова уже занимает память.
{
	// Удаляю ту динамическую память, которую принимает сейчас.
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;	// Зануляю, чтобы конструктор его не удалил.
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}

void String::clear()	// Очистка строки.
{
	delete[] str;
	str = 0;
	size = 0;
}

String& String::operator+=(const String& other)	// Оператор '+=' перегружаю в классе потому-что он изменяет операнд слева.
{
	return *this = *this + other;
}

bool operator==(const String& left, const String& right)	// Проверка на равенство.
{
	return !static_cast<bool>(strcmp(left.str, right.str));
}

bool operator!=(const String& left, const String& right)	// Проверка на неравенство.
{
	return static_cast<bool>(strcmp(left.str, right.str));
}

// Оператор квадратные скобки '[]' возвращает указатель, значение по номеру или по индексу.
// Оператор квадратные скобки '[]' принимает индекс.
// Константный оператор квадратные скобки '[]' который возвращает константную ссылку.
const char& String::operator[](int i)const
{
	return this->str[i];
}

// Неконстантный оператор квадратные скобки '[]', который возвращает просто ссылку.
char& String::operator[](int i)
{
	return this->str[i];
}

//			Methods:
void String::print()const
{
	cout << "str:\t" << str << endl;
	cout << "size:\t" << size << endl;
}

// Оператор '+' перегружаю за классом, потому-что оператор '+' не должен изменять свои операнды.
String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);	// Size constructor.
	// result - локальный объект, он существует только в пределах функции operator+
	for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];
	//strcpy(result.get_str(), left.get_str());		// Выполняет копирование строки left в строку result.
	//strcat(result.get_str(), right.get_str());	// Выполняет конкатенацию строки right в строку result.
	return result;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}