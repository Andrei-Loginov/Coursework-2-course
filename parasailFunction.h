//
// Created by andrei on 10.03.2020.
//

#ifndef COURSWEORK2_PARASAILFUNCTION_H
#include "RandomSequence.h"
#include <parasail.h>
#include <parasail/matrices/blosum35.h>
#include <parasail/matrices/pam50.h>
#include <parasail/matrices/blosum75.h>

#include <cstring>
#include <iostream>
#define COURSWEORK2_PARASAILFUNCTION_H

struct iterationResult{
    size_t firstSequenceLength, secondSequenceLength;
    int alignmentScore;
    iterationResult(const size_t &len1, const size_t &len2, int score)
    {
        firstSequenceLength = len1;
        secondSequenceLength = len2;
        alignmentScore = score;
    }
};

class parasailFunction : public RandomSequence {
public:
    parasailFunction(const parasail_matrix_t &matrix);
    parasailFunction(parasail_result_t* (*function) (const char*, const int,  const char*, const int,
                                                     const int, const int, const parasail_matrix_t*), const parasail_matrix_t &matrix);
    parasail_result_t* (*alignmentFunction) (const char*, const int,  const char*, const int,
                                             const int, const int, const parasail_matrix_t*);
    std::vector <iterationResult> randomSequencesAlignment(int len1, int len2, int iterationsNumber);
private:
    parasail_matrix_t substitutionMatrix;
};


#endif //COURSWEORK2_PARASAILFUNCTION_H
