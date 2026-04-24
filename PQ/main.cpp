#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Customer.h"
#include "PQType.h"
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int MAX_NAMES = 30;
    string names[MAX_NAMES];
    int nameCount = 0;

    ifstream roster("roster.txt");
    if (!roster) {
        cerr << "Error opening roster.txt" << endl;
        return 1;
    }
    string line;
    while (getline(roster, line) && nameCount < MAX_NAMES) {
        if (!line.empty())
            names[nameCount++] = line;
    }
    roster.close();

    PQType<Customer> pq(1000);
    const int MAX_SERVED = 200;
    Customer servedCustomers[MAX_SERVED];
    int servedCount = 0;
    int globalCount = 1;

    for (int i = 0; i < 10 && i < nameCount; i++) {
        int idx = rand() % nameCount;
        Customer c(names[idx], globalCount);
        pq.Enqueue(c);
        globalCount++;
    }

    while (servedCount < MAX_SERVED) {
        int roll = rand() % 10;
        if (roll < 6 && !pq.IsFull()) {
            int idx = rand() % nameCount;
            Customer c(names[idx], globalCount);
            pq.Enqueue(c);
            globalCount++;
        } else if (!pq.IsEmpty()) {
            Customer served;
            pq.Dequeue(served);
            served.waitTime = (globalCount - 1) - served.arrivalNumber;
            servedCustomers[servedCount++] = served;
        }
    }

    ofstream outFile("pq_wait_times.txt");
    if (!outFile) {
        cerr << "Error opening pq_wait_times.txt" << endl;
        return 1;
    }
    outFile << "Name                           ArrivalNum  Priority  WaitTime" << endl;
    outFile << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < servedCount; i++) {
        outFile << servedCustomers[i].fullName;
        for (int s = servedCustomers[i].fullName.length(); s < 31; s++)
            outFile << " ";
        outFile << servedCustomers[i].arrivalNumber << "          "
                << servedCustomers[i].priority << "         "
                << servedCustomers[i].waitTime << endl;
    }
    outFile.close();

    cout << "Simulation complete. Results written to pq_wait_times.txt" << endl;
    return 0;
}
