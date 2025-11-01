//merge Sort 
#include <iostream>
#include <vector>
using namespace std;


//merge comparisions
void merge(vector<int>&arr, int low, int mid, int high)
{
    vector<int> temp;
    // left[low..mid]
    //right[mid+1..high]
    int left = low;
    int right = mid+1;
    while (left<=mid&&right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }

    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
     while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++)
    {
        arr[i]= temp[i-low];

    }

}
//recursive steps
void mergeSort(vector<int> &arr, int low, int high)
{

 if(low>=high) return;
 int mid= (low+high)/2;
 mergeSort(arr, low, mid);
  mergeSort(arr, mid+1, high);
  merge(arr, low, mid, high);

}




int main(){

       vector <int > arr= {3,4,5,4,7,0,1,2,9,6};
       mergeSort(arr, 0, 10);
       for (int x : arr) cout << x << " ";


}
