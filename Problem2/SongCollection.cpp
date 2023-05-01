#include "SongCollection.h"

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

}

