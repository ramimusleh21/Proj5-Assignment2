#pragma once

#include <iostream>

struct STUDENT_DATA {
	STUDENT_DATA(std::string name) {
		int firstnameLength = 0;
		int lastnameLength = 0;

		for (int i = 0; i < name.length(); i++) 
		{
			if (name[i] == ',') 
			{
				firstnameLength = i;
				continue;
			}

		}

		lastnameLength = name.length() - firstnameLength - 1;

		for (int i = 0; i < firstnameLength; i++) {
			if (name[i] != ' ') firstname += name[i];
		}
		
		for (int i = firstnameLength+1; i < name.length(); i++) {
			if (name[i] != ' ') lastname += name[i];
		}
	}

	void printName() {
		std::cout << firstname << " " << lastname << std::endl;
	}

	std::string firstname;
	std::string lastname;
};