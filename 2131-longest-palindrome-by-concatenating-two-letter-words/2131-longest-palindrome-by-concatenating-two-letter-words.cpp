class Solution {
public:
   int longestPalindrome(vector<string>& words) {
  int cnt=0;
  map <string,int> ms;
  map <string,int> ms2;
  for(int i=0;i<words.size();i++){
    string s=words[i];
    if(s[0]==s[1]){
      ms2[s]++;
    }else{
      ms[s]++;
    }
  }
  // deb(ms2);
  int ans=0;
  bool ok=0;
  for(auto j:ms2){
    if(j.second%2!=0){
      ok=1;
    }
    int val=j.second/2;
    ans += 2*val;
  }
  ans=ans*2;
  if(ok){
    ans +=2;
  }
  // deb(ms);
  for(auto j:ms){
    string tt=j.first;
    string tt2="";

    tt2+=tt[1];
    tt2+=tt[0];
    // deb(tt);
    // deb(tt2);

    if(ms.count(tt2)){
      cnt += 4*(min(ms[tt],ms[tt2]));
      // deb(cnt);
      ms.erase(tt);
      ms.erase(tt2);
    }
    if(ms.size()<2){
      break;
    }
  }






  ans =max(0,ans);
  return cnt+ans;
}

};