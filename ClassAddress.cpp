#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
	std::string city;
	std::string street;
	int house;
	int apt;
public:
	Address() {
		city = "default";
		street = "default";
		house = 0;
		apt = 0;
	}

	void fill(std::string city, std::string street, int house, int apt) {
		this->city = city;
		this->street = street;
		this->house = house;
		this->apt = apt;
	}

	std::string print() {
		return (city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apt));
	}
};

Address* createArray (const int elements)
{
	Address* Arr = new Address[elements];

	return Arr;
}

//Функция удаления динамического массива
void deleteArr(Address* arr, const int elements)
{
	delete[] arr;
	return;
}

int main() {
	int size;
	Address* address;

	std::string path_in = "in.txt";
	std::string path_out = "out.txt";

	std::ifstream file_in(path_in);
	std::ofstream file_out(path_out);

	if (file_in.is_open()) {
		file_in >> size;
		address = createArray(size);

		int i = 0;
		while (i < size) {

			std::string city;
			std::string street;
			int house;
			int apt;

			file_in >> city;
			file_in >> street;
			file_in >> house;
			file_in >> apt;

			address[i].fill(city, street, house, apt);

			i++;
		}

		for (int i = size - 1; i >= 0; i--) {
			file_out << address[i].print() << std::endl;
		}

		deleteArr(address, size);
	}
	else {
		std::cout << "File not find" << std::endl;
	}

	file_in.close();
	file_out.close();

}