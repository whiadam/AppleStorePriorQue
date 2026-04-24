#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;

class Customer {
public:
    string fullName;
    int arrivalNumber;
    int priority;
    int waitTime;

    Customer() : fullName(""), arrivalNumber(0), priority(0), waitTime(0) {}

    Customer(string name, int num)
        : fullName(name), arrivalNumber(num),
          priority(static_cast<int>(name.length())), waitTime(0) {}

    bool operator<(const Customer& other) const {
        return priority < other.priority;
    }
    bool operator<=(const Customer& other) const {
        return priority <= other.priority;
    }
    bool operator>(const Customer& other) const {
        return priority > other.priority;
    }
};

#endif
