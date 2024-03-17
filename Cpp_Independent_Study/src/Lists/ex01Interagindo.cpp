/*
 * ex01Interagindo.cpp
 *
 *  Created on: 4 de set. de 2023
 *      Author: Albert
 */
#include <list>
#include <iostream>
using namespace std;

int mainasdsad() {
	list<string> *str_list = new list<string>;

	int op = 0;
	string str_temp;
	do {
		cout << "1 - Push back" << endl;
		cout << "2 - Push front" << endl;
		cout << "3 - Pop back" << endl;
		cout << "4 - Pop front" << endl;
		cout << "5 - Show List" << endl;
		cout << "0 - End" << endl;
		cin >> op;

		switch (op) {
		case 1:
			cout << "Insert string:" << endl;
			cin >> str_temp;
			str_list->push_back(str_temp);
			break;
		case 2:
			cout << "Insert string:" << endl;
			cin >> str_temp;
			str_list->push_front(str_temp);
			break;
		case 3:
			str_list->pop_back();
			break;
		case 4:
			str_list->pop_front();
			break;
		case 5:
			for(string const &item: *str_list) {
				cout << item << " ";
			}
			cout << endl;
			break;
		default:
			cout << "OPCAO INVALIDA" << endl;
		}

	} while (op != 0);

	delete str_list;
	return 0;
}

