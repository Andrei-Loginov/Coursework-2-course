#include "RandomSequence.h"
#include "parasailFunction.h"
#include <algorithm>
#include <string>
#include <fstream>

char* filename(int len1, int len2) //returns name for the output file: res_<first sequence length>_<second sequence length>.csv
{
    std::string s = "res_";
    std::vector<int> num;
    while (len1 > 0)
    {
        num.push_back(len1%10);
        len1 /= 10;
    }
    reverse(num.begin(), num.end());
    for (int x: num)
    {
        s.push_back((char)((int)'0' + x));
    }
    num.clear();
    s += "_";
    while (len2 > 0)
    {
        num.push_back(len2%10);
        len2 /= 10;
    }
    reverse(num.begin(), num.end());
    for (int x: num)
    {
        s.push_back((char)((int)'0' + x));
    }
    num.clear();
    s += ".csv";
    char *ans = new char[s.size()+1];
    ans[s.size()] = '\0';
    for (int i = 0; i < s.size(); i++)
        ans[i] = s[i];
    return ans;
}


int main()
{
    std::ifstream fin("start_config.txt");
    std::cout << "Hello, world!\n";
    if (fin.is_open()) std::cout << "The file has been opened successfully\n";
    int firstStringLength, secondStringLengthLowerBound, secondStringLengthUpperBound, iterationsNumber;
    fin >> firstStringLength >> secondStringLengthLowerBound >> secondStringLengthUpperBound >> iterationsNumber;
    std::vector <iterationResult> ans;
    parasailFunction semiGlobal(parasail_sg, parasail_blosum75); //WATCH HERE!!!!
    for (int i = secondStringLengthLowerBound; i <= secondStringLengthUpperBound; i++)
    {
        std::ofstream fout(filename(firstStringLength, i), std::ios_base::trunc);
        if (fout.is_open()) std::cout << "The output file has been opened successfully\n";
        ans.clear();
        ans = semiGlobal.randomSequencesAlignment(firstStringLength, i, iterationsNumber);
        std::cout << filename(firstStringLength, i) << "\n";
        fout << "FirstSequenceLength,SecondSequenceLength,AlignmentScore\n";
        for (iterationResult x: ans)
            fout << x.firstSequenceLength << ',' << x.secondSequenceLength << ',' << x.alignmentScore << '\n';
        fout.close();
    }
    return 0;
}