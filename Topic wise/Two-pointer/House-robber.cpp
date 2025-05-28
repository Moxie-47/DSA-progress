#include <bits/stdc++.h>
using namespace std;

int Helper(const vector<int> &nums, int i, vector<int> &dp)
{
    if (i >= nums.size())
    {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];
    return dp[i] = max(nums[i] + Helper(nums, i + 2, dp),
                       Helper(nums, i + 1, dp));
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    Helper(nums, 0, dp);
    return dp[0];
}

int main()
{
    int test_case = -1;
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
        cout << "Rob : " << rob(nums) << endl;
    }
    return 0;
}