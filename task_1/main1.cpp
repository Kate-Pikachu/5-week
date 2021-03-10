#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <locale>
#include <sstream>

#include <Windows.h> 


void show_currency_symbol(const std::string& locale_name) {
	std::cout << locale_name << " : " <<
		std::use_facet < std::moneypunct < char, false > >(
			std::locale(locale_name)).curr_symbol() << std::endl;
}

int main(int argc, char* argv) {

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int mon = 1227;


	std::ostringstream sout;
	sout.imbue(std::locale("ru_RU.utf8"));
	sout << std::showbase << std::put_money(mon, false) << std::endl;
	std::cout << sout.str() << std::endl;


	std::ostringstream ssout;
	ssout.imbue(std::locale("de_DE.utf8"));
	ssout << std::showbase << std::put_money(mon, false) << std::endl;
	std::cout << ssout.str() << std::endl;


	system("pause");
	return EXIT_SUCCESS;
}