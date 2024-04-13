class Solution {
public:
    set<int>cl,ld,rd;
    void f(int n,int col,vector<string>&p,vector<vector<string>>&v)
    {
        if(n==col)
        {
            v.push_back(p);
            return;
        }
        
        string as = "";
        for(int i= 0;i<col;++i)
            as+=".";
        for(int i = 0;i<col;++i)
        {
            if(cl.find(i)==cl.end()&&ld.find(n-i)==ld.end()&&rd.find(n+i)==rd.end())
            {
                as[i]='Q';
                cl.insert(i);
                ld.insert(n-i);
                rd.insert(i+n);
                p.push_back(as);
                f(n+1,col,p,v);
                p.pop_back();
                as[i]='.';
                cl.erase(i);
                ld.erase(n-i);
                rd.erase(n+i);
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>v;
        vector<string>p;
        f(0,n,p,v);
        return v;
    }
};
