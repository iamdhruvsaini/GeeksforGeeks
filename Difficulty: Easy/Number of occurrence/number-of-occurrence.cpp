//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lastOccurence(vector<int>& arr, int target){
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            
            if(arr[mid]==target){
                ans=mid;
                s=mid+1;
            }
            else if(arr[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    int firstOccurence(vector<int>& arr, int target){
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            
            if(arr[mid]==target){
                ans=mid;
                e=mid-1;
            }
            else if(arr[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        int firstOcc=firstOccurence(arr,target);
        int lastOcc=lastOccurence(arr,target);
        if(firstOcc==-1)return 0;
        return lastOcc-firstOcc+1;
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends