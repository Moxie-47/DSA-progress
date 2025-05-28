
#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> prePro;
    vector<int> ans;
    vector<int> SuffPro;
    int pref = 1;
    int n = nums.size();
    prePro.push_back(pref);
    for (int i = 0; i < n - 1; i++)
    {
        pref *= nums[i];
        prePro.push_back(pref);
    }

    int suff = 1;
    SuffPro.push_back(suff);
    for (int i = n - 1; i > 0; i--)
    {
        suff *= nums[i];
        SuffPro.push_back(suff);
    }

    reverse(SuffPro.begin(), SuffPro.end());
    for (int i = 0; i < n; i++)
    {
        ans.push_back(prePro[i] * SuffPro[i]);
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
        cout<<productExceptSelf(arr)<<endl;
    }
    return 0;
}