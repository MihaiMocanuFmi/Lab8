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

    static constexpr char ARTIST_VAR[] = "ARTIST=\"";
    static constexpr char TITLE_VAR[] = "TITLE=\"";
    static constexpr char LYRICS_VAR[] = "LYRICS=\"";

    std::string m_findFirstVariable(const std::string &variable, bool &outFound);
    void m_loadNextSong();

public:
    explicit SongCollection(const std::string &filePath);
    ~SongCollection();

    void loadSongs();

};
