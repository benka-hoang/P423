#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include"Date.h"
#include"Student.h"

struct Course {
	char CourseID[20];
	char CourseName[30];
	int Num; Student ListStudent[100];
	bool Status;
	int MaxNumber, MinNumber;

	void UpdateStatus();

	void InputFile(ifstream& inp);

	void OutputFile(ofstream& out);

	void AddStudent(Student a);
	void DelStudent(int c);

	void WriteLegal(ofstream& out, Date d);
	void WriteBornMonth(ofstream& out, Date d);
	void WriteBornDate(ofstream& out, Date d);
	void WriteK19Class(ofstream& out);
	void WriteID(ofstream& out, int c);

	void SortID();
	void SortFirstName();
	void SortGPA();
	void SortDOB();

};