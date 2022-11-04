class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        set<char> v = {'a','e','i','o','u','A','E','I','O','U'};
        int i = 0;
        int j = n-1;
        while(i<j){
            if(v.find(s[i])==v.end()) i++;
            else if(v.find(s[j])==v.end()) j--;
            else {
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        
        return s;
    }
};