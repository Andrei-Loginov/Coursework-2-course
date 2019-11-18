#pragma once
#ifndef COURSEWORK_MATCHSCANNER_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "RandomString.h"

#define COURSEWORK_MATCHSCANNER_H
/*
 *   The getter of MatchScanner will return this structure
 *   Now it has only length of sequences and vector, which consists frequencies of number of matching symbols
 *   Later some other indicators will be added
*/

struct matchTestsResults
{
    size_t SLen;
    int cardinality;
    vector <size_t> frequencies;
    void outf(const char* outf)
    {
        ofstream f;
        f.open(outf, ios_base::app);
        for (size_t i = 0; i < frequencies.size(); i++)
        {
            cout << cardinality <<','<< SLen << "," << i << "," << frequencies[i] << "\n";
            f << cardinality << ',' << SLen << "," << i << "," << frequencies[i] << "\n";
        }
        f.close();
    }
};

class MatchScanner : public RandomString
{
public:
    MatchScanner();
    MatchScanner(size_t SL, size_t nOI, int alphabetSize);
    void setSLen(size_t size);
    matchTestsResults getres();
private:
    size_t SLen, numberOfIterations;
    int alphabetCardinality;
    vector<size_t> frequencies;
    vector<int> S1, S2;
    size_t matchCounter();
    void frequenciesCounter();
};


#endif //COURSEWORK_MATCHSCANNER_H
