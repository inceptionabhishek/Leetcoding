class Solution {
public:
    int ans(vector<int>costs,int coins,int i){
        if(coins==0){
            return 0;
        }
        if(i>=costs.size()){
            if(coins>=0){
                return 0;
            }
            return INT_MAX;
        }
        if(coins<0){
            return INT_MAX;
        }
        
        int t1=1+ans(costs,coins-costs[i],i+1);
        int t2=ans(costs,coins,i+1);
        return max(t1,t2);
    }
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int tot=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]>coins){
                break;
            }else{
                tot++;
                coins-=costs[i];
            }
        }
        return tot;
        //sreturn ans(costs,coins,0);
    }
};