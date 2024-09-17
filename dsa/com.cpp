#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (ind == arr.size())
        {
            // cout<< ind << endl;
            if (target == 0)
            {
                ans.push_back(ds);
            }
        }

        if (arr[ind] <= target)
        {
            // cout<< ind << endl;
            ds.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, ds); // repeatedly picking same element case
            ds.pop_back();
        }
        findCombination(ind + 1, target, arr, ans, ds); // not picking and moving to next element
    }

public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int> > ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

int main()
{
    // sort array and delete duplicates
    Solution sol;
    vector<vector<int> > ans;
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(6);
    candidates.push_back(7);
    ans = sol.combinationSum(candidates, 10);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<)
    }
}