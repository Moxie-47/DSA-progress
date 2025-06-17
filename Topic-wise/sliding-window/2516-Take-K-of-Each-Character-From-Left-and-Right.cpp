#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        if (k == 0)
            return 0;

        int total[3] = {0};
        for (char c : s)
            total[c - 'a']++;

        for (int i = 0; i < 3; i++)
        {
            if (total[i] < k)
                return -1;
        }

        int n = s.size();
        int maxWindow = 0;
        int freq[3] = {0};
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            freq[s[right] - 'a']++;

            while (freq[0] > total[0] - k || freq[1] > total[1] - k ||
                   freq[2] > total[2] - k)
            {
                freq[s[left] - 'a']--;
                left++;
            }

            maxWindow = max(maxWindow, right - left + 1);
        }

        return n - maxWindow;
    }
};

int main()
{
    int test_case = -1;
    cin >> test_case;
    while (test_case--)
    {
        string str = "";
        int k = 0;
        cin >> str >> k;
        Solution s;
        cout << "The answer is : " << s.takeCharacters(str, k) << endl;
    }
}