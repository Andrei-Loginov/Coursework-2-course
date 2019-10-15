#include "RandomString.h"

RandomString::RandomString()
{
#ifdef DEBUG
    cout << "RandomString::RandomString()\n";
#endif
    srand(time(nullptr));
}

RandomString::~RandomString()
{
#ifdef DEBUG
    cout << "RandomString::~RandomString";
#endif
    if (!r.empty()) r.clear();
}

string RandomString::intToString(int x, int radix)
{
#ifdef DEBUG
    cout << "RandomString::intToString(int, int)\n";
#endif
    string ans;
    while (x > 0)
    {
        ans.insert(ans.begin(), (char)((int)'0' + x % radix));
        x /= radix;
    }
    return ans;
}

string RandomString::random(unsigned long long len)
{
#ifdef DEBUG
    cout << "RandomString::random(int)";
#endif
    string s;
    if (!r.empty()) r.clear();
    while (len > 31)
    {
        s = intToString(rand() % (int)pow(2, 31), 2);
        while (s.size() < 31)
            s.insert(s.begin(),'0');
        r.insert(r.begin(), s.begin(), s.end());
        len -= 31;
    }
    s = intToString(rand() % (int)pow(2, len), 2);
    while (s.size() < len)
        s.insert(s.begin(),'0');
    r.insert(r.begin(), s.begin(), s.end());
    return r;
}