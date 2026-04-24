#include <iostream>
#include <string>
#include <ctime>
#include <istream>
#include <ostream>


using namespace std;

class Customer
{public:

    string fullname;
    string arrivalnumber;
    int priority;
    int waitingtime;
    Customer(string name, int num):fullname(name), arrivalnumber(num), priority(static_cast<int>(name.length())), waitingtime(0) {}
    priority = static_cast<int>(fullname.length());
};


int main() {
    srand(static_cast<unsigned int>(time(0)));
    const int MAX_NAMES = 30;
    const int MAX_ARRIVAL_NUM = 1000;
    string names[MAX_NAMES];
    int nameCount=0;

    ifstream roster(s: "roster.txt");

    if (roster) {
        string name;
        while (getline(roster, name) && nameCount < MAX_NAMES) {
            names[nameCount++] = name;
        }
        roster.close();
    } else {
        cerr << "Error opening roster.txt" << endl;
        return 1;
    }

    for (int i = 0; i < nameCount; ++i) {
        int arrivalNum = rand() % MAX_ARRIVAL_NUM + 1;
        Customer customer(names[i], arrivalNum);
    }


    roster.close();
    PQType<Customer> pq(max: 1000)
    const int Max_SERVED= 200
    Customer servedCustomers[Max_SERVED];
    int servedCount = 0;
    int arrivalTracker = 0;
    int timer = 0;

    for (int i =0; i<10 && !pq.IsFull();i++) {
        pq.Enqueue(newitem Customer(names[arrivalTracker], rand() % MAX_ARRIVAL_NUM + 1));
        arrivalTracker++;
        timer++;
    }

    return 0;
}