#include "customer.h"
#include <cstdlib> // Needed for rand()


Customer::Customer(string name, string type) : name(name), type(type) {}
Customer::~Customer() {}


BreezyCustomer::BreezyCustomer(string name): Customer(name, "Breezy") {}

int BreezyCustomer::getRentalDays() const {
    return (rand() % 2) + 1;
}

int BreezyCustomer::getRentalLimit() const {
    return (rand() % 2) + 1;
}

RegularCustomer::RegularCustomer(string name): Customer(name, "Regular") {}

int RegularCustomer::getRentalDays() const {
    return (rand() % 3) + 1;
}

int RegularCustomer::getRentalLimit() const {
    return (rand() % 5) + 3;
}

HoarderCustomer::HoarderCustomer(string name): Customer(name, "Hoarder") {}

int HoarderCustomer::getRentalDays() const {
    return 3;
}

int HoarderCustomer::getRentalLimit() const {
    return 7;
}