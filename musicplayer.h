#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
    string song;
    Node *next;
    Node *prev;
    Node(const string &songName) : song(songName), next(nullptr), prev(nullptr) {}
};

class MusicPlayer
{
private:
    Node *head;
    Node *top; // For recently played songs
    void addNode(Node *first, const string &song);
    void deleteFile(const string &song);
    void toFile(const string &song);
    void loadFromFile(Node *first);
    void deleteNode(Node *first, const string &song);

public:
    MusicPlayer();
    ~MusicPlayer();
    void addSong();
    void deleteSong();
    void displayPlaylist();
    void countSongs();
    void searchSong();
    void playSong();
    void displayRecent();
    void displayLastPlayed();
    void sortPlaylist();
};

#endif // MUSICPLAYER_H
