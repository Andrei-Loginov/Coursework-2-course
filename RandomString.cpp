#include "RandomString.h"

RandomString::RandomString()
{
#ifdef DEBUG
    cout << "RandomString::RandomString()\n";
#endif
    random_device rd;
    random_generator.seed(rd());
}

RandomString::~RandomString()
{
#ifdef DEBUG
    cout << "RandomString::~RandomString";
#endif
    if (!r.empty()) r.clear();
}

string RandomString::intToString(size_t x, int radix)
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

vector<int> RandomString::random(size_t len, int radix)
{
#ifdef DEBUG
    cout << "RandomString::random(ULL, int)";
#endif
    uniform_int_distribution<int> dist(0, radix - 1);
    r.resize(len);
    for (vector<int>::iterator iter = r.begin(); iter != r.end(); iter++)
        *iter = dist(random_generator);
    return r;
}

string RandomString::getString()
{
    string ans;
    for (int i = 0;i < r.size(); i++)
        ans += intToString(r[i], 10);
    return ans;
}