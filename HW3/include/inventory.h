#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
using namespace std;

class Video;

class Inventory {
private:
    vector<Video*> videos;

public:
    Inventory();
    ~Inventory();

    void addVideo(Video* video);
    void removeVideo(Video* video);

    int getAvailableVideoCount() const;
    vector<Video*> getAvailableVideos() const;
    vector<Video*> rentVideos(int count);

    void returnVideos(vector<Video*> returnedVideos);
};

#endif