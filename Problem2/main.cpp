#include <iostream>

#include "SongCollection.h"



int main()
{
    try
    {
        SongCollection songCollection("songs.txt");
        songCollection.loadSongs();
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what();
        return 1;
    }



    return 0;
}