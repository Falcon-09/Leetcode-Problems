//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        int ans = 1e9;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])!=mp.end()){
                ans = min(ans,mp[arr[i]]);
            }
            else{
                mp[arr[i]]=i+1;
            }
        }
        
        return ans>=1e9?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends