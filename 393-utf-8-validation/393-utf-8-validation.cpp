class Solution {
public:
    bool validUtf8(vector<int>& d) {
        
        for(int i =0;i<d.size();++i)
        {
            int c =0;
            int u=7;
            while(u>=0 && (1<<u)&d[i])
            c++,u--;
            c--;
            if(c==0 || c>=4)
                return false;
            int n =d.size()-i-1;
            if(n<c)  
            return 0;
            for(int k = 0;k<c;++k)
            {
                ++i;
                int p = (1<<7)&d[i];
                int l = (1<<6)&d[i];
                if((p!=128) || (l!=0))
                    return 0;
            }
                
        }
        return 1;
    }
};