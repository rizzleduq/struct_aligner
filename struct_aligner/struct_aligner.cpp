// struct_aligner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct data_size {
	string name_of_type;
	int size;
};

void pack_array_of_data_type_size(data_size arr[], int n) {
	arr[0].name_of_type = "int";
	arr[0].size = sizeof(int);
	arr[1].name_of_type = "double";
	arr[1].size = sizeof(double);
	arr[2].name_of_type = "float";
	arr[2].size = sizeof(float);
	arr[3].name_of_type = "bool";
	arr[3].size = sizeof(bool);
	arr[4].name_of_type = "char";
	arr[5].size = sizeof(char);
}

string check_type(string data_type, data_size arr[], int n) {
	bool b = false;
	int i;
	for (i = 0;i < n && !b;++i) {
		if (data_type == arr[i].name_of_type)
			b = true;
	}
	return arr[i].name_of_type;
}

// пока что одна структура с полями без массивов указателей и других структур
////////////////////////////////////////////////////////////////////
void parse_file(ifstream &in, ofstream &out, data_size arr[], int n) {
	int saved_memory = 0;

	// пропускаем: struct name {
	string waste;
	in >> waste >> waste >> waste;
	while (!in.eof()) {
		string data_type;
		in >> data_type;
		cout << check_type(data_type, arr, n) << endl;
		in >> waste;
		in >> data_type;
	}
	cout << "memory saving by alignment: " << saved_memory << '.' << endl;
}

int main()
{
	// заполняем массив структур с названиями типа данных и его обьема
	const int n = 5;
	data_size arr[n];
	pack_array_of_data_type_size(arr, n);

	ifstream in("a.txt");
	ofstream out("b.txt");
	cout << "size of pointer: " << sizeof(void*) << " bytes." << endl;


	cout << "please wait your structs are aligning..." << endl;
	parse_file(in, out, arr, n);

	in.close();
	out.close();
}