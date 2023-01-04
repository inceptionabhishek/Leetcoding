#define ss second
#define pb push_back
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map <int,int> ms;
        for(int i=0;i<tasks.size();i++){
            ms[tasks[i]]++;
        }
        int cnt=0;
        multiset <int> mm;
        for(auto j:ms){
            mm.insert(j.ss);
        }
        // deb(mm);
        while(!mm.empty()){
            int val= *mm.begin();
            //deb(val);
           
            mm.erase(mm.find(val));

            if(val==1){
            	return -1;
            }
            int mini1=-1,mini2=-1,mini3=-1;
            if(val%2==0){
            	mini1=val/2;
            }
            if(val%3==0){
            	mini2=val/3;
            }
      
            vector <int> v;
            if(mini1!=-1){
            	v.pb(mini1);
            }
            if(mini2!=-1){
            	v.pb(mini2);
            }
            
            	int temp = val/3;
            	val -= (temp)*3;
            	if(val%2!=0){
            		val+=3;
            		temp--;
            	}
            	if(val%2==0){
            		mini3=val/2;
            		mini3+=temp;
            	}
            	if(mini3!=-1){
            		 v.pb(mini3);
            	}
           
            sort(v.begin(),v.end());
            if(v.size()!=0){
            	if(v[0]!=-1){
            		cnt+=v[0];
            	}
            }
            // deb(cnt);
            // deb(mm);
        }
        return cnt;
    }
};