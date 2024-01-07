#define ll long long int
#define endl '\n'
const ll mod=1000000007;
const ll mod2=998244353;
const double PI = 3.14159265358979323846;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fo(i ,n) for(ll i = 0 ; i < n ; i++)
#define rep(i,n) for(ll i=1;i<=n;i++)
#define mp make_pair
#define all(x) x.begin() , x.end()
#define ff first
#define ss second
#define pb push_back
#define vi vector<ll>
class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x<=y){
            return y-x;
        }
        queue<int>q;
        q.push(x);
        set<int>vis;
        int ops=0;
        while(!q.empty()){
            int len = q.size();
            
            for(int i=0;i<len;i++){
                
                int a=q.front();
                q.pop();
                // cout << a << endl;
                if(vis.count(a)>0){
                    continue;
                }
                vis.insert(a);
                if(a==y){
                    return ops;
                }
                if(a%11==0){
                    q.push(a/11);
                }
                if(a%5==0){
                    q.push(a/5);
                }
                q.push(a-1);
                q.push(a+1);
            }
            ops++;
        }
        return -1;
    }
};