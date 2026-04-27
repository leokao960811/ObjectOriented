#include "video.h"

Video::Video(string title, string category, double pricePerDay) : title(title), category(category), pricePerDay(pricePerDay), isAvailable(true){}
Video::~Video() {}

string Video::getTitle() const {return title;}
string Video::getCategory() const {return category;}
double Video::getPricePerDay() const {return pricePerDay;}
bool Video::getIsAvailable() const {return isAvailable;}

void Video::setAvailable(bool available) {isAvailable = available;}
double Video::calculatePrice(int days) const {return pricePerDay * days;}