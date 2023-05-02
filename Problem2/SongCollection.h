#pragma once
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <unordered_map>

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
    const std::vector<Song> &getSongs() const;
    std::set<std::string> getUniqueArtists() const ;
    std::unordered_multimap<std::string, std::string> getArtistsSongs() const;

};
