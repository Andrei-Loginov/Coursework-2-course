#include "RandomString.h"
#include "PrCounter.h"
#include "MatchScanner.h"

int main()
{
    ifstream fin("start_config.txt");
    ofstream fout("res.csv", ios_base::trunc);
    fout << "Cardinality,StringLength,NumberOfMatches,NumberOfAppearances\n";
    fout.close();
    if (fin.is_open()) cout << "The file has been opened successfully\n";
    char outf[] = "res.txt";
    char rf[] = "rubbish.txt";
    size_t strLen, nOI;
    int al;
    ofstream f;
    f.open("rubbish.txt", ios_base::trunc);
    f.close();
    fin >> al >> strLen >> nOI;
    MatchScanner ms(strLen, nOI, al);
    ms.getres().outf("res.csv");
    return 0;
}