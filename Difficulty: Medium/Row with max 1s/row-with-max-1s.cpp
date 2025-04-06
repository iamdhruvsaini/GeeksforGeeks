//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int search(vector<int> &temp){
        int n=temp.size();
        int s=0;
        int e=n-1;
        int first=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            
            if(temp[mid]==1){
                //search any before
                first=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        if(first==-1)return -1;
        return n-first;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int r=arr.size();
        int c=arr[0].size();
        int ones=0,index=-1;
        for(int i=0;i<r;i++){
            // find first most occurence of 1
            int cnt=search(arr[i]);
            if(cnt>ones){
                index=i;
                ones=cnt;
            }
        
        }
        
        return index;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the integer input
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        cout << obj.rowWithMax1s(mat);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends