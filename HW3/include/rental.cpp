#include "customer.h"
#include "video.h"
#include "rental.h"

Rental::Rental(Customer* customer, vector<Video*> videos, int rentalDays, int startDay)
 : customer(customer), videos(videos), rentalDays(rentalDays), startDay(startDay){

    this->returnDay = startDay + rentalDays;
    for(Video* v : videos) {
      v->setAvailable(false);
    }

    calculateTotalPrice();
 }
Rental::~Rental() {}

Customer* Rental::getCustomer() const {return customer;}
vector<Video*> Rental::getVideos() const {return videos;}
int Rental::getRentalDays() const {return rentalDays;}
int Rental::getStartDay() const {return startDay;}
int Rental::getReturnDay() const {return returnDay;}
double Rental::getTotalPrice() const {return totalPrice;}

bool Rental::isReturned(int currentDay) const{
    return currentDay >= returnDay;
}

void Rental::calculateTotalPrice() {
    totalPrice = 0.0;
    for(Video* v : videos) {
        totalPrice += v->calculatePrice(rentalDays);
    }
}