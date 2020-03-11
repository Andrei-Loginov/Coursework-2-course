
#ifndef COURSWEORK2_RANDOMSEQUENCE_H
#include <iostream>
#include <vector>
#include <cstring>
#include <random>
#define COURSWEORK2_RANDOMSEQUENCE_H
/*
 * This class generates random amino acids sequence
 */

const std::vector<char> aminoAcidsAlphabet = {'A', 'R', 'N', 'D', 'B', 'C', 'E', 'Q', 'Z',
                                              'G', 'H', 'I', 'L', 'K', 'M', 'F', 'P', 'S',
                                              'T', 'W', 'Y', 'V'};


class RandomSequence {
public:
    RandomSequence();
    char *random(const size_t &len);
private:
    std::mt19937 randomGenerator_;
};


#endif //COURSWEORK2_RANDOMSEQUENCE_H
