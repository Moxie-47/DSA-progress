#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans;
    int temp = 1;
    int n = nums.size();
    ans.push_back(temp);

    for (int i = 0; i < n - 1; i++)
    {
        temp *= nums[i];
        ans.push_back(temp);
    }
    temp = 1;
    for (int i = n - 1; i > 0; i--)
    {
        temp *= nums[i];
        ans[i - 1] = temp * ans[i - 1];
    }
    return ans;
}

int main()
{
    int test_case = -1;
    cin >> test_case;

    while (test_case--)
    {
        int n = 0;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << productExceptSelf(arr) << endl;
    }
    return 0;
}