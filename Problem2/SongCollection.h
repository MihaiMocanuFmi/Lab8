#pragma once
#include <vector>
#include <string>
#include <fstream>

#include "Song.h"

class SongCollection
{
private:
    std::vector<Song> m_songs;

    std::ifstream m_inputFile;


public:
    SongCollection(const std::string &filePath);
    ~SongCollection();

    void loadSongs();

};
