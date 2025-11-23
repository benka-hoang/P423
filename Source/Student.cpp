#include "Student.h"
#include<string>
#include<math.h>

string FirstName(Student a) {
	string s = ""; string h = a.name;
	for (int i = 0; i < h.size() && h[i] != ' '; ++i)
		s.push_back(h[i]);
	return s;
}
string LastName(Student a){
	string s = ""; string h = a.name;
	for (int i = h.size() - 1; i >= 0 && h[i] != ' '; --i)
		s.push_back(h[i]);
	for (int i = 0; i < s.size() / 2; ++i)
		swap(s[i], s[s.size() - i - 1]);
	return s;
}

void OutputClearly(ofstream& out, Student h) {
	out << "ID : " << h.id << "\n";
	out << "First name : " << FirstName(h) << "\n";
	out << "Last name  : " << LastName(h) << "\n";
	out << "GPA : " << h.gpa << "\n";
	out << "Address : " << h.address << "\n";
	out << "DOB : "; h.date.OutputFile(out);
	return;
}

int ExtractClass(Student h) {
	int c[20], n = 0, id = h.id;
	while (id > 0) {
		c[++n] = id % 10;
		id /= 10;
	}
	int number = c[n] * 10 + c[n - 1];
	return number;
}

bool CompareId(Student a, Student b) {
	return a.id < b.id;
}

bool CompareGpaId(Student a, Student b) {
	const float p = 0.00001;
	if (abs(a.gpa - b.gpa) < p) {
		return a.id < b.id;
	}
	return a.gpa < b.gpa;
}

bool CompareNameId(Student a, Student b) {
	if (a.name < b.name) return true;
	if (a.name > b.name) return false;
	return a.id < b.id;
}

bool CompareFirstId(Student a, Student b) {
	string x = FirstName(a), y = FirstName(b);
	if (x == y) return a.id < b.id;
	return x < y;
}

bool CompareLastId(Student a, Student b) {
	string x = LastName(a), y = LastName(b);
	if (x == y) return a.id < b.id;
	return x < y;
}

bool CompareDobId(Student a, Student b) {
	if(DateEqual(a.date, b.date)) 
		return a.id < b.id;
	if (a.date.year == b.date.year) {
		if (a.date.month == b.date.month)
			return a.date.day < b.date.day;
		return a.date.month < b.date.month;
	}
	return a.date.year < b.date.year;
}