class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>> v;
        for(int i=0;i<points.size();i++){
            v.push_back(make_pair(points[i][1],points[i][0]));
        }
        sort(v.begin(),v.end());
        int currShootedPoint=-1;
        int ans=0;
        for(auto j:v){
            if(currShootedPoint==-1){
                currShootedPoint=j.first;
                ans++;
            }else{
                if(j.second<=currShootedPoint && j.first>=currShootedPoint){
                    
                }else{
                    ans++;
                    currShootedPoint=j.first;
                }
            }
        }
        return ans;
    }
};