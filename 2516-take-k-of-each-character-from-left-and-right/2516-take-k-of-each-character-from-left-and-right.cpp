class Solution {
public:
    int takeCharacters(string s, int k) {
        int a=0;
        int b=0;
        int c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                a++;
            }else if(s[i]=='b'){
                b++;
            }else{
                c++;
            }
        }
        if(a<k || b<k || c<k){
            return -1;
        }
        a-=k;
        b-=k;
        c-=k;
        int wa=0;
        int wb=0;
        int wc=0;
        int i=0,j=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                wa++;
            }else if(s[i]=='b'){
                wb++;
            }else{
                wc++;
            }
            while(wa>a || wb>b || wc>c){
                if(s[j]=='a'){
                    wa--;
                }
                if(s[j]=='b'){
                    wb--;
                }
                if(s[j]=='c'){
                    wc--;
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return s.length()-ans;
    }
};