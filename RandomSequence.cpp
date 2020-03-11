//
// Created by andrei on 10.03.2020.
//

#include "RandomSequence.h"

RandomSequence::RandomSequence()
{
    std::random_device rd;
    randomGenerator_.seed(rd());
}

char* RandomSequence::random(const size_t &len)
{
    char *ans = new char[len + 1];
    ans[len] = '\0';
    for (int i = 0; i < len; ++i)
        ans[i] = aminoAcidsAlphabet[randomGenerator_() % 22];
    return ans;
}