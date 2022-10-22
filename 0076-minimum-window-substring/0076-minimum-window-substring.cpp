class Solution {
public:
    string minWindow(string s, string t) {
        
        int n=s.size();
        int m=t.size();
        string res="";
        
        if(n<m)
            return res;
        
        unordered_map<char,int>m1,m2;
        for(auto it:t) m1[it]++;
        
        
        int i=0;
        int j=0;
        int count=0;
        int len=INT_MAX;
        int startIndex=-1;
        
        while(j<n)
        {
            m2[s[j]]++;
            
            if(m2[s[j]]<=m1[s[j]])
            {
                count++;
            }
            if(count==m)
            {
                
              //  cout<<i<<" "<<j<<endl;
                
                while(m2[s[i]]>m1[s[i]] or m1[s[i]]==0)
                {
                    
                    if(m2[s[i]]>m1[s[i]])
                    m2[s[i]]--;
                    
                    i++;
                    
                }
                //cout<<i<<endl;
                
                int found=j-i+1;
                if(len>found)
                {
                    len=found;
                    startIndex=i;
                }
               
            }
            j++;
        }
        if(startIndex==-1)
            return "";
        return s.substr(startIndex,len);
        
    }
};