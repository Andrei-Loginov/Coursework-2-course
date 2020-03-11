//
// Created by andrei on 10.03.2020.
//

#include "parasailFunction.h"

parasailFunction::parasailFunction(const parasail_matrix_t &matrix)
{
    substitutionMatrix = matrix;
}

parasailFunction::parasailFunction(parasail_result_t* (*function) (const char*, const int,  const char*, const int,
                                                                   const int, const int, const parasail_matrix_t*), const parasail_matrix_t &matrix)
{
    alignmentFunction = function;
    substitutionMatrix = matrix;
}

std::vector<iterationResult> parasailFunction::randomSequencesAlignment(int len1, int len2, int iterationsNumber)
{
    std::vector<iterationResult> ans;
    char *s1 = new char[len1 + 1];
    strcpy(s1, random(len1));
    for (int i = 0; i < iterationsNumber; ++i)
    {
        char *s2 = new char[len2 + 1];
        strcpy(s2, random(len2));
        parasail_result_t *res = alignmentFunction(s1, len1, s2, len2, 10000, 10000, &substitutionMatrix);
        ans.emplace_back(iterationResult(len1, len2, parasail_result_get_score(res)));
        parasail_result_free(res);
        delete[] s2;
    }
    return ans;
}