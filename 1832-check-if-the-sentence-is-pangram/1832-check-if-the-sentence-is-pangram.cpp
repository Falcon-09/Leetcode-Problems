class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_set<char> st;
        
        st.insert(s.begin(),s.end());
        
        return st.size()==26;
    }
};