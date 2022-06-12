class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& n, int t) {
        
        set<vector<int>>s;
        sort(n.begin(),n.end());
        
        for(ll i =0;i<n.size();++i)
        {
            ll h=n[i];
            for(int j = i+1;j<n.size();++j)
            {
                h = n[i]+n[j];
                int x = j+1;
                int y =n.size()-1;
                while(x<y)
                {
                    ll g=h+n[x]+n[y];
                    if(g>t)
                        --y;
                    else if(g<t)
                        ++x;
                    
                    else
                    {
                        s.insert({n[i],n[j],n[x],n[y]});
                        while(y>=1 && n[y-1]==n[y])
                            --y;
                        while(x<y && n[x+1]==n[x])
                        ++x;
                        
                        --y;
                    }
                }
                
            }
        }
        vector<vector<int>>v(s.begin(),s.end());
        return v;
    }
};