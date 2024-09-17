//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool comp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

class Solution {
  public:
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int, int> mp;
        vector<pair<int, int>> vec;
        for(auto it: arr){
            mp[it]++;
        }
        for(auto it: mp){
            vec.push_back({it.second, it.first});
        }
        sort(vec.begin(), vec.end(), comp);
        
        vector<int> ans;
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].first;j++){
                ans.push_back(vec[i].second);
            }
        }
        // for(auto it: vec){
        //     ans.insert(ans.end(), it.first, it.second);  // it.first ko it.second time ans me daala
        // }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends