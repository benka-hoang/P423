#include<iostream>
#include<iomanip>
#include<fstream>

#include"Date.h"
#include"Student.h"
#include"Course.h"

using namespace std;

int main() {
	ifstream inp("input.txt"); ofstream out("output.txt");
	Course A;
	A.InputFile(inp);
	A.OutputFile(out);
	cout << A.Num << "\n";
	cout << A.MinNumber << " " << A.MaxNumber << "\n";
	out << "------------------\n";

	Student x;
	x.InputFile(inp);
	A.AddStudent(x);
	A.OutputFile(out);

	int c = 19125095;
	A.DelStudent(c);
	out << "------------------\n";
	A.OutputFile(out);
	inp.close(); out.close();
	return 0;
}