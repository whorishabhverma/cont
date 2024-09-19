#include<bits/stdc++.h>
using namespace std;


//bubble sort 
void bubble_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
// Time Complexity:
// Worst Case: O(n²)
// Average Case: O(n²)
// Best Case: O(n) (when the array is already sorted)


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped in inner loop, then the array is already sorted
        if (!swapped)
            break;
    }
}


//selection sort
void selection_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<=n-2;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
}
// Worst Case: O(n²)
// Average Case: O(n²)
// Best Case: O(n²) (even when the array is already sorted)


//insertion sort
void insertion_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=1;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
//same as bubble

//merge sort
void merge(vector<int>&arr,int low,int mid,int high){


    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left <=mid && right <=high)
{
    if(arr[left]<arr[right])
    {
        temp.push_back(arr[left]);
        left++;
    }
    else{
        temp.push_back(arr[right]);
        right++;
    }
}

while(left<=mid){
    temp.push_back(arr[left]);
        left++;
}

while(right <= high){
     temp.push_back(arr[right]);
        right++;
}
for(int i=low;i<=high;i++){
    arr[i]=temp[i-low];
}
}
void merges(vector<int> &arr ,int low ,int high){
    if(low == high) return;
    int mid=(low+high)/2;
    merges(arr,low,mid);
    merges(arr,mid+1,high);
    merge(arr,low,mid,high);
}
// Worst Case: O(n log n)
// Average Case: O(n log n)
// Best Case: O(n log n)
// sc : O(n)



//quick sort using pivot as last element 
int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int i=low;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<=pivot){
           swap(arr[j],arr[i]);
           i++;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
// Best/Average Case: O(n log n) when the pivot splits the array into two roughly equal parts.
// Worst Case: O(n²) when the pivot is the smallest or largest element, causing unbalanced partitions. This can be mitigated by choosing a better pivot (like random pivot selection).


int main(){
    vector<int> arr ={3,2,1,4,87,63,5,2};
    insertion_sort(arr);
    for(auto ele:arr){
        cout<<ele<<" ";
    }
}