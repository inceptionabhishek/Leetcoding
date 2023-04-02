#define ll long long
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>v;
        int m= potions.size();
        int n=spells.size();
        for(int i=0;i<spells.size();i++){
            ll left = 0;
            ll right = m-1;
            ll ans=0;
            ll last = n;
            while(left <= right){
                ll mid = (left + right)/2;
                if(1LL*spells[i]*potions[mid] < success){
                    left = mid+1;
                }else{
                    ans += (right - mid +1);
                    right = mid-1;
                }
            }
            v.push_back(ans);
        }
        return v;
    }
    
};