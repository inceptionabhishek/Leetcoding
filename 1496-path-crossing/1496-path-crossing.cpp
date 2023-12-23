class Solution {
public:
    bool isPathCrossing(string path) {
        int i=0,j=0;
        set<pair<int,int>>s;
        s.insert({i,j});
        for(int k=0;k<path.length();k++){
            cout << i << ' ' << j << endl;
            if(path[k]=='N'){
                i--;
            }
            else if(path[k]=='S'){
                i++;
            }else if(path[k]=='W'){
                j--;
            }else{
                j++;
            }
            if(s.count({i,j})>0){
                return true;
            }
            s.insert({i,j});
        }
        return false;
    }
};