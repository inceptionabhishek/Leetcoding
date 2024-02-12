class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int,int> ms;
        for(int i=0;i<nums.size();i++){
            ms[nums[i]]++;
        }
        vector <pair<int,int>> v;
        for(auto j:ms){
            v.push_back(make_pair(j.second,j.first));
        }
        for(auto i:v){
            cout << i.first << " " << i.second << endl;
        }
        sort(v.begin(),v.end());
        return v[v.size()-1].second;
    }
};