#include "inventory.h"
#include "video.h"
#include <algorithm>

Inventory::Inventory() {}

Inventory::~Inventory() {
    for(Video* v : videos) delete v;
}

void Inventory::addVideo(Video* video) {
    videos.push_back(video);
}

int Inventory::getAvailableVideoCount() const {
    int count = 0; 
    for(Video* v : videos) {
        if(v->getIsAvailable()) count++;
    }
    return count;
}

vector<Video*> Inventory::getAvailableVideos() const{
    vector<Video*> available;
    for(Video* v : videos) {
        if(v->getIsAvailable()) available.push_back(v);
    }
    return available;
}

vector<Video*> Inventory::rentVideos(int count) {
    vector<Video*> toRent;
    int found = 0;
    for(Video* v : videos) {
        if(v->getIsAvailable() && found < count) {
            v->setAvailable(false);
            toRent.push_back(v);
            found++;
        }
    }
    return toRent;
}

void Inventory::returnVideos(vector<Video*> returnedVideos) {
    for(Video* v : returnedVideos) {
        v->setAvailable(true);
    }
}