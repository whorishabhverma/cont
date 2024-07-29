#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
    public:
        int search(vector<int>& arr, int target) {
            // 4,5,6,7,0,1,2
            // 0,1,2,3,4,5,6
            //ye baat clear h ki ek part sorted hoga 
            int low=0,high=arr.size()-1;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(arr[mid]==target) return mid;
                //left sorted
                if(arr[low]<=arr[mid]){
                    if(arr[low]<=target && target<=arr[mid]){
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
                //right sorted
                else {
                    if(arr[mid+1]<=target && target<=arr[high]){
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }
            }
            return -1;
        }
    };

    // ***********************************************************************************************
    // https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
  
            bool search(vector<int>& arr, int target) {
                // 2,5,6,0,0,1,2
                // 0,1,2,3,4,5,6
                // 0
        
                // 1,0,1,1,1 target = 0 ;
                // 0,1,2,3,4
        
        
                //3,1,2,3,3,3,3 not able to find sorted half
        
        
                int low=0,high=arr.size()-1;
                while(low<=high){
                    int mid = low+(high-low)/2;
                    if(arr[mid]==target) return true;
                    if(arr[low]==arr[mid] && arr[mid]==arr[high]){
                        low++;high--; continue;
                    }
        
                    //left sorted
                    if(arr[low]<=arr[mid]){
                        if(arr[low]<=target && target<=arr[mid]){
                            high=mid-1;
                        }
                        else{
                            low=mid+1;
                        }
                    }
                    //right sorted
                    else {
                        if(arr[mid+1]<=target && target<=arr[high]){
                            low=mid+1;
                        }
                        else{
                            high=mid-1;
                        }
                    }
                }
                return false;
            }
        
// ************************************************************************************************************
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
        int findMin(vector<int>& arr) {
            int low=0,high=arr.size()-1,ans=INT_MAX;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(arr[low]<=arr[high]){
                    ans=min(ans,arr[low]);
                    break;
                }
                if(arr[low]<=arr[mid]){
                    ans=min(ans,arr[low]);
                    low=mid+1;
                }
                else{
                    ans=min(ans,arr[mid]);
                    high=mid-1;
                }
            }
    
            //low<=high ans cal break
            //low<=mid ans low=mid+1 //left half
            //mid<=high ans high=mid-1
            return ans;
        }

// **********************************************************************************************************
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
//repeated
    int findMin(vector<int>& arr) {
        int low=0,high=arr.size()-1,ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[low]==arr[mid] && arr[high]==arr[mid]){
            ans=min(ans,arr[low]);
            low=low+1;
            high=high-1;
            continue;
            }
            if(arr[low]<=arr[mid]){
                ans=min(ans,arr[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,arr[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
// *************************************************************************************
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int x=0; for(int i=0;i<nums.size();i++)  x=x^nums[i];   return x;
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low=1,high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if((nums[mid]!=nums[mid-1]) && (nums[mid]!=nums[mid+1])) return nums[mid];
            //left half
            if(((mid%2==1) && (nums[mid]==nums[mid-1])) || ((mid%2==0) && (nums[mid]==nums[mid+1]))){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};





// *****************************************************************************************************************
// https://leetcode.com/problems/single-element-in-a-sorted-array/description/
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
    
