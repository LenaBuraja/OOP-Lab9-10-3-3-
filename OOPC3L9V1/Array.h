#pragma once
#include <ostream>
#include <istream>
#include <memory>

class Array {
	int size;
	std::shared_ptr<int> element = nullptr; 
public:
	Array(int size);
	Array(const Array& arr);
	Array();

	void setSize(int newSize);
	void setElement(int index, int value);
	int getSize() const;
	int getElement(int index) const;
	~Array();

	friend std::ostream &operator<< (std::ostream& out, Array& arr) {
		out << "[";
		for (int i = 0; i < arr.getSize(); i++) {
			out << arr.getElement(i);
			if (i != arr.getSize() - 1) {
				out << ", ";
			}
		}
		out << "]";
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