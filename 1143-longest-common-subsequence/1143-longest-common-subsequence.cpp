class Solution {
public:
    string  f(string &p,string &q)
{
	vector<vector<int>>v(p.size(),vector<int>(q.size()));
	for(int i=  0;i<p.size();++i)
	{
		for(int j = 0;j<q.size();++j)
		{
			if(p[i]==q[j])
			{
				v[i][j]=1;
				if(i-1>=0 && j-1>=0)
					v[i][j]+=v[i-1][j-1];
			}
			else
			{
				if(i-1>=0)
					v[i][j] = v[i-1][j];
				if(j-1>=0)
					v[i][j] = max(v[i][j],v[i][j-1]);
			}
		}
	}
	string s = "";
	int i = p.size()-1;
	int j = q.size()-1;
	while(i>=0 && j>=0)
	{
		if(i>=0 && j>=0 && p[i]==q[j])
		{
			s+=p[i];
			i-=1;
			j-=1;
		}
		else 
		{
			if(i-1<0)
				j-=1;
			else if(j-1<0)
				i-=1;
			else if(v[i][j-1]>v[i-1][j])
				j-=1;
			
			else
				i-=1;
		}
	}
	reverse(s.begin(),s.end());
	return s;
}
    int longestCommonSubsequence(string t1, string t2) {
     
        return f(t1,t2).size();
    }
};