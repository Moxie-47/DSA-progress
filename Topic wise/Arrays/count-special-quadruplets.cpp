#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countQuadruplets(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        int n = nums.size() ;
        for (int i = 1 ; i<n ; i++)
        {
            for(int j = 0 ; j<i ;j++){
                mp[nums[i]+nums[j]]++ ;
            }
            for(int k = i+2 ; k<n ; k++){
                ans+= mp[nums[k]-nums[i+1]] ;
            }
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