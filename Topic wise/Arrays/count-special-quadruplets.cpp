#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countQuadruplets(vector<int> &nums)
    {
        int ans = 0;
        // sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    for (int l = k + 1; l < nums.size(); l++)
                    {
                        if (nums[i] + nums[j] + nums[k] == nums[l])
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    int test_case = 0 ;
    cin>>test_case ;
    while (test_case--)
    {
        int n = 0 ;
        cin>>n ;
        vector<int>nums(n,0) ;
        for (int i = 0; i < n; i++)
        {
            cin>>nums[i] ;
        }
        Solution  s ;
        cout<<s.countQuadruplets(nums)<<endl;
    }
    return 0;
}