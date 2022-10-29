class Solution {
public:
    int search(vector<int>& arr, int t) {
        int n = arr.size();
        
        int lo = 0;
        int hi = n-1;
        
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            
            if(arr[mid]==t) return mid;
            
            // left half sorted
            if(arr[mid]>=arr[0]){
                if(t>=arr[0] and t<arr[mid]) hi = mid-1;
                else lo = mid+1;
            }
            // right half sorted
            if(arr[mid]<=arr[hi]){
                if(t>arr[mid] and t<=arr[hi]) lo = mid+1;
                else hi = mid-1;
            }
        }
        
        return -1;
    }
};