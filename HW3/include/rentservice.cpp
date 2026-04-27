#include "customer.h"
#include "inventory.h"
#include "rental.h"
#include "rentallog.h"
#include "rentservice.h"
#include <iostream>

RentService::RentService(Inventory* inv, RentalLog* log)
    : inventory(inv), rentalLog(log) {}

Rental* RentService::createRental(Customer* customer, int currentDay) {
    int requestedVideos = customer->getRentalLimit();
    int requestedDays = customer->getRentalDays();
    int availableInStore = inventory->getAvailableVideoCount();

    if (availableInStore == 0) {
        return nullptr;
    }

    // 顧客同時最多只能租 3 部
    if (!customer->canRent(requestedVideos)) {
        return nullptr;
    }

    // Hoarder 一定要租 3 部，不足 3 部就不能租
    if (customer->getType() == "Hoarder" && availableInStore < 3) {
        return nullptr;
    }

    // 一般情況：店內影片不足以滿足這次租借，也不能建立 rental
    if (availableInStore < requestedVideos) {
        return nullptr;
    }

    vector<Video*> rentedVideos = inventory->rentVideos(requestedVideos);

    Rental* newRental = new Rental(customer, rentedVideos, requestedDays, currentDay);

    customer->addRentedCount(rentedVideos.size());

    rentalLog->addRental(newRental);

    return newRental;
}