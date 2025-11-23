#include "Course.h"
#include"Date.h"
#include"Student.h"
#include<fstream>

void Course::UpdateStatus() {
	if (MinNumber <= Num && Num <= MaxNumber) {
		Status = true;
		return;
	}
	Status = false;
	if (Num > MaxNumber) {
		Num = MaxNumber;
	}
	return;
}

void Course::InputFile(ifstream& inp) {
	inp.get(CourseID, 20, '\n'); inp.ignore();
	inp.get(CourseName, 30, '\n');
	inp >> Num;
	for (int i = 0; i < Num; ++i) {
		ListStudent[i].InputFile(inp);
	}
	inp  >> MinNumber >> MaxNumber;
	UpdateStatus();
	return;
}

void Course::OutputFile(ofstream& out) {
	out << "Course ID : " << CourseID << "\n";
	out << "Course Name : " << CourseName << "\n";
	for (int i = 0; i < Num; ++i) {
		out << "--- Student " << i + 1 << " : ---\n";
		ListStudent[i].OutputFile(out);
	}
	return;
}

void Course::AddStudent(Student a) {
	++Num;
	ListStudent[Num - 1] = a;
	UpdateStatus();
	return;
}
void Course::DelStudent(int c) {
	int pos = -1;
	for (int i = 0; i < Num; ++i) if (c == ListStudent[i].id) {
		pos = i;
		break;
	}
	if (pos == -1) return;
	for (int i = pos; i < Num - 1; ++i)
		ListStudent[i] = ListStudent[i + 1];
	--Num;
	UpdateStatus();
	return;
}

void Course::WriteBornMonth(ofstream& out, Date d) {
	for (int i = 0; i < Num; ++i) if (ListStudent[i].date.month = d.month) {
		ListStudent[i].OutputFile(out);
	}
	return;
}
void Course::WriteBornDate(ofstream& out, Date d) {
	for (int i = 0; i < Num; ++i) if (ListStudent[i].date.month = d.month
		&& ListStudent[i].date.day == d.day) {
		ListStudent[i].OutputFile(out);
	}
	return;
}

void Course::WriteLegal(ofstream& out, Date d) {
	for (int i = 0; i < Num; ++i) {
		int a = DatetoId(ListStudent[i].date);
		int b = DatetoId(d);
		if (b - a >= 18 * 365) {
			ListStudent[i].OutputFile(out);
		}
	}
	return;
}

void Course::WriteK19Class(ofstream& out) {
	for (int i = 0; i < Num; ++i) if (ExtractClass(ListStudent[i]) == 19){
		ListStudent[i].OutputFile(out);
	}
	return;
}

void Course::WriteID(ofstream& out, int c) {
	for (int i = 0; i < Num; ++i) if (ListStudent[i].id == c) {
		ListStudent[i].OutputFile(out);
		break;
	}
	return;
}

void Course::SortID() {
	for (int i = 0; i < Num; ++i) {
		for (int j = i + 1; j < Num; ++j) if (ListStudent[i].id < ListStudent[j].id)
			swap(ListStudent[i], ListStudent[j]);
	}
	return;
}
void Course::SortFirstName() {
	for (int i = 0; i < Num; ++i) {
		for (int j = i + 1; j < Num; ++j) if (FirstName(ListStudent[i]) < FirstName(ListStudent[j]))
			swap(ListStudent[i], ListStudent[j]);
	}
	return;
}
void Course::SortGPA() {
	for (int i = 0; i < Num; ++i) {
		for (int j = i + 1; j < Num; ++j) if (ListStudent[i].gpa < ListStudent[j].gpa)
			swap(ListStudent[i], ListStudent[j]);
	}
	return;
}
void Course::SortDOB() {
	for (int i = 0; i < Num; ++i) {
		for (int j = i + 1; j < Num; ++j) if (DatetoId(ListStudent[i].date) < DatetoId(ListStudent[j].date))
			swap(ListStudent[i], ListStudent[j]);
	}
	return;
}