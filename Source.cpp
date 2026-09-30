#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "student.h"
#include "globals.h"

#define PRE_RELEASE

using namespace std;

int main(void) {

	vector<STUDENT_DATA> StudentList;

	ifstream nameFile(NAME_FILEPATH);
	if (!nameFile.is_open()) {
		cerr << "Could Not Open Name File" << endl;
		return 1;
	}

	ifstream emailFile(EMAIL_FILEPATH);
	if (!emailFile.is_open()) {
		cerr << "Could Not Open Email File" << endl;
		return 1;
	}
	
#ifdef PRE_RELEASE
	
	string name;
	string email;
	cout << "Running PRE - RELEASE source code.\n\n" << endl;
	while (getline(nameFile, name) && getline(emailFile, email))
	{
		STUDENT_DATA student(name, email);
		StudentList.emplace_back(student);
	}
#else
	cout << "Running Standard source code.\n\n" << endl;
		
	string name;
	while (getline(nameFile, name) && getline(emailFile, email))
		{
			STUDENT_DATA student(name);
			StudentList.emplace_back(student);
		}
#endif
	 
	#ifdef _DEBUG
	cout << "NAMES LOADED:\n";
		for (int i = 0; i < StudentList.size(); i++) StudentList[i].printName();
	#endif

	nameFile.close();
	emailFile.close();

	return 1;
}