class Solution {
public:
 int minStoneSum(vector<int>& piles, int k) {
  int n=piles.size();
  priority_queue<int> pq;
  for(int i=0;i<piles.size();i++){
    pq.push(piles[i]);
  }
  while(k!=0){
   int val=pq.top();
   if(val==0){
     break;
   }
   val= val/2;

   pq.push(pq.top()-val);
    pq.pop();
   k--;
  }
  int sum=0;
    priority_queue<int> g = pq;
    while (!g.empty()) {
      sum+=g.top();
      g.pop();
    }


    return sum;

}
};