#include <bits/stdc++.h>
using namespace std;

// space optimsation in tabulation way
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    int prev1 = nums[0];
    int prev2 = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int curr = max(nums[i] + prev1 , prev2) ;
        prev1 = prev2 ; 
        prev2 = curr ;
    }
    return prev2;
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