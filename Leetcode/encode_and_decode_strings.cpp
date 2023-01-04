#include <bits/stdc++.h>

using namespace std;

string encode(vector<string> &strs)
{
    string ans = "";
    for (auto &str : strs)
    {
        ans += to_string(str.length()) + "#" + str;
    }

    return ans;
}

vector<string> decode(string str)
{
    vector<string> strs;
    int i = 0;
    while (i < str.length())
    {
        int len = 0;
        // get length
        while (str[i] != '#')
        {
            len = (len * 10) + (str[i] - '0');
            i += 1;
        }

        strs.push_back(str.substr(i + 1, len));

        i += len + 1;
    }

    return strs;
}

int main()
{
    // boilerplate for question
    int n;
    cin >> n;
    vector<string> strs;

    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        strs.push_back(a);
    }

    string es = encode(strs);
    cout << "Encoded : " << es << endl;

    vector<string> ds = decode(es);
    cout << "Decoded : ";

    for (auto &str : ds)
        cout << str << " ";
    cout << endl;

    if (ds == strs)
        cout << "Match" << endl;
    else
        cout << "ERROR" << endl;

    return 0;
}