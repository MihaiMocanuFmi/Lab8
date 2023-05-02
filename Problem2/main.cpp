#include <iostream>
#include <map>
#include <algorithm>

#include "SongCollection.h"

template <typename T>
void printResultFor5(const std::set<T> &set)
{
    std::cout << "All authors are:\n";
    for (const auto &element : set)
        std::cout << "\t\t" << element << '\n';

}
template <typename T>
void printResultFor6(const std::unordered_multimap<T, T> &map)
{
    std::vector<std::pair<T, int>> artists;

    //this is pain
    for (auto it = map.begin(); it != map.end(); std::advance(it, map.bucket_size(map.bucket(it->first))))
        artists.push_back(std::make_pair(it->first, map.bucket_size(map.bucket(it->first))));

    std::sort(artists.begin(), artists.end(),
              [](const auto &pair1, const auto &pair2)->bool{return pair1.second > pair2.second;} );

    std::cout << "The first 10 Artists with the most songs are:\n";
    for (int i = 0; i < 10; ++i)
        std::cout << "\t\t\"" << artists[i].first << "\" with " << artists[i].second << " songs.\n";



}
void printResultFor7(std::vector<Song> songs)
{
    std::sort(songs.begin(), songs.end(),
              [](const Song &song1, const Song &song2)->bool{return  song1.getArtist().compare(song2.getArtist()) < 0;});

    std::cout << "increasing order based on the artist's name:\n\t";
    for (const auto & song : songs)
        std::cout << song.getArtist() << '\t';
    std::cout << '\n';

    std::sort(songs.begin(), songs.end(),
              [](const Song &song1, const Song &song2)->bool{return  song1.getTitle().compare(song2.getTitle()) > 0;});

    std::cout << "decreasing order based on the song's title:\n\t";
    for (const auto & song : songs)
        std::cout << song.getTitle() << '\t';
    std::cout << '\n';

    std::sort(songs.begin(), songs.end(),
              [](const Song &song1, const Song &song2)->bool{return  song1.getLyrics().size() < song2.getLyrics().size();});

    std::cout << "increasing order based on the number of words in the lyrics.:\n\t";
    for (const auto & song : songs)
        std::cout << song.getLyrics().size() << '\t';
    std::cout << '\n';

}

void problem8(const SongCollection &collection)
{
    std::multimap<std::string, std::string> map;

    for (const auto &song : collection.getSongs())
        for (const auto &word : song.getLyrics())
        {
            const auto & pairIt = map.equal_range(word);
            bool songExists = false;
            for (auto it = pairIt.first; it != pairIt.second; ++it)
            {
                if (it->second == song.getTitle())
                {
                    songExists = true;
                    break;
                }
            }

            if (not songExists)
                map.insert(std::make_pair(word, song.getTitle()));
        }

    bool stop;

    do
    {
        std::cout << "Search for word:\n>> ";
        std::string word;
        std::cin >> word;

        const auto & pairIt = map.equal_range(word);
        for (auto it = pairIt.first; it != pairIt.second; ++it)
            std::cout << it->second << "\t";
        std::cout << "\n";

        std::cout << "Input \"0\" to stop, anything else to continue:\n>> ";
        char option;
        std::cin >> option;

        if (option == '0')
            stop = true;
        else
            stop = false;
    } while (not stop);

}

int main()
{
    try
    {
        SongCollection songCollection("songs.txt");
        songCollection.loadSongs();

        //printResultFor5(songCollection.getUniqueArtists());

        //std::cout << "\n\n";

        //printResultFor6(songCollection.getArtistsSongs());

        //std::cout << "\n\n";

        //printResultFor7(songCollection.getSongs());

        //SongCollection collectionTest("test.txt");
        //collectionTest.loadSongs();
        problem8(songCollection);
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what();
        return 1;
    }



    return 0;
}