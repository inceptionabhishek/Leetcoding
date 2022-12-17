class Solution {
public:
    int change(string s){
        stringstream t(s);
        int x=0;
        t >> x;
        return x;
    }
    int evalRPN(vector<string>& tokens) {
        stack <long long> st;
        int ans=0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="/" || tokens[i]=="*"){
                long long first=st.top();
                st.pop();
                long long second=st.top();
                st.pop();
                long long currans;
                if(tokens[i] == "+"){
                    currans = first + second;
                }else if(tokens[i] == "-"){
                    currans = -first+second;
                }else if(tokens[i] == "/"){
                    currans = second/first;
                }else{
                    currans = first*second;
                }
                st.push(currans);
            }else{
                long long curr = change(tokens[i]);
                st.push(curr);
            }
        }
        return st.top();
    }
};