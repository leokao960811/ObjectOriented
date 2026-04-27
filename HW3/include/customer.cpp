#include "customer.h"
#include <cstdlib> // Needed for rand()


Customer::Customer(string name, string type) : name(name), type(type) {}
Customer::~Customer() {}
string Customer::getName() const {
    return name;
}

string Customer::getType() const {
    return type;
}

BreezyCustomer::BreezyCustomer(string name): Customer(name, "Breezy") {}

int BreezyCustomer::getRentalDays() const {
    return (rand() % 2) + 1;
}

int BreezyCustomer::getRentalLimit() const {
    return (rand() % 2) + 1;
}

RegularCustomer::RegularCustomer(string name): Customer(name, "Regular") {}
HoarderCustomer::HoarderCustomer(string name)
    : Customer(name, "Hoarder") {}
int RegularCustomer::getRentalDays() const {
    return (rand() % 3) + 3; // 3~5 days
}

int RegularCustomer::getRentalLimit() const {
    return (rand() % 3) + 1; // 1~3 videos
}

int HoarderCustomer::getRentalDays() const {
    return 7;
}

int HoarderCustomer::getRentalLimit() const {
    return 3;
}