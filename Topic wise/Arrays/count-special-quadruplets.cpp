#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countQuadruplets(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = nums.size() - 1; i >= 2; i--)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                for (int k = j - 1; k >= 0; k--)
                {
                    if (mp[nums[i] + nums[j] + nums[k]])
                    {
                        ans += mp[nums[i] + nums[j] + nums[k]];
                    }
                }
            }
            mp[nums[i]]++ ;
        }
        return ans;
    }
};

int main()
{
    int test_case = 0;
    cin >> test_case;
    while (test_case--)
    {
        int n = 0;
        cin >> n;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        Solution s;
        cout << s.countQuadruplets(nums) << endl;
    }
    return 0;
}