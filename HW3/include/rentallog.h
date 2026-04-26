#ifndef RENTALLOG_H
#define RENTALLOG_H

#include <vector>
using namespace std;

class Rental;

class RentalLog {
private:
    vector<Rental*> activeRentals;
    vector<Rental*> completedRentals;

public:
    RentalLog();
    ~RentalLog();

    void addRental(Rental* rental);
    void processReturns(int currentDay);

    vector<Rental*> getActiveRentals() const;
    vector<Rental*> getCompletedRentals() const;

    double getTotalRevenue() const;
};

#endif