#include <iostream>
#include <limits>
#include "MusicPlayer.h"

using namespace std;

void displayMenu()
{
    cout << "**********************\n";
    cout << "**  MUSIC PLAYER    **\n";
    cout << "**********************\n";
    cout << "1. Add New Song\n";
    cout << "2. Delete Song\n";
    cout << "3. Display Playlist\n";
    cout << "4. Count Songs\n";
    cout << "5. Search Song\n";
    cout << "6. Play Song\n";
    cout << "7. Recently Played List\n";
    cout << "8. Last Played\n";
    cout << "9. Sort Playlist\n";
    cout << "10. Exit\n";
    cout << "**********************\n";
    cout << "Enter your choice: ";
}

int main()
{
    MusicPlayer player;
    int choice;

    cout << "\033[1;32m** WELCOME TO THE MUSIC PLAYER **\033[0m" << endl;

    do
    {
        displayMenu();

        if (!(cin >> choice))
        {
            cout << "\033[1;31mInvalid input. Please enter a number.\033[0m" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            player.addSong();
            break;
        case 2:
            player.deleteSong();
            break;
        case 3:
            player.displayPlaylist();
            break;
        case 4:
            player.countSongs();
            break;
        case 5:
            player.searchSong();
            break;
        case 6:
            player.playSong();
            break;
        case 7:
            player.displayRecent();
            break;
        case 8:
            player.displayLastPlayed();
            break;
        case 9:
            player.sortPlaylist();
            break;
        case 10:
            cout << "\033[1;32mExiting...\033[0m" << endl;
            exit(0);
        default:
            cout << "\033[1;31mInvalid choice. Please try again.\033[0m" << endl;
            break;
        }

    } while (true);

    return 0;
}
