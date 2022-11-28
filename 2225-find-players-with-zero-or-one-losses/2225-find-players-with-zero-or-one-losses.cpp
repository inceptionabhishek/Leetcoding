class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans;
        set<int>s;
        map<int,int>ms;
        for(int i=0;i<matches.size();i++){
            s.insert(matches[i][0]);
            s.insert(matches[i][1]);
            ms[matches[i][1]]++;
        }
        vector<int>winner1;
        vector<int>winner2;
        while(!s.empty()){
            if(ms[*s.begin()]==1){
                winner2.push_back(*s.begin());
            }else if(ms[*s.begin()]==0){
                winner1.push_back(*s.begin());
            }
            s.erase(*s.begin());
        }
        return {winner1,winner2};
    }
};