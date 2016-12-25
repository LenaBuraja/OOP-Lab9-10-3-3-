#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <map>
#include <iterator>
#include <algorithm>
#include <ctime>
#include "Array.h"


int main() {
	//srand(time(0));

	Array arr1;
	for (int i = 0; i < arr1.getSize(); i++) {
		arr1.setElement(i, 3 + rand() % 7);
	}
	Array arr2;
	for (int i = 0; i < arr2.getSize(); i++) {
		arr2.setElement(i, 3 + rand() % 7);
	}
	Array arr3;
	for (int i = 0; i < arr3.getSize(); i++) {
		arr3.setElement(i, 3 + rand() % 7);
	}
	Array arr4;
	for (int i = 0; i < arr4.getSize(); i++) {
		arr4.setElement(i, 3 + rand() % 7);
	}
	Array arr5;
	for (int i = 0; i < arr5.getSize(); i++) {
		arr5.setElement(i, 3 + rand() % 7);
	}

	std::map<std::string, Array*> student;

	student.insert(std::make_pair("Latkovich", &arr1));
	student.insert(std::pair<std::string, Array*>("Natarova", &arr2));
	student.insert({ "Buraja", &arr3 });
	student.insert(std::make_pair("Shostak", &arr4));
	student.insert({ "Sokol", &arr5 });

	std::cout << "Map students:" << std::endl;
	for (auto it = student.begin(); it != student.end(); it++) {
		std::cout << (*it).first << " - " << *(*it).second << std::endl;
	}
	system("pause");
	
	std::map<std::string, Array*>::iterator it;
	it = student.find("Latcovich");
	if (it == student.end()) std::cout << "INVALID KEY" << std:: endl;
		else std::cout << (*it).first << " - " << *(*it).second << std::endl;
	it = student.find("Latkovich");
	if (it == student.end()) std::cout << "INVALID KEY" << std::endl;
		else std::cout << (*it).first << " - " << *(*it).second << std::endl;
		system("pause");

	//std::map<std::string, Array*> listStudents;
	//Array arr6;
	//for (int i = 0; i < arr6.getSize(); i++) {
	//	arr6.setElement(i, 3 + rand() % 7);
	//}
	//Array arr7;
	//for (int i = 0; i < arr7.getSize(); i++) {
	//	arr7.setElement(i, 3 + rand() % 7);
	//}
	//Array arr8;
	//for (int i = 0; i < arr8.getSize(); i++) {
	//	arr8.setElement(i, 3 + rand() % 7);
	//}
	//Array arr9;
	//for (int i = 0; i < arr9.getSize(); i++) {
	//	arr9.setElement(i, 3 + rand() % 7);
	//}
	std::list<Array*> listStudents;
	for (auto it = student.begin(); it != student.end(); it++) {
		if ((*it).first.front() == 'K') {
			listStudents.push_back((*it).second);
		}
	}
	for (auto it = listStudents.begin(); it != listStudents.end(); it++) {
		std::cout << "List assessments: " << *it << std::endl;
	}

	return 0;
}
