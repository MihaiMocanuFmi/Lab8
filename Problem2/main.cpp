#include <iostream>

#include "SongCollection.h"



int main()
{
    try
    {
        SongCollection songCollection("songs.txt");
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what();
    }
}