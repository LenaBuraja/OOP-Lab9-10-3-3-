#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>

class Array {
	int size;
	int *element;
public:
	Array(int size) {
		this->size = 0;
		element = new int[this->size];
		setSize(size);
	}

	Array(const Array& arr) {
		for (int i = 0; i < getSize(); i++) {
			setElement(i, arr.getElement(i));
		}
	}

	Array() : Array(5) {

	}

	void setSize(int newSize) {
		int *newArr = new int[newSize];
		int minSize = (size < newSize) ? size : newSize;
		for (int i = 0; i < minSize; i++) {
			newArr[i] = element[i];
		}
		delete[] element;
		size = newSize;
		element = newArr;
	}

	void setElement(int index, int value) {
		if (index >= 0 || index < size) {
			element[index] = value;
		}
	}
	int getSize() const {
		return size;
	}

	int getElement(int index) const {
		return element[index];
	}
	~Array() {

	}

	friend std::ostream &operator<< (std::ostream& out, Array& arr) {
		for (int i = 0; i < arr.getSize(); i++) {
			out << arr.getElement(i);
			if (i != arr.getSize() - 1) {
				out << ", ";
			}
		}
		return out;
	}

	friend std::istream &operator >> (std::istream& in, Array& arr) {
		for (int i = 0; i < arr.getSize(); i++) {
			int value;
			in >> value;
			arr.setElement(i, value);
		}
		return in;
	}
};

int main() {
	Array arr1;
	std::cout << "Enter first array:" << std::endl;
	std::cin >> arr1;
	Array arr2;
	std::cout << "Enter second array:" << std::endl;
	std::cin >> arr2;
	Array arr3;
	std::cout << "Enter three array:" << std::endl;
	std::cin >> arr3;

	std::map<std::string, Array> student;

	student.insert({ "Latkovich" , arr1 });
	student.insert(std::pair<std::string, Array> ("Natarova", arr2 ));
	student.insert({ "Buraja", arr3 });

	std::cout << "Map students:" << std::endl;
	for (auto it = student.begin(); it != student.end(); it++) {
		std::cout << (*it).first << " - " << (*it).second << std::endl;
	}

	return 0;
}
