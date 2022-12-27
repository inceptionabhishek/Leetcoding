class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector <int> temp;
        for(int i=0;i<rocks.size();i++){
            temp.push_back(capacity[i]-rocks[i]);
        }
        int ans=0;
        
        sort(temp.begin(),temp.end());
        for(auto j:temp){
            cout << j << " ";
        }
        cout << endl;
        
        for(int i=0;i<temp.size();i++){
            if(temp[i]==0){
              ans++;  
            }else{
                if(temp[i]<=additionalRocks){
                    ans ++;
                    additionalRocks-=temp[i];
                }
            }
        }
        return ans;
    }
};