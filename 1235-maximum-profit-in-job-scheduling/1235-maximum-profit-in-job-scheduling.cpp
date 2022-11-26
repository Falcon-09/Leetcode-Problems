class Solution {
public:
    
    int dp[100005];
    
    class Job{
        public:
        int s;
        int e;
        int p;
        
        Job(int s,int e,int p){
            this->s = s;
            this->e = e;
            this->p = p;
        }
    };
    
    static bool cmp(Job a,Job b){
        if(a.s!=b.s) return a.s<b.s;
        return a.e<b.e;
    }
    
   
    int f(int i,vector<Job> &arr,vector<int> &st){
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        // not pick
        int no = f(i+1,arr,st);
        // pick
        int yes = 0;
        int idx = lower_bound(st.begin(),st.end(),arr[i].e)-st.begin();
        yes = arr[i].p + f(idx,arr,st);
        return dp[i] = max(yes,no);
    }
    
    int jobScheduling(vector<int>& st, vector<int>& en, vector<int>& pr) {
        vector<Job> v;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<st.size();i++){
            v.push_back(Job(st[i],en[i],pr[i]));
        }
        sort(v.begin(),v.end(),cmp);
        sort(st.begin(),st.end());
        
        return f(0,v,st);
    }
};