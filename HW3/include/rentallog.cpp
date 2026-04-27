#include "customer.h"
#include "video.h"
#include "rental.h"
#include "rentallog.h"
#include <iostream>

RentalLog::RentalLog() {}
RentalLog::~RentalLog() {
    for(Rental* r : activeRentals) delete r;
    for(Rental* r : completedRentals) delete r;
}

void RentalLog::addRental(Rental* rental) {
    activeRentals.push_back(rental);
}



double RentalLog::getTotalRevenue() const {
    double total = 0.0;

    for(Rental* r: completedRentals) total += r->getTotalPrice();
    for(Rental* r: activeRentals) total += r->getTotalPrice();
    return total;
}
void RentalLog::processReturns(int currentDay) {
    for (auto it = activeRentals.begin(); it != activeRentals.end();) {
        if ((*it)->isReturned(currentDay)) {

            for (Video* v : (*it)->getVideos()) {
                v->setAvailable(true);
            }

            Customer* customer = (*it)->getCustomer();
            customer->removeRentedCount((*it)->getVideos().size());

            completedRentals.push_back(*it);
            it = activeRentals.erase(it);

        } else {
            ++it;
        }
    }
}

vector<Rental*> RentalLog::getActiveRentals() const {return activeRentals;}
vector<Rental*> RentalLog::getCompletedRentals() const {return completedRentals;}