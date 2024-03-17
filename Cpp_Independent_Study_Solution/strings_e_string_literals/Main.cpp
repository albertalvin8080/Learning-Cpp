#include <iostream>
#include <string>
#define LOG(x) std::cout << x << std::endl;

using String = std::string;

// cria um loop infinito onde 'os' chama o overload de << para str[]
//std::ostream& operator<<(std::ostream& os, const char str[]) {
//	os << str;
//	return os;
//}

// more than one operator matchs these operands
//static void operator += (std::string& str, const char* c_str) {
//	str.append(c_str).append(" success");
//}

// nonmember operator requires a parameter with class or enum type
//static std::string operator+(const char* c1, const char* c2) {
//	return std::string(c1) + c2;
//}

void replaceAllOccurences(std::string& str, char find, char replace) {
	for (char& c : str) {
		if (c == find) {
			c = replace;
		}
	}
}

int main() {

	std::string str1;
	str1.assign("Ola");
	LOG(str1);

	std::string str2 = str1 + " concatenando";
	LOG(str2);

	const char str3[] = "str_literal";
	LOG(str3);

	//using namespace std::string_literals;
	//std::string str4 = "char"s + "char"s;

	const char* str5 = R"(Raw string start
Linha1\n
Linha2
end.)";
	LOG(str5);

	const char16_t* c16 = u"olá abençoado";
	LOG(c16);

	const char32_t* c32 = U"olá abençoado";
	LOG(c32);

	std::locale::global(std::locale("pt-br"));

	LOG(sizeof(wchar_t));
	const wchar_t* wchar = L"olá abençoado";
	std::wcout.imbue(std::locale());
	std::wcout << wchar << std::endl;

	std::cout.imbue(std::locale());
	std::cout << "olá baçamba" << std::endl;

	std::string str6("summa blasphemia");
	LOG("before: " + str6);
	replaceAllOccurences(str6, 'a', 'C');
	LOG("after: " + str6);

	LOG(std::string("teste").compare("t"));

	String str7("testando_replace");
	// Off = indice do primeiro caractere a suvstituir
	// Nx = quantos caracteres remover (contando com Off)
	// std = string substituta
	str7.replace(5, 2, String("00"));
	LOG(str7);

	String str8("novo_teste");
	str8.replace(5, 1, 2, '0');
	LOG(str8);

	extern int variavel; // procure externamente
	LOG("variavel " + variavel);

	//LOG("c_1" + "c_2");
	std::string str9("olá");
	str9 += "c_2";
	LOG(str9);

	#include "MyClass.h"
	MyClass myClass(9);
	myClass.getNum();
	myClass.getNum();
	myClass.getNum();
	myClass.getNum();

	LOG(myClass.debug);

	return EXIT_SUCCESS;
}

