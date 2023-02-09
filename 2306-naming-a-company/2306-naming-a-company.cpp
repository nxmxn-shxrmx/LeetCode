class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string,bool>m;
        vector<int>v(26);
        for(auto c:ideas)
            m[c]=1,v[c[0]-'a']++;
        sort(ideas.begin(),ideas.end());
        vector<vector<int>>p(26,vector<int>(26));
        long long count = 0;
        for(auto c:ideas)
        {
            string u =c;
            for(char a='a';a<c[0];++a)
            {
                u[0]=a;
                if(m.find(u)==m.end())
                    count+=v[a-'a']-p[c[0]-'a'][a-'a'];
                else
                    count-=(v[a-'a']-p[c[0]-'a'][a-'a']);
                
            }
            char a;
            a =c[0];
            a++;
            for(a;a<='z';++a)
            {
                u[0]=a;
                if(m.find(u)==m.end())
                    count+=v[a-'a'];
                else
                    p[a-'a'][c[0]-'a']++;
            }
        //    cout<<count<<" ";
        }
     return count;   
    }
};
/*
c-1
d-1
t-2   
coffee
*/