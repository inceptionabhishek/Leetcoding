class Solution {
public:
    bool chk(char a){
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u'){
            return true;
        }
        if(a=='A' || a=='E' || a=='I' || a=='O' || a=='U'){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int cnt1=0,cnt2=0;
        for(int i=0;i<s.length()/2;i++){
            if(chk(s[i])){
                cnt1++;
            }
        }
        for(int i=s.length()/2;i<s.length();i++){
            if(chk(s[i])){
                cnt2++;
            }
        }
        return cnt1==cnt2;
    }
};