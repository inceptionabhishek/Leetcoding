struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DSU dsu(n);
        auto check=[&](string s,string t){
            if(s.length()!=t.length()){
                return 0;
            }
            int cnt=0;
            for(int i=0;i<s.length();i++){
                if(s[i]!=t[i]){
                    cnt++;
                }
            }
            if(cnt==2 || cnt==0){
                return 1;
            }
            return 0;
        };
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(strs[i],strs[j])){
                    dsu.unite(i,j);
                }
            }
        }
        set<int>ans;
        for(int i=0;i<n;i++){
            ans.insert(dsu.get(i));
        }
        return ans.size();
    }
};