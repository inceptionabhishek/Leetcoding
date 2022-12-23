class Solution {
public:
    // int dp[5002][5002];
    // int ans(vector<int>&prices,int index,int selected){
    //     cout << index << ' ' << selected << endl;
    //     if(index > prices.size()){
    //         return 0;
    //     }
    //     int curr = INT_MIN;
    //     if(dp[index][selected]!=-1){
    //         return dp[index][selected];
    //     }
    //     if(selected!=-1){
    //         int choice1=ans(prices,index+1,selected);
    //         int choice2=(prices[index-1]-prices[selected])+ans(prices,index+2,-1);
    //         curr=max(curr,max(choice1,choice2));
    //     }
    //     else{
    //         int choice1=ans(prices,index+1,selected+1);
    //         int choice2=ans(prices,index+1,index+1);
    //         curr=max(curr,max(choice1,choice2));
    //     }
    //     return dp[index][selected]=curr;
    // }
    int maxProfit(vector<int> &prices) {
        int buy=INT_MIN, sell=0, prev_sell=0, prev_buy;
        for (int price : prices) {
            prev_buy = buy;
            buy = max(prev_sell - price, buy);
            prev_sell = sell;
            sell = max(prev_buy + price, sell);
        }
        return sell;
    }
};