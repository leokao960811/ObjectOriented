#ifndef RENTSERVICE_H
#define RENTSERVICE_H

#include <vector>
using namespace std;

class Customer;
class Inventory;
class RentalLog;
class Rental;

class RentService {
private:
    Inventory* inventory;
    RentalLog* rentalLog;

public:
    RentService(Inventory* inv, RentalLog* log);

    Rental* createRental(Customer* customer, int currentDay);
};

#endif