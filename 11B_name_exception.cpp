#include <iostream>
#include <stdexcept>
#include <string>

class Person {
private:
    std::string name;
    int id;

public:
    Person() : name(""), id(0) {} // default constructor

    void setName(const std::string& n) {
        if (n.empty()) {
            throw std::invalid_argument("Name cannot be empty");
        }
        name = n;
    }

    void setId(int i) {
        if (i == 0) {
            throw std::invalid_argument("ID cannot be 0");
        }
        id = i;
    }

    void setData(const std::string& n, int i) {
        try {
            setName(n);
            setId(i);
        } catch (const std::invalid_argument& e) {
            throw;
        }
    }

    void printPerson() const {
        std::cout << "Name: " << name << ", ID: " << id << std::endl;
    }
};

int main() {
    Person person;
    std::string name;
    int id;
    std::cout << "Enter name: ";
    std::getline(std::cin >> std::ws, name); // read input with whitespaces
    std::cout << "Enter ID: ";
    std::cin >> id;
    try {
        person.setData(name, id);
        person.printPerson();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

