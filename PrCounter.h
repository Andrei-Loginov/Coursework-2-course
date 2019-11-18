#ifndef SIGN_PRCOUNTER_H
#include "RandomString.h"
#define SIGN_PRCOUNTER_H



class PrCounter: public RandomString
{
public:
    PrCounter();
    PrCounter(size_t SL, size_t subLen, size_t nOI, size_t ML, int alphabetSz,  char *outFile);
    PrCounter(size_t SL, size_t subLen, size_t nOI, size_t ML, int alphabetSz, char *outFile, char* rubbishOut);
    ~PrCounter();
    size_t mismatch();
    size_t equalityQuantity(size_t substrlen);
    void getResult();
    void reSet(size_t SL, size_t subLen, size_t nOI, size_t ML);
    void setSubstrLen(size_t size);
    void setSLen(size_t size);
private:
    int alphabetSize;
    size_t SLen, substrLen, numberOfIterations, mismatchLimit;
    vector<int> S, substr;
    const char* outputFile;
    const char *rubbishOutput;
    ofstream fout1, fout2;
    size_t frequency();
    size_t cf;
    double probability();
};


#endif //SIGN_PRCOUNTER_H