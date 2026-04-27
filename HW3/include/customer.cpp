#include "customer.h"
#include <cstdlib>

Customer::Customer(string name, string type)
    : name(name), type(type), currentRentedCount(0) {}

Customer::~Customer() {}

string Customer::getName() const {
    return name;
}

string Customer::getType() const {
    return type;
}

int Customer::getCurrentRentedCount() const {
    return currentRentedCount;
}

int Customer::getRemainingRentalLimit() const {
    return 3 - currentRentedCount;
}

bool Customer::canRent(int count) const {
    return currentRentedCount + count <= 3;
}

void Customer::addRentedCount(int count) {
    currentRentedCount += count;
}

void Customer::removeRentedCount(int count) {
    currentRentedCount -= count;
    if (currentRentedCount < 0) {
        currentRentedCount = 0;
    }
}

BreezyCustomer::BreezyCustomer(string name)
    : Customer(name, "Breezy") {}

int BreezyCustomer::getRentalDays() const {
    return (rand() % 2) + 1; // 1~2 days
}

int BreezyCustomer::getRentalLimit() const {
    return (rand() % 2) + 1; // 1~2 videos
}

RegularCustomer::RegularCustomer(string name)
    : Customer(name, "Regular") {}

int RegularCustomer::getRentalDays() const {
    return (rand() % 3) + 3; // 3~5 days
}

int RegularCustomer::getRentalLimit() const {
    return (rand() % 3) + 1; // 1~3 videos
}

HoarderCustomer::HoarderCustomer(string name)
    : Customer(name, "Hoarder") {}

int HoarderCustomer::getRentalDays() const {
    return 7;
}

int HoarderCustomer::getRentalLimit() const {
    return 3;
}