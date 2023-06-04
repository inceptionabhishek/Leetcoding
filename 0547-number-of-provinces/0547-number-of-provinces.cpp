class Solution {
public:
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    dsu.unite(i,j);
                }
            }
        }
        set<int>tot;
        for(int i=0;i<n;i++){
            tot.insert(dsu.get(i));
        }
        return tot.size();
    }
};