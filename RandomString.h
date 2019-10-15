#pragma once
#ifndef RANDOMSTRING_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
#define RANDOMSTRING_H
//#define DEBUG
#define ULL unsigned long long

class RandomString
{
public:
    RandomString();
    ~RandomString();
    string random(unsigned long long len);
    string intToString(ULL x, int radix);
private:
    string r;
};

#endif