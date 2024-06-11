#include <iostream>
#include <stdexcept>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(2000) {} // default constructor

    void setDay(int d) {
        if (d < 1 || d > 31) {
            throw std::invalid_argument("Invalid day");
        }
        day = d;
    }

    void setMonth(int m) {
        if (m < 1 || m > 12) {
            throw std::invalid_argument("Invalid month");
        }
        month = m;
    }

    void setYear(int y) {
        if (y < 1) {
            throw std::invalid_argument("Invalid year");
        }
        year = y;
    }

    void setData(int d, int m, int y) {
        try {
            setDay(d);
            setMonth(m);
            setYear(y);
        } catch (const std::invalid_argument& e) {
            throw;
        }
    }

    void printDate() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

int main() {
    Date date;
    int day, month, year;
    std::cout << "Enter day: ";
    std::cin >> day;
    std::cout << "Enter month: ";
    std::cin >> month;
    std::cout << "Enter year: ";
    std::cin >> year;
    try {
        date.setData(day, month, year);
        date.printDate();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

