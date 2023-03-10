class Solution {
public:
    bool check(long long m,vector<int>&time,int sum)
    {
        
        for(auto c:time)
        {
            sum-=(m/c);
            if(sum<=0)return 1;
        }
        return sum<=0;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {

        sort(time.begin(),time.end());
        long long l = time[0];
        long long r = l*totalTrips;
        long long t =r;
     
        while(l<=r)
        {
            long long m =(l+r)/2;
         
            if(check(m,time,totalTrips))
                r = m-1,t =m;
            else l = m+1;
        }
        return t;
    }
};