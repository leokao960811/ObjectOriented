#include "customer.h"
#include "inventory.h"
#include "rental.h"
#include "rentallog.h"
#include "rentservice.h"
#include <iostream>

RentService::RentService(Inventory* inv, RentalLog* log) : inventory(inv), rentalLog(log) {}

Rental* RentService::createRental(Customer* customer, int currentDay) {
    int requestedVideos = customer->getRentalLimit();
    int requestedDays = customer->getRentalDays();
    
    int availableInStore = inventory->getAvailableVideoCount();

    if (customer->getType() == "Hoarder" && availableInStore < 3) {
        return nullptr;
    }

    int actualVideosToRent = requestedVideos;
    if (actualVideosToRent > availableInStore) {
        actualVideosToRent = availableInStore;
    }

    if (actualVideosToRent == 0) {
        return nullptr;
    }

    vector<Video*> rentedVideos = inventory->rentVideos(actualVideosToRent);

    Rental* newRental = new Rental(customer, rentedVideos, requestedDays, currentDay);

    rentalLog->addRental(newRental);

    return newRental;
}