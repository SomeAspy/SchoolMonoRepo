#include "PlaylistNode.h"
#include <iostream>

using std::cout;

PlaylistNode::PlaylistNode()
{
}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength)
{
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
}

string PlaylistNode::GetID() const
{
    return uniqueID;
}

string PlaylistNode::GetSongName() const
{
    return songName;
}

string PlaylistNode::GetArtistName() const
{
    return artistName;
}

int PlaylistNode::GetSongLength() const
{
    return songLength;
}

PlaylistNode *PlaylistNode::GetNext() const
{
    return nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode *nodePtr)
{
    if (nextNodePtr != nullptr)
    {
        nodePtr->InsertAfter(nextNodePtr);
    }
    nextNodePtr = nodePtr;
}

void PlaylistNode::SetNext(PlaylistNode *nodePtr)
{
    nextNodePtr = nodePtr;
}

void PlaylistNode::PrintPlaylistNode() const
{
    cout << "Unique ID: " << uniqueID << "\nSong Name: " << songName << "\nArtist Name: " << artistName << "\nSong Length (in seconds): " << songLength << '\n';
}
