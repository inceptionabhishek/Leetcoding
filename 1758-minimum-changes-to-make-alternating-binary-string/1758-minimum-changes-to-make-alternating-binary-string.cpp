class Solution {
public:
    int minOperations(string s) {
        int op1=0,op2=0;
        char curr='1';
        int pz=0;
        for(int i=0;i<s.length();i++){
            if(pz==0){
                if(s[i]!=curr){
                    op1++;
                }
                pz=1;
                curr='0';
            }else{
                if(s[i]!=curr){
                    op1++;
                }
                pz=0;
                curr='1';
            }
        }
        curr='0';
    pz=1;
        for(int i=0;i<s.length();i++){
            if(pz==0){
                if(s[i]!=curr){
                    op2++;
                }
                pz=1;
                curr='0';
            }else{
                if(s[i]!=curr){
                    op2++;
                }
                pz=0;
                curr='1';
            }
        }
        return min(op1,op2);
    }
};