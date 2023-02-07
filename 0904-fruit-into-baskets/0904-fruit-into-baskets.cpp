class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first=0;
        int second=0;
        int first_el=-1;
        int second_el=-1;
        int ct = 0;
        int ans = 0;
        for(int i = 0;i<fruits.size();++i)
        {
            if(first_el==-1)first_el=fruits[i],first=i;
            else if(second_el==-1 && fruits[i]!=first_el)second_el = fruits[i],second = i;
            else if(first_el!=fruits[i]&&second_el!=fruits[i])
            {
                if(first>=second)
                {
                    swap(first,second);
                    swap(first_el,second_el);
                }
                ct = first+1;
                first=i;
                first_el=fruits[i];
            }
            else if(first_el==fruits[i])first=i;
            else if(second_el==fruits[i])second=i;
            int p =i+1-ct;
            ans = max(ans,p);
            
        }
        int p = fruits.size()-ct;
        return max(ans,p);
    }
};