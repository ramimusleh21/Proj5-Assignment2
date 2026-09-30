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

		for (int i = firstnameLength + 1; i < name.length(); i++) {
			if (name[i] != ' ') lastname += name[i];
		}
	};

	STUDENT_DATA(std::string name, std::string emailString) {
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

		for (int i = firstnameLength + 1; i < name.length(); i++) {
			if (name[i] != ' ') lastname += name[i];
		}

		int offset = firstname.size() + lastname.size() + 2;

		for (int i = offset; i < emailString.size(); i++)
		{
			if (emailString[i] != ',' && emailString[i] != ' ')
			{
				email += emailString[i];
			}
		}
	};

	void printName() {
		std::cout << firstname << " " << lastname << " " << email << std::endl;
	}

	std::string firstname;
	std::string lastname;
	std::string email;
};