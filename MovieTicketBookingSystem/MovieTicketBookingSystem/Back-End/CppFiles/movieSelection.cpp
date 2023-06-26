#include "../../HeaderFiles/applicationSetUp.h"

std::vector<int> cinemaBannerShuffle(std::vector<int> movie)
{
    std::vector<int> movieNumber = { 0, 1, 2, 3, 4, 5 };

    std::random_device rd;
    std::mt19937 engine(rd());

    std::shuffle(movieNumber.begin(), movieNumber.end(), engine);

    for (int i = 0; i < 4; i++)
    {
        movie.push_back(movieNumber[i]);
    }
    return movie;
}