#pragma once
#ifndef RANDOMSTRING_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <random>
using namespace std;
#define RANDOMSTRING_H
//#define DEBUG
#define ULL unsigned long long

class RandomString
{
public:
    RandomString();
    ~RandomString();
    vector <int> random(size_t len, int radix);
    string intToString(size_t x, int radix);
    string getString(); //return the result of last random() call
private:
    mt19937 random_generator;
    vector <int> r;
};

#endif