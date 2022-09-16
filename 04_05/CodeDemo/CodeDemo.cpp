// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

using namespace std;

vector<Student> students = {Student(1,"George P. Burdell"),
							Student(2,"Nancy Rhodes")};

vector<Course> courses = {Course(1,"Algebra",5),
						  Course(2,"Physics",4),
						  Course(3,"English",3),
						  Course(4,"Economics",4)};

vector<Grade> grades = {Grade(1,1,'B'),	Grade(1,2,'A'),	Grade(1,3,'C'),
						Grade(2,1,'A'),	Grade(2,2,'A'), Grade(2,4,'B')};

float GPA = 0.0f;
int id;

int PointsTable(char grade)
{
	int points = 0;
	switch (grade) {
	case 'A':
		points = 4;
		break;
	case 'B':
		points = 3;
		break;
	case 'C':
		points = 2;
		break;
	case 'D':
		points = 1;
		break;
	case 'F':
		points = 0;
		break;
	default:
		points = 0;
		break;

	}
	return points;
}


int main(){
	cout << "Enter a student ID: ";
	cin >> id;
	int grade_points=0;
	int total_ch = 0;

	// Calculate the GPA for the selected student.
	// Write your code here
	for (auto x : grades)
	{
		if (x.get_student_id() == id) {
			
			// attained_points * credit_hours
			grade_points += PointsTable(x.get_grade())* courses[x.get_course_id()-1].get_credits();
			total_ch += courses[x.get_course_id() - 1].get_credits();
		}
	}
	GPA = (float)grade_points / total_ch;

	string student_str;
	student_str = students[id-1].get_name(); // Change this to the selected student's name

	cout << "The GPA for " << student_str << " is " << GPA << endl;
	return (0);
}





