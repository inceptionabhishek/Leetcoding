class Solution {
public:
    int partitionString(string s) {
        int cnt=1;
        map<char,int>m;
        for(auto j:s){
            if(m.count(j)>0){
                cnt++;
                m.clear();
                m[j]++;
            }else{
                m[j]++;
            }
        }
        return cnt;
    }
};