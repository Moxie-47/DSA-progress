#include <bits/stdc++.h>
using namespace std;

void Helper(const vector<int> &nums, int i, int temp, int &ans)
{
    if (i >= nums.size())
    {
        ans = max(ans, temp);
        return;
    }

    Helper(nums, i + 2, temp + nums[i], ans);
    Helper(nums, i + 1, temp, ans);
}

int rob(vector<int> &nums)
{
    int temp = 0;
    Helper(nums, 0, 0, temp);
    return temp;
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