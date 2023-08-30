class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());
        int cnt=0;
        int index=0;
        for(int i=0;i<p.size() && index<t.size();){
            if(p[i]<=t[index]){
                i++;
                cnt++;
                index++;
            }else{
                index++;
            }
        }
        return cnt;
    }
};