class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<long long>v(chalk.size());
        v[0]=chalk[0];
        for(int i = 1;i<chalk.size();++i)
            v[i]+=v[i-1]+chalk[i];
        k%=v.back();
        int lo = 0;
        int hi = chalk.size()-1;
        while(lo<hi)
        {
            int mid = (lo+hi)/2;
            if(v[mid]<=k)
                lo=mid+1;
            else
                hi=mid;
        }
        return lo; 
    }
};
//3 7 8 10