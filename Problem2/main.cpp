#include <iostream>
#include <map>
#include <algorithm>

#include "SongCollection.h"

template <typename T>
void printSet(const std::set<T> &set)
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

int main()
{
    try
    {
        SongCollection songCollection("songs.txt");
        songCollection.loadSongs();

        printSet(songCollection.getUniqueArtists());

        std::cout << "\n\n";

        printResultFor6(songCollection.getArtistsSongs());
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what();
        return 1;
    }



    return 0;
}