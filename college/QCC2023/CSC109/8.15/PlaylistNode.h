#include <string>

using std::string;

class PlaylistNode
{
public:
    PlaylistNode();
    PlaylistNode(string uniqueID, string songName, string artistName, int songLength);
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode *GetNext() const;
    void InsertAfter(PlaylistNode *nodePtr);
    void SetNext(PlaylistNode *nodePtr);
    void PrintPlaylistNode() const;

private:
    string uniqueID = "none";
    string songName = "none";
    string artistName = "none";
    int songLength = 0;
    PlaylistNode *nextNodePtr = 0;
};
