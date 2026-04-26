#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

class Video {
protected:
    string title;
    string category;
    double pricePerDay;
    bool isAvailable;

public:
    Video(string title, string category, double pricePerDay);
    virtual ~Video();

    string getTitle() const;
    string getCategory() const;
    double getPricePerDay() const;
    bool getIsAvailable() const;

    void setAvailable(bool available);

    virtual double calculatePrice(int days) const;
};

#endif