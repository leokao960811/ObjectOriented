#ifndef STORE_H
#define STORE_H

#include <vector>
using namespace std;

class Inventory;
class RentalLog;
class Customer;

class Store {
private:
    Inventory* inventory;
    RentalLog* rentalLog;
    vector<Customer*> customers;
    int currentDay;

public:
    Store();
    ~Store();

    void initializeVideos();
    void initializeCustomers();

    void simulate(int days);
    void simulateOneDay();

    Customer* selectRandomCustomer();
    void createRental(Customer* customer);

    void generateReport() const;
};

#endif