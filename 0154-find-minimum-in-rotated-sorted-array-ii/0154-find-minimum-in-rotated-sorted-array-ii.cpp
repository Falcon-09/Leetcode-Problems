class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        
        if(n==1 or arr[0]<arr[n-1]) return arr[0];
        
        int lo = 0;
        int hi = n-1;
        int ans = 1e9;
        
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(arr[mid]>arr[hi]) lo = mid+1;
            else if(arr[mid]==arr[hi]) {
                ans = min(ans,arr[mid]);
                hi--;
            }
            else {
                ans = min(ans,arr[mid]);
                hi = mid-1;
            }
        }
        
        return ans; 
    }
};