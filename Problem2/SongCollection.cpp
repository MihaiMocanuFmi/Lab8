#include <iostream>
#include "SongCollection.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////PRIVATE/////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string SongCollection::m_findFirstVariable(const std::string &variable, bool &outFound)
{
    std::string result;
    while(std::getline(m_inputFile, result) and not result.starts_with(variable));

    outFound = result.length() >= variable.length();

    if(outFound)
    {
        //we remove the variable flag, e.g ARTIST="
        result.erase(result.begin(), result.begin() + variable.length());

        std::string line;
        //while the line does not end with _"_ right before the "Carriage Return", we need to continue reading
        while(result.at(result.length() - 2) != '"' and std::getline(m_inputFile, line) )
            result += line;

        //we delete the \n (or \r = "Carriage Rerturn" in this case) at the end of the file
        result.erase(result.length() - 1);

        //we remove the last _"_
        result.erase(result.length() - 1);
    }


    return result;
}




void SongCollection::m_loadNextSong()
{
    bool found1, found2, found3;
    std::string artist = m_findFirstVariable(ARTIST_VAR, found1);
    std::string title = m_findFirstVariable(TITLE_VAR, found2);
    std::string lyrics = m_findFirstVariable(LYRICS_VAR, found3);

    if (found1 and found2 and found3)
        m_songs.emplace_back(artist, title, lyrics);

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////PUBLIC//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SongCollection::SongCollection(const std::string &filePath)
{
    m_inputFile.open(filePath);

    if (m_inputFile.fail())
        throw std::invalid_argument("Failed to open file!");
}
SongCollection::~SongCollection()
{
    m_inputFile.close();
}

void SongCollection::loadSongs()
{
    while (not m_inputFile.eof())
        m_loadNextSong();
}

