#include <bits/stdc++.h>
using namespace std;

bool CheckPalindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while (i <= j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

string longestPalindrome(string s)
{
    if (s.length() == 1)
        return s;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            if (CheckPalindrome(s.substr(i, j - i + 1)) &&
                j - i + 1 > ans.length())
            {
                ans = s.substr(i, j - i + 1);
            }
        }
    }
    return ans;
}

int main()
{
    int test_case = -1;
    cin >> test_case;

    while (test_case--)
    {
        string s = "";
        cin >> s;
        cout << "The longest Palindrome : "<<longestPalindrome(s)<<endl;
    }
    return 0;
}