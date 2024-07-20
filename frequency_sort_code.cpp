#include<bits/stdc++.h>
using namespace std;
// comparator works in prority_queue only if they are a class which has
// operator() overloaded in it
struct CompareSecond {
    bool operator()(const std::pair<int, int>& left, const std::pair<int, int>& right) {
        // Order by the second element of the pair
        // For min heap, use ">" for max heap, use "<"
        if (left.first != right.first) {
            return left.first < right.first; // Sort by frequency (descending)
        }
        return left.second > right.second; 
    }
};
void frequencySort(vector<int>&arr){
    vector<int>ans;
    map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int, int>>, CompareSecond> maxH;
    for(auto ele:mp){
        maxH.push({ele.second,ele.first});
    }
    arr.clear();
    while(!maxH.empty()){
        int freq  = maxH.top().first;
        int  num  = maxH.top().second;
        while(freq){
            arr.push_back(num);
            freq--;
        }
        maxH.pop();
    }
}
int main(){
    vector<int> arr = {1,-2,2,-1,1,3,4,4,5,6,5,7,1};
    frequencySort(arr);
    for(auto ele:arr) cout<<ele<<" "; 
}