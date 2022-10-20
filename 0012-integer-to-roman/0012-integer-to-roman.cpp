class Solution {
public:
    string intToRoman(int num) {
        vector<int> code = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s[20] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string ans;
        
        for(int i=0;i<code.size();i++){
            while(num>=code[i]){
                ans+=s[i];
                num-=code[i];
            }
        }
        
        return ans;
    }
};