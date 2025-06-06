#include "menu.h"

#include <iostream>
#include <string>
using namespace std;

void showMenu(Stack*& top) {	
	int m = 0, direction = 0;
	string str, filename;	
	do
	{			
		system("pause");
		system("cls");
		output_menu(0);
		cin >> str;
		cin.ignore();
		if (check(str)) {
			m = stoi(str);
			switch (m) {
			case 1: {
				addPatient(top);
			} break;
			case 2: {
				printTab(top);				
			} break;
			case 3: {
				input_filename(filename, m);
				ofstream db = new_DB(filename);
				if (!db) {
					error_create();
				}
			} break;
			case 4: {
				input_filename(filename, m);
				remove_DB(filename);
			} break;
			case 5: {
				input_filename(filename, m);
				cin.ignore();
				save_DB(filename, top);
			} break;
			case 6: {
				input_filename(filename, m);
				cin.ignore();
				load_DB(filename, top);
			} break;
			case 7: {
				int pos;
				input_toDelete(pos);
				editPatient(top, pos);
			} break;
			case 8: {
				int pos;
				input_toDelete(pos);
				deletePatient(top, pos);
			} break;
			case 9: {
				sort(top);
			} break;
			case 10: {
				filterPatients(top);
			} break;
			case 11: {
				searchPatient(top);
			} break;
			case 12: {
				extra_task(top);
			} break;
			case 13: {
				break;
			}
			}
		}
		else error_choice();
	} while (!check(str) || m != 13);
	clear(top);	
}