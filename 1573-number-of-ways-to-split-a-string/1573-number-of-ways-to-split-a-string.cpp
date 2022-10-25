class Solution {
public:
    long long moduloMultiplication(long a,long b, long mod){
        long res = 0; 
        a %= mod;
        while (b > 0){
            if ((b & 1) > 0){
                res = (res + a) % mod;
            }
            a = (2 * a) % mod;
            b >>= 1;
        }
        return res;
    }
    int numWays(string s) {
        int modd=1000000007;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            cnt += (s[i]=='1');
        }
        if(cnt%3!=0){
            return 0;
        }
        int div=cnt/3;
        int index1=-1;
        int index2=-1;
        bool found=0;
        int currcnt=0;
        vector <pair<int,int>> v;
        for(int i=0;i<s.length();i++){
            if(found){
                if(s[i]=='1'){
                    currcnt++;
                    if(currcnt==div){
                        index2=i;
                        found=0;
                        currcnt=0;
                        v.push_back(make_pair(index1,index2));
                        index1=-1;
                        index2=-1;
                    }
                }
            }else{
                if(s[i]=='1'){
                    currcnt++;
                    found=1;
                    index1=i;
                    index2=i;
                    if(currcnt==div){
                        index2=i;
                        found=0;
                        currcnt=0;
                        v.push_back(make_pair(index1,index2));
                        index1=-1;
                        index2=-1;
                    }
                }
            }
        }
        if(v.size()==0){
            return ((s.length()-1)*(s.length()-2)/2)%modd;
        }
        for(auto j:v){
            cout << j.first << ' ' << j.second << endl;
        }
        int cnt1=abs(v[0].second-v[1].first)%modd;
        int cnt2=abs(v[1].second-v[2].first)%modd;
        
        return moduloMultiplication(cnt1,cnt2,modd);
    }
};