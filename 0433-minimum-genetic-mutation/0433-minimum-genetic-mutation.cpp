class Solution {
public:
    int minMutation(string s, string e, vector<string>& b) {
        int n = b.size();
        if(s==e) return 0;
        
        unordered_set<string> chk,seen;
        unordered_set<char> ch;
        
        ch.insert('A');ch.insert('C');ch.insert('G');ch.insert('T');
        
        for(auto x:b) chk.insert(x);
        
        queue<string> q;
        q.push(s);
        seen.insert(s);
        int ans = 0;
        
        while(!q.empty()){
            int k = q.size();
            ans++;
            while(k--){
                string t = q.front();
                q.pop();
                for(int i=0;i<t.size();i++){
                    for(auto x:ch){
                        string ns = t;
                        ns[i] = x;
                        if(seen.find(ns)==seen.end() and chk.find(ns)!=chk.end()){
                            if(ns==e) return ans;
                            seen.insert(ns);
                            q.push(ns);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};