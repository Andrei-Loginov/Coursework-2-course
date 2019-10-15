#include "RandomString.h"
#include "PrCounter.h"

int main()
{
    char outf[] = "res.txt";
    char rf[] = "rubbish.txt";
    ULL strLen, minSubstrLen, maxSubstrLen, nOI, mismatchNumber;
    ofstream f;
    f.open("rubbish.txt", ios_base::trunc);
    f.close();
    f.open("res.txt", ios_base::trunc);
    f << "StringLength,SubstringLenght,Probability\n";
    f.close();
    cout << "Enter length of the string: ";
    cin >> strLen;
    cout << "Enter the minimal length of substring: ";
    cin >> minSubstrLen;
    cout << "Enter the maximal length of substring: ";
    cin >> maxSubstrLen;
    cout << "Enter the number of iterations for everry substring length: ";
    cin >> nOI;
    cout << "Enter the quantity of premissible mismathes: ";
    cin >> mismatchNumber;
    PrCounter p(strLen, minSubstrLen, maxSubstrLen, nOI, mismatchNumber, outf, rf);
    RandomString rs;
    p.getResult();
    return 0;
}