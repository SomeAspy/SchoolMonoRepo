#include <iostream>
#include <ostream>
#include "PlaylistNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ostringstream;
using std::streambuf;
using std::string;

void PrintMenu(const string playlistTitle)
{
    cout << playlistTitle << " PLAYLIST MENU\na - Add song\nd - Remove song\nc - Change position of song\ns - Output songs by specific artist\nt - Output total time of playlist (in seconds)\no - Output full playlist\nq - Quit\n\n";
}

PlaylistNode *ExecuteMenu(char option, string playlistTitle, PlaylistNode *headNode)
{
    switch (option)
    {
    case 'a':
    {
        string uid, name, aname;
        int length;
        cout << "ADD SONG\nEnter song's unique ID:\n";
        cin >> uid;
        cout << "Enter song's name:\n";
        cin >> name;
        cout << "Enter artist's name:\n";
        cin >> aname;
        cout << "Enter song's length (in seconds):\n";
        cin >> length;
        PlaylistNode *addition = new PlaylistNode(uid, name, aname, length);
        PlaylistNode *temp = headNode;
        while (true)
        {
            if (temp->GetNext() == 0)
            {
                break;
            }
            temp = temp->GetNext();
        }
        temp->InsertAfter(addition);
        break;
    }
    case 'd':
        break;
    case 'c':
        break;
    case 's':
        break;
    case 't':
        break;
    case 'o':
    {
        cout << playlistTitle << " - OUTPUT FULL PLAYLIST\n";
        PlaylistNode *temp = headNode;
        if (temp == NULL)
        // This is here to handle impossibly malformed inputs (ie not made with new PlaylistNode (FUCK YOU ZYBOOKS))
        {
            cout << "Playlist is empty\n";
        }
        else
        {
            unsigned int counter = 1;
            while (true)
            {
                cout << counter << ".\n";
                cout << temp->GetNext() << '\n';
                ++counter;
                temp->PrintPlaylistNode();
                if (temp->GetNext() == 0)
                {
                    break;
                }
                temp = temp->GetNext();
            }
        }
        break;
    }
    case 'q':
        exit(0);
    }
}

int main()
{
    PlaylistNode *list = new PlaylistNode();
    string playlistTitle;
    cout << "Enter playlist's title:\n\n";
    getline(cin, playlistTitle);
    while (true)
    {
        char option = 'q';
        PrintMenu(playlistTitle);
        cout << "Choose an option:\n";
        cin >> option;
        ExecuteMenu(option, playlistTitle, list);
    }
    return 0;
}
