class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        int c=0;
        long long pre=0,cur=0;
        for(int i = p.size()-1;~i;--i)
        {
            while(i-1>=0 && p[i][0]==p[i-1][0])
            {
                // cout<<i<<"->"<<c<<"\n";
                if(p[i][1]<pre)
                    c++;
                if(cur<p[i][1])
                    cur = p[i][1];
                --i;
            }
            if(p[i][1]<pre)
                 c++;
            else
                pre = p[i][1];
            pre = max(cur,pre);
            // cout<<c<<" ";
        }
        
        return c;
    }
};