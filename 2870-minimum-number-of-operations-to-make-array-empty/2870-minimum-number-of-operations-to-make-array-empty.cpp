class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int>ms(1e6+1,0);
        for(auto j:nums){
            ms[j]++;
        }
        auto find=[&](int x){
            int div = x/3;
            int rest = x-div*3;
            if(rest%2==0){
                return div + rest/2;
            }
            rest = x-(div-1)*3;
            return div-1 + rest/2;
        };
        int cnt=0;
        for(auto j:ms){
            if(j == 1) return -1;
            cnt += find(j);
        }
        return cnt;
    }
};