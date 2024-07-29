///////////////////////////////////////////////////////////////////
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid>0 && mid<n-1 && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            //i am on left half so eliminate left
            if(mid%2==0 && mid+1<n && nums[mid]==nums[mid+1] || mid%2==1 && mid-1>=0 && nums[mid]==nums[mid-1] ){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return nums[low];
    }
};

///////////////////////////////////////////////////////////////////////////////////////////
https://leetcode.com/problems/single-number-ii/description/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bitIndex=0;bitIndex<=31;bitIndex++){
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                //check ith bit set or not
                if(nums[i] & (1<<bitIndex)){
                    cnt++;
                }
            }
            if(cnt%3==1){
                //set ith bit 
                ans = ans | (1<<bitIndex);
            }
        }
        return ans;
    }
};



//////////////////////////////////////////////////////
https://leetcode.com/problems/single-number-iii/
class Solution {
public:

    vector<int> singleNumber(vector<int>& nums) {
        long long zor=0;
        for(auto ele:nums) zor=zor^ele;
        long long diff = zor & -zor;
        int groupA = 0;
        int groupB = 0;
        for(auto ele:nums){
             if (ele & diff){
                groupA^=ele;
             }
             else{
                groupB^=ele;
             }
        }
        return {groupA,groupB};
    }
};

   

