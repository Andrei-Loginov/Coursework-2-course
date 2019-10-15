#ifndef SIGN_PRCOUNTER_H
#include "RandomString.h"
#define SIGN_PRCOUNTER_H



class PrCounter: public RandomString
{
public:
    PrCounter();
    PrCounter(ULL SL, ULL  minSL, ULL maxlSL, ULL nOI, ULL ML, char *outFile);
    PrCounter(ULL SL, ULL  minSL, ULL maxlSL, ULL nOI, ULL ML, char *outFile, char* rubbishOut);
    ~PrCounter();
    ULL mismatch();
    double probability(ULL substrLen);
    ULL equalityQuantity(ULL substrlen);
    void getResult();
    void reSet(ULL SL, ULL minSL, ULL maxSL, ULL nOI, ULL ML);
private:
    ULL SLen, minimalSubstrLen, maximalSubstrLen, numberOfIterations, mismatchLimit;
    string S, substr;
    char* outputFile, *rubbishOutput;
    ofstream fout1, fout2;
};


#endif //SIGN_PRCOUNTER_H