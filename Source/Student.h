#pragma once
#include<fstream>
#include<string>
#include<iostream>
#include<iomanip>
#include"Date.h"

using namespace std;

struct Student {
	int id;
	string name;
	float gpa;
	string address;
	Date date;

	void InputConsole() {
		char str[42];
		cin >> id; cin.ignore();
		cin.get(str, 20, '\n');
		name = str;
		cin >> gpa; cin.ignore();
		cin.get(str, 40, '\n');
		address = str;
		date.InputConsole();
		return;
	}

	void OutputConsole() {
		cout << id << "\n" << name << "\n";
		cout << fixed << setprecision(2) << gpa << "\n";
		cout << address << "\n";
		date.OutputConsole();
		return;
	}

	void InputFile(ifstream& inp) {
		char str[42];
		inp >> id; inp.ignore();
		inp.get(str, 20, '\n');
		name = str;
		inp >> gpa; inp.ignore();
		inp.get(str, 40, '\n');
		address = str;
		date.InputFile(inp);
		return;
	}

	void OutputFile(ofstream& out) {
		out << id << "\n" << name << "\n";
		out << fixed << setprecision(2) << gpa << "\n";
		out << address << "\n";
		date.OutputFile(out);
		return;
	}
};

string FirstName(Student h);
string LastName(Student h);
void OutputClearly(ofstream& out, Student h);

int ExtractClass(Student h);

bool CompareId(Student a, Student b);
bool CompareGpaId(Student a, Student b);
bool CompareNameId(Student a, Student b);
bool CompareFirstId(Student a, Student b);
bool CompareLastId(Student a, Student b);
bool CompareDobId(Student a, Student b);