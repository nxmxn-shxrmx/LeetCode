class Solution {
public:
    bool checkInclusion(string &s1, string &s2) {
        vector<int>v(26);
        for(auto c:s1)
            v[c-'a']++;
        
        for(int i = 0;i<s2.size();++i)
        {
            vector<int>u(v.begin(),v.end());
            map<int,queue<int>>q;
            int p =0;
            int j = i;
            while(i<s2.size()&&p<s1.size())
            {
                if(v[s2[i]-'a']==0)break;
                if(u[s2[i]-'a']==0)
                {
                    cout<<j<<" ";
                     int l = q[s2[i]-'a'].front();
                     for(j;j<=l&&j<s2.size();++j)
                     {
                        p--;
                        q[s2[j]-'a'].pop();
                        u[s2[j]-'a']++;
                     }
                    j=l+1;
                    cout<<j<<"\n";
                }
                u[s2[i]-'a']--;
                q[s2[i]-'a'].push(i);
                ++p;
                ++i;
            }
            // for(auto c:v)cout<<c<<" ";
            // cout<<"\n";
            // for(auto c:u)cout<<c<<" ";
            // cout<<"\n";
            // cout<<p<<"\n";
            if(p==s1.size())return 1;
        }
        return 0;
    }
};