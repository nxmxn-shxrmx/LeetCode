class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int r = chalk.size()-1;
        for(int i = 1;i<chalk.size();++i)
        {
            long long u = chalk[i]+chalk[i-1];
            if(u>k)
            {
                r = i;
                break;
            }
            chalk[i]+=chalk[i-1];
        }
        if(r==chalk.size()-1)
        k%=chalk.back();
        int lo = 0;
        int hi = r;
        cout<<r<<"\n";
        while(lo<hi)
        {
            int mid = (lo+hi)/2;
            if(chalk[mid]<=k)
                lo=mid+1;
            else
                hi=mid;
        }
        return lo; 
    }
};
//3 7 8 10