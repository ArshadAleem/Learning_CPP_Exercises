// Learning C++ 
// Challenge 06_03
// Upgrade to work with files, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <fstream>
#include "records.h"

using namespace std;

void initialize();
void initializeWithFile();

StudentRecords SR;
int id;

int main(){
	initializeWithFile();

	cout << "Enter a student ID: ";
	cin >> id;

	SR.report_card(id);
	
	return (0);
}

void initializeWithFile() {
	ifstream inFile;
	string str;
	int sid;
	string sname;
	inFile.open("students.txt");
	if (inFile.fail())
		printf("students.txt did not open!");
	else
	{
		while (!inFile.eof())
		{
			getline(inFile,str);
			sid=stoi(str);
			getline(inFile, str);
			sname = str;
			SR.add_student(sid, sname);
		}
		inFile.close();
	}
	int cid;
	string subname;
	int crh;
	inFile.open("courses.txt");
	if (inFile.fail())
		printf("courses.txt did not open!");
	else
	{
		while (!inFile.eof())
		{
			getline(inFile, str);
			cid = stoi(str);
			getline(inFile, str);
			subname = str;
			getline(inFile, str);
			crh = stoi(str);
			SR.add_course(cid, subname,crh);
		}
		inFile.close();
	}
	char grade;
	inFile.open("grades.txt");
	if (inFile.fail())
		printf("grades.txt did not open!");
	else
	{
		while (!inFile.eof())
		{
			getline(inFile, str);
			sid = stoi(str);
			getline(inFile, str);
			cid = stoi(str);
			getline(inFile, str);
			grade = str[0];
			SR.add_grade(sid, cid, grade);
		}
		inFile.close();
	}
}

void initialize(){
	SR.add_student(1, "George P. Burdell");
	SR.add_student(2,"Nancy Rhodes");

	SR.add_course(1, "Algebra", 5);
	SR.add_course(2, "Physics", 4);
	SR.add_course(3, "English", 3);
	SR.add_course(4,"Economics",4);

	SR.add_grade(1, 1, 'B');
	SR.add_grade(1, 2, 'A');
	SR.add_grade(1, 3, 'C');
	SR.add_grade(2, 1, 'A');
	SR.add_grade(2, 2, 'A'); 
	SR.add_grade(2, 4, 'B');
}