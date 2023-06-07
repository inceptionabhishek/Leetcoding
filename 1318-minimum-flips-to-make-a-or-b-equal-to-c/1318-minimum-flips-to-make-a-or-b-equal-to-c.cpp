class Solution {
public:
    string decToBinary(int n)
{
        string s="";
    // Size of an integer is assumed to be 32 bits
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            s+='1';
        else
            s+='0';
    }
        return s;
}
 
    int minFlips(int a, int b, int c) {
        string a1=decToBinary(a);
        string a2=decToBinary(b);
        string a3=decToBinary(c);
        int cnt=0;
        for(int i=0;i<=31;i++){
            if(a3[i]=='1'){
                if(a1[i]=='0' && a2[i]=='0'){
                    cnt++;
                }
            }else{
                if(a1[i]=='1' && a2[i]=='1'){
                    cnt+=2;
                }else if(a1[i]=='1' || a2[i]=='1'){
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
};