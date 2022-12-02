class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>v(26,0),v1(26,0);
        unordered_set<char>st;
        if(word1.size()!=word2.size())
        {
            return false;
        }
        for(int i=0;i<word1.size();i++)
        {
            v[word1[i]-'a']++;
            v1[word2[i]-'a']++;
            st.insert(word1[i]);
        }
        sort(v.begin(),v.end());
        sort(v1.begin(),v1.end());
        for(auto it: word2)
        {
            if(st.find(it)==st.end())
            {
                return false;
            }
        }
        return v==v1;
    }
};