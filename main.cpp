#include "RandomString.h"
#include "PrCounter.h"

int main()
{
    char outf[] = "res.txt";
    char rf[] = "rubbish.txt";
    ofstream f;
    f.open("rubbish.txt", ios_base::trunc);
    f.close();
    f.open("res.txt", ios_base::trunc);
    f << "StringLength,SubstringLenght,Probability\n";
    f.close();
    PrCounter p(200, 3, 60, 1000000, 0, outf, rf);
    RandomString rs;
    p.getResult();
    return 0;
}