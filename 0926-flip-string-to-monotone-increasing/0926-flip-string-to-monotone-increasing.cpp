class Solution {
public:
    int minFlipsMonoIncr(string s) {
       int o1 = 0;
       int z1 = 0;
       int z = 0;
        int o =0;
        int c = 0;
        int pre = 0;
        for(int i =0;i<s.size();++i)
        {
            if(s[i]=='1')o1++;
            else z1++;
            
            if(s[i]=='1' && i+1<s.size() && s[i+1]=='0')
                pre = o1;
        }
      
        for(int i =0;i<s.size();)
        {

            if(s[i]=='1')
            {
                pre = min(pre,c+(z1-z));
                int c1 = 0;
                while(i<s.size() && s[i]=='1')
                o++,c1++,i++;
                int c2 = 0;
                while(i<s.size() && s[i]=='0')
                c2++,i++;
                if(c1>(z1-z))
                {
                    c+=(z1-z);
                    break;
                }
                else
                    c+=c1;
                
                z+=c2;
            }
            else
                z++,++i;
        }
        return min(c,pre);
    }
};
