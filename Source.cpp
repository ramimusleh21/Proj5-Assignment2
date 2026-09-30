#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "student.h"
#include "globals.h"

#define PRE_RELEASE

using namespace std;

int main(void) {

#ifdef PRE_RELEASE
	cout << "Running PRE - RELEASE source code.\n\n" << endl;
#else
	cout << "Running Standard source code.\n\n" << endl;
#endif

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
	string line;

	while (getline(nameFile, line))
	{
		STUDENT_DATA student(line);
		StudentList.emplace_back(student);
	}
	 
	#ifdef _DEBUG
	cout << "NAMES LOADED:\n";
		for (int i = 0; i < StudentList.size(); i++) StudentList[i].printName();
	#endif

	nameFile.close();
	emailFile.close();

	return 1;
}