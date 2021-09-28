#include<iostream>
#include"String.h"
#include"BitString.h"
using namespace std;

#define delimiter "\n----------------------------------------------------\n"
#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define CONCATENATION
//#define BITSTRING

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str("test");
	str.print();

	String str2(5);
	str2.print();

	cout << typeid("Hello").name() << endl;
	String str3 = "Hello";
	str3.print();
	cout << str3 << endl;

	String str4 = str3;	//CopyConstructor
	cout << "Str4 - " << str4 << endl;

	String str5;
	str5 = str4;
	cout << "Str5 - " << str5 << endl;

	cout << delimiter << endl;
	cout << (str2 == str3) << endl;
	cout << (str == "test") << endl;
	cout << ("abc" == str3) << endl;
	cout << delimiter << endl;
	
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;
#endif // ASSIGNMENT_CHECK

#ifdef CONCATENATION
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3;
	str3 = str1 + str2;//Оператор + будет выполнять конкатенацию (слияние) строк
	cout << delimiter << endl;
	cout << str3 << endl;
	cout << delimiter << endl;
	str1 += str2;
	cout << str1 << endl;
	cout << delimiter << endl;
#endif // CONCATENATION

#ifdef BITSTRING
	BitString s1;
	s1.print();
	BitString s2("0101");
	BitString s2;
	s2.print();
	BitString s3(s2);
	s3.print();
	BitString s4('k');
	s4.print();
#endif // BITSTRING

}