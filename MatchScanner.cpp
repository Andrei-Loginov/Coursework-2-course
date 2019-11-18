#include "MatchScanner.h"

MatchScanner::MatchScanner()
{
#ifdef DEBUG
    cout << "MatchScanner()\n";
#endif
}

MatchScanner::MatchScanner(size_t SL, size_t nOI, int alphabetSize)
{
    SLen = SL;
    numberOfIterations = nOI;
    frequencies.resize(SLen);
    alphabetCardinality = alphabetSize;
}

void MatchScanner::setSLen(size_t size)
{
    SLen = size;
    frequencies.resize(SLen + 1);
}

size_t MatchScanner::matchCounter()
{
    int ans = 0;
    for(int i = 0; i < SLen; i++)
        if (S1[i] == S2[i]) ans++;
    return ans;
}

void MatchScanner::frequenciesCounter()
{
    for (vector<size_t>::iterator it = frequencies.begin(); it != frequencies.end(); *it = 0, it++);
    for (size_t i = 0; i < numberOfIterations; i++)
    {
        S1 = random(SLen, alphabetCardinality);
        S2 = random(SLen, alphabetCardinality);
        frequencies[matchCounter()]++;
    }

}

matchTestsResults MatchScanner::getres()
{
    frequenciesCounter();
    matchTestsResults ans;
    ans.SLen = SLen;
    ans.frequencies = frequencies;
    ans.cardinality = alphabetCardinality;
    return ans;
}