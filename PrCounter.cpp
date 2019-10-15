#include "PrCounter.h"

PrCounter::PrCounter()
{
#ifdef DEBUG
    cout << "PrCounter()\n";
#endif
}

PrCounter::PrCounter(ULL SL, ULL minSL, ULL maxSL, ULL nOI, ULL ML, char* outFile): SLen(SL), minimalSubstrLen(minSL), maximalSubstrLen(maxSL), numberOfIterations(nOI), mismatchLimit(ML), outputFile(outFile)
{
    srand(time(nullptr));
    S = random(SL);
    fout1.open(outFile, ios_base::app);
    //fout1 << "For the string " << S << ":\n";
#ifdef DEBUG
    cout << "PrCounter::PrCounter(ULL, ULL, ULL, ULL, char*)\n";
#endif
}

PrCounter::PrCounter(ULL SL, ULL minSL, ULL maxSL, ULL nOI, ULL ML, char* outFile, char* rubbishOut): SLen(SL), minimalSubstrLen(minSL), maximalSubstrLen(maxSL), numberOfIterations(nOI), mismatchLimit(ML)
{
    outputFile = outFile;
    rubbishOutput = rubbishOut;
    S = random(SL);
    //fout2.open(rubbishOut, ios_base::app);
    //fout2 << S <<"\n";
    //fout2 << S.size() << ' ' << S << "\n";
#ifdef DEBUG
    cout << "PrCounter::PrCounter(ULL, ULL, ULL, ULL, char*)\n";
#endif
}


PrCounter::~PrCounter()
{
#ifdef DEBUG
    cout << "PrCounter::~Prcounter()\n";
#endif
}

ULL PrCounter::mismatch()
{
    unsigned long long ans = substr.size();
    //cout << substr.size() << "\n";
    for (ULL i = 0; i < S.size() - substr.size(); i++)
    {
        ULL k = 0;
        //cout << "SSSSSSSS " << S.size() << " " << substr.size() << " " << i << "\n";
        for (ULL j = 0; j < substr.size(); j++)
        {
            if (substr[j] != S[i + j]) k++;
            if (k > mismatchLimit) k = ans;
        }
        if (k < ans) ans = k;
    }
    return ans;
}

double PrCounter::probability(ULL substrLen)
{
    ULL counter = 0;
    //cout << "Substrlen is: " << substrLen << "\n";
    for (ULL i = 0; i < numberOfIterations; i++)
    {
        substr = random(substrLen);
        //cout << substr << "\n";
        fout2 << substr << " " << substr.size() << "\n";
        if (mismatch() <= mismatchLimit) counter++;
    }
    return (double)counter / (double)numberOfIterations;
}

ULL PrCounter::equalityQuantity(ULL substrLen)
{
    ULL counter = 0;
    for (ULL i = 0; i < numberOfIterations; i++)
    {
        substr = random(substrLen);
        //cout << substr << "\n";
        fout2 << substr << " " << substr.size() << "\n";
        if (mismatch() <= mismatchLimit) counter++;
    }
    return counter;
}

void  PrCounter::getResult()
{
    //cout << S << " " << minimalSubstrLen << " " << maximalSubstrLen << "\n";
    fout2.open(rubbishOutput, ios_base::app);
    fout2 << S << " " << S.size() << "\n";
    for (ULL i = minimalSubstrLen; i <= maximalSubstrLen; i++)
    {
        fout1.open(outputFile, ios_base::app);
        fout1 << SLen << ',' << i << ',' << probability(i) << "\n";
        fout1.close();
    }
    fout2.close();
}

void PrCounter::reSet(ULL SL, ULL minSL, ULL maxSL, ULL nOI, ULL ML)
{
    SLen = SL;
    minimalSubstrLen = minSL;
    maximalSubstrLen = maxSL;
    numberOfIterations = nOI;
    mismatchLimit = ML;
}