class Solution {
public:
    
    string reverseWords(string s) {
        int l=0;
        int r=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                int curr=r;
               // cout << l <<" " << r << endl;
                while(l<r){
                    swap(s[l],s[r]);
                    l++;
                    r--;
                }
                l=curr+2;
            }else{
                r=i;
            }
        }
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};