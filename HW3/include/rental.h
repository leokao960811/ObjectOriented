#ifndef RENTAL_H
#define RENTAL_H

#include <vector>
using namespace std;

class Customer;
class Video;

class Rental {
private:
    Customer* customer;
    vector<Video*> videos;
    int rentalDays;
    int startDay;
    int returnDay;
    double totalPrice;

public:
    Rental(Customer* customer, vector<Video*> videos, int rentalDays, int startDay);

    Customer* getCustomer() const;
    vector<Video*> getVideos() const;
    int getRentalDays() const;
    int getStartDay() const;
    int getReturnDay() const;
    double getTotalPrice() const;

    bool isReturned(int currentDay) const;
    void calculateTotalPrice();
};

#endif