class Solution {
public:
    int evaluate(int a, int b,string y){
        if(y=="+") return b+a;
        if(y=="-") return b-a;
        if(y=="*") return long(a)*b;
        return b/a;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto&x:tokens){
            if(x=="+"||x=="-"||x=="*"||x=="/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(evaluate(a,b,x));
            }
            else{
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};