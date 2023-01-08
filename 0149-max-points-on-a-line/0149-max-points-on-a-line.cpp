class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1, ct;
        double m1, m2;
        for(int i=0; i<points.size(); i++)
        {
            for(int j=i+1; j<points.size(); j++)
            {
                ct = 0;
                if(points[i][1] != points[j][1])
                {
                    m1 = ((points[i][0]-points[j][0])*1.0)/(points[i][1]-points[j][1]);
                    for(int k=0; k<points.size(); k++)
                    {
                        if(k == i || k == j) ct++;
                        else if(points[k][1] != points[j][1])
                        {
                            m2 = ((points[k][0]-points[i][0])*1.0)/(points[k][1]-points[i][1]);
                            if(m1 == m2) ct++;
                        }
                    }
                    ans = max(ans, ct);
                }
                else
                {
                    for(int k=0; k<points.size(); k++)
                    {
                        if(k == i || k == j) ct++;
                        else if(points[k][1] == points[j][1])
                        {
                            ct++;
                        }
                    }
                    ans = max(ans, ct);
                }
            }
        }
        return ans;
    }
};