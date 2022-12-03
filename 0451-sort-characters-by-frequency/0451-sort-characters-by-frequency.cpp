class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>>v;
        map<char,int> ms;
        for(int i=0;i<s.length();i++){
            ms[s[i]]++;
        }
        for(auto j:ms){
            v.push_back(make_pair(j.second,j.first));
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        string ans="";
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].first;j++){
                ans += v[i].second;
            }
        }
        return ans;
    }
};