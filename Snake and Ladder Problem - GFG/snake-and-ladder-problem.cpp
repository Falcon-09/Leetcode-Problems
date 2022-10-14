//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int n, int arr[]){
        // code here
        vector<int> con(31,-1);
        
        for(int i=0;i<2*n;i+=2){
            con[arr[i]]=arr[i+1];
        }
        
        int ans=0;
        queue<int> q;
        q.push(1);
        vector<int> vis(31,0);
        vis[1]=1;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                int cur = q.front();
                q.pop();
                if(cur==30) return ans;
                for(int i=cur+1;i<=cur+6;i++){
                    if(i>30) break;
                    if(vis[i]==1) continue;
                    vis[i]=1;
                    if(con[i]==-1) q.push(i);
                    else q.push(con[i]);
                }
            }
            ans++;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends