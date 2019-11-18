#include "PrCounter.h"

PrCounter::PrCounter()
{
#ifdef DEBUG
    cout << "PrCounter()\n";
#endif
}

PrCounter::PrCounter(size_t SL, size_t subLen, size_t nOI, size_t ML, int alphabetSz, char* outFile):  outputFile(outFile)
{
    srand(time(nullptr));
    SLen = SL;
    substrLen = subLen;
    numberOfIterations = nOI;
    mismatchLimit = ML;
    alphabetSize = alphabetSz;
    S = random(SL, alphabetSize);
    fout1.open(outFile, ios_base::app);
    //fout1 << "For the string " << S << ":\n";
#ifdef DEBUG
    cout << "PrCounter::PrCounter(size_t, size_t, size_t, size_t, char*)\n";
#endif
}

PrCounter::PrCounter(size_t SL, size_t subLen, size_t nOI, size_t ML, int alphabetSz, char* outFile, char* rubbishOut):  outputFile(outFile), rubbishOutput(rubbishOut)
{
    srand(time(nullptr));
    SLen = SL;
    substrLen = subLen;
    numberOfIterations = nOI;
    mismatchLimit = ML;
    alphabetSize = alphabetSz;
    S = random(SL, alphabetSize);
#ifdef DEBUG
    cout << "PrCounter::PrCounter(size_t, size_t, size_t, size_t, char*)\n";
#endif
}


PrCounter::~PrCounter()
{
#ifdef DEBUG
    cout << "PrCounter::~Prcounter()\n";
#endif
    fout1.close();
    fout2.close();
}

size_t PrCounter::mismatch()
{
    size_t ans = substr.size();
    for (size_t i = 0; i + substr.size() <= S.size(); i++)
    {
        size_t k = 0;
        for (size_t j = 0; j < substr.size(); j++)
        {
            if (substr[j] != S[i + j]) k++;
        }
        if (k < ans) ans = k;
    }
    return ans;
}

size_t PrCounter::frequency()
{
    size_t counter = 0;
    for (size_t i = 0; i < numberOfIterations; i++)
    {
        substr = random(substrLen, alphabetSize);
        for (vector<int>::iterator it = substr.begin(); it != substr.end(); fout2 << *it << "|", it++);
        fout2 << " " << substr.size() << "\n";
        if (mismatch() <= mismatchLimit) counter++;
    }
    cf = counter;
    return counter;
}

double PrCounter::probability()
{
    return (double) cf / (double) numberOfIterations;
}

size_t PrCounter::equalityQuantity(size_t substrLen)
{
    return (double)cf / double(numberOfIterations);
}

void PrCounter::setSubstrLen(size_t size)
{
    substrLen = size;
}

void  PrCounter::getResult()
{
    //cout << S << " " << minimalSubstrLen << " " << maximalSubstrLen << "\n";
    fout2.open(rubbishOutput, ios_base::app);
    for (vector<int>::iterator it = S.begin(); it != S.end(); fout2 << *it << "|", it++);
    fout2 << " " << S.size();
    fout1.open(outputFile, ios_base::app);
    fout1 << SLen << ',' << substrLen << ',' << frequency() << ','<<probability() << "\n";
    fout1.close();
    fout2.close();
}

void PrCounter::reSet(size_t SL, size_t subLen, size_t nOI, size_t ML)
{
    SLen = SL;
    substrLen = subLen;
    numberOfIterations = nOI;
    mismatchLimit = ML;
}

void PrCounter::setSLen(size_t size)
{
    SLen = size;
}