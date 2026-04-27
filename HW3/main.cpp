#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "video.h"
#include "customer.h"
#include "inventory.h"
#include "rental.h"
#include "rentallog.h"
#include "rentservice.h"

using namespace std;

void printRental(Rental* rental) {
    cout << "Customer: " << rental->getCustomer()->getName()
         << " (" << rental->getCustomer()->getType() << ")" << endl;

    cout << "Videos: ";
    for (Video* v : rental->getVideos()) {
        cout << v->getTitle() << " [" << v->getCategory() << "] ";
    }

    cout << endl;
    cout << "Rental Days: " << rental->getRentalDays() << endl;
    cout << "Start Day: " << rental->getStartDay() << endl;
    cout << "Return Day: " << rental->getReturnDay() << endl;
    cout << "Total Price: $" << rental->getTotalPrice() << endl;
    cout << "-----------------------------" << endl;
}

int main() {
    srand(time(0));

    Inventory inventory;
    RentalLog rentalLog;
    RentService rentService(&inventory, &rentalLog);

    // 20 videos, 5 categories
    inventory.addVideo(new Video("New Release 1", "New Release", 5));
    inventory.addVideo(new Video("New Release 2", "New Release", 5));
    inventory.addVideo(new Video("New Release 3", "New Release", 5));
    inventory.addVideo(new Video("New Release 4", "New Release", 5));

    inventory.addVideo(new Video("Drama 1", "Drama", 4));
    inventory.addVideo(new Video("Drama 2", "Drama", 4));
    inventory.addVideo(new Video("Drama 3", "Drama", 4));
    inventory.addVideo(new Video("Drama 4", "Drama", 4));

    inventory.addVideo(new Video("Comedy 1", "Comedy", 2));
    inventory.addVideo(new Video("Comedy 2", "Comedy", 2));
    inventory.addVideo(new Video("Comedy 3", "Comedy", 2));
    inventory.addVideo(new Video("Comedy 4", "Comedy", 2));

    inventory.addVideo(new Video("Romance 1", "Romance", 3));
    inventory.addVideo(new Video("Romance 2", "Romance", 3));
    inventory.addVideo(new Video("Romance 3", "Romance", 3));
    inventory.addVideo(new Video("Romance 4", "Romance", 3));

    inventory.addVideo(new Video("Horror 1", "Horror", 3));
    inventory.addVideo(new Video("Horror 2", "Horror", 3));
    inventory.addVideo(new Video("Horror 3", "Horror", 3));
    inventory.addVideo(new Video("Horror 4", "Horror", 3));

    // 10 customers
    vector<Customer*> customers;
    customers.push_back(new BreezyCustomer("Alice"));
    customers.push_back(new BreezyCustomer("Bob"));
    customers.push_back(new BreezyCustomer("Cindy"));

    customers.push_back(new RegularCustomer("David"));
    customers.push_back(new RegularCustomer("Emily"));
    customers.push_back(new RegularCustomer("Frank"));
    customers.push_back(new RegularCustomer("Grace"));

    customers.push_back(new HoarderCustomer("Henry"));
    customers.push_back(new HoarderCustomer("Ivy"));
    customers.push_back(new HoarderCustomer("Jack"));

    // simulate 35 days
    for (int day = 1; day <= 35; day++) {
        rentalLog.processReturns(day);

        int visitsToday = rand() % 6; // 0~5 customers per day

        for (int i = 0; i < visitsToday; i++) {
            if (inventory.getAvailableVideoCount() == 0) {
                break;
            }

            vector<Customer*> candidates;

            for (Customer* c : customers) {
                if (c->getType() == "Hoarder" &&
                    inventory.getAvailableVideoCount() < 3) {
                    continue;
                }

                candidates.push_back(c);
            }

            if (candidates.empty()) {
                break;
            }

            Customer* selected =
                candidates[rand() % candidates.size()];

            rentService.createRental(selected, day);
        }
    }

    // final report
    cout << "\n========== FINAL REPORT ==========\n";

    cout << "\nVideos currently in store: "
         << inventory.getAvailableVideoCount() << endl;

    vector<Video*> availableVideos = inventory.getAvailableVideos();
    for (Video* v : availableVideos) {
        cout << "- " << v->getTitle()
             << " (" << v->getCategory() << ")" << endl;
    }

    cout << "\nTotal Revenue: $"
         << rentalLog.getTotalRevenue() << endl;

    cout << "\n========== Completed Rentals ==========\n";
    vector<Rental*> completed = rentalLog.getCompletedRentals();
    for (Rental* r : completed) {
        printRental(r);
    }

    cout << "\n========== Active Rentals ==========\n";
    vector<Rental*> active = rentalLog.getActiveRentals();
    for (Rental* r : active) {
        printRental(r);
    }

    for (Customer* c : customers) {
        delete c;
    }

    return 0;
}