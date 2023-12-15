class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string>s;
        for(auto j:paths){
            s.insert(j[1]);
        }
        for(auto j:paths){
            s.erase(j[0]);
        }
        return *s.begin();
    }
};