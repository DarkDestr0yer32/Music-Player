#include "MusicPlayer.h"

// Constructor
MusicPlayer::MusicPlayer() : head(nullptr), top(nullptr)
{
    head = new Node("Playlist");
    loadFromFile(head);
}

// Destructor
MusicPlayer::~MusicPlayer()
{
    Node *current = head;
    while (current)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

// Add a song to the playlist
void MusicPlayer::addSong()
{
    cout << "Enter Song name: ";
    string song;
    cin.ignore();
    getline(cin, song);
    addNode(head, song);
    toFile(song);
}

// Add node to the linked list
void MusicPlayer::addNode(Node *first, const string &song)
{
    while (first->next != nullptr)
    {
        first = first->next;
    }
    Node *newNode = new Node(song);
    first->next = newNode;
    newNode->prev = first;
}

// Write song to the file
void MusicPlayer::toFile(const string &song)
{
    ofstream outFile("playlist.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << song << endl;
    }
    outFile.close();
}

// Load playlist from file
void MusicPlayer::loadFromFile(Node *first)
{
    ifstream inFile("playlist.txt");
    if (!inFile.is_open())
    {
        cout << "Unable to open file." << endl;
        return;
    }

    string line;
    while (getline(inFile, line))
    {
        addNode(first, line);
    }
    inFile.close();
}

// Delete a song from the playlist
void MusicPlayer::deleteSong()
{
    displayPlaylist();
    cout << "Choose song you wish to delete: ";
    string song;
    cin.ignore();
    getline(cin, song);
    deleteNode(head, song);
    deleteFile(song);
}

// Delete node from the linked list
void MusicPlayer::deleteNode(Node *first, const string &song)
{
    while (first != nullptr)
    {
        if (first->song == song)
        {
            Node *temp = first;
            if (first->prev != nullptr)
            {
                first->prev->next = first->next;
            }
            if (first->next != nullptr)
            {
                first->next->prev = first->prev;
            }
            delete temp;
            cout << "Song has been deleted." << endl;
            return;
        }
        first = first->next;
    }
    cout << "Song not found." << endl;
}

// Delete song from the file
void MusicPlayer::deleteFile(const string &song)
{
    ifstream inFile("playlist.txt");
    ofstream outFile("temp.txt");
    if (!inFile.is_open() || !outFile.is_open())
    {
        cout << "Unable to open file." << endl;
        return;
    }

    string line;
    while (getline(inFile, line))
    {
        if (line != song)
        {
            outFile << line << endl;
        }
    }
    inFile.close();
    outFile.close();
    remove("playlist.txt");
    rename("temp.txt", "playlist.txt");
}

// Display the playlist
void MusicPlayer::displayPlaylist()
{
    Node *first = head;
    cout << "Playlist:" << endl;
    while (first != nullptr)
    {
        cout << first->song << endl;
        first = first->next;
    }
}

// Count the total number of songs
void MusicPlayer::countSongs()
{
    int count = 0;
    Node *first = head->next;
    while (first != nullptr)
    {
        count++;
        first = first->next;
    }
    cout << "Total songs: " << count << endl;
}

// Search for a song in the playlist
void MusicPlayer::searchSong()
{
    cout << "Enter song to be searched: ";
    string song;
    cin.ignore();
    getline(cin, song);

    Node *first = head;
    while (first != nullptr)
    {
        if (first->song == song)
        {
            cout << "Song found: " << song << endl;
            return;
        }
        first = first->next;
    }
    cout << "Song not found." << endl;
}

// Play a song from the playlist
void MusicPlayer::playSong()
{
    displayPlaylist();
    cout << "Choose song you wish to play: ";
    string song;
    cin.ignore();
    getline(cin, song);

    Node *first = head;
    while (first != nullptr)
    {
        if (first->song == song)
        {
            cout << "Now Playing: " << song << endl;
            Node *newNode = new Node(song);
            newNode->next = top;
            if (top != nullptr)
            {
                top->prev = newNode;
            }
            top = newNode;
            return;
        }
        first = first->next;
    }
    cout << "Song not found." << endl;
}

// Display the recently played songs
void MusicPlayer::displayRecent()
{
    Node *temp = top;
    if (temp == nullptr)
    {
        cout << "No recently played tracks." << endl;
        return;
    }

    cout << "Recently played tracks:" << endl;
    while (temp != nullptr)
    {
        cout << temp->song << endl;
        temp = temp->next;
    }
}

// Display the last played song
void MusicPlayer::displayLastPlayed()
{
    if (top == nullptr)
    {
        cout << "No last played tracks." << endl;
        return;
    }
    cout << "Last Played Song: " << top->song << endl;
}

// Sort the playlist (simple bubble sort for demonstration)
void MusicPlayer::sortPlaylist()
{
    if (head->next == nullptr)
    {
        return;
    }

    Node *i = head;
    Node *j = nullptr;
    bool swapped = true;

    while (swapped)
    {
        swapped = false;
        i = head;

        while (i->next != j)
        {
            if (i->song > i->next->song)
            {
                swap(i->song, i->next->song);
                swapped = true;
            }
            i = i->next;
        }
        j = i;
    }
    cout << "Playlist sorted." << endl;
}
