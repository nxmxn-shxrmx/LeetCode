class Solution {
public:
    int countDigitOne(int n) {
        if(n==0)return 0;
        long long ct = 0;
        long long rev = 0;
        while(n)
        {
            rev = rev*10+n%10;
            n/=10;
            ct++;
        }
        long long ans =0;
        while(rev)
        {
            if(ct==1)
                return ans+1;
            
            if(rev%10==0)
            {
                rev/=10;
                ct--;
                continue;
            }
            long long poe = pow(10,ct-1)+.25;
            long long sum = ct*poe;
            long long nex = (ct-1)*poe/10;
            long long rem = rev%10;
        
            rem = 10-rem;
            nex*=rem;
            if(rev%10==1)
            {
                long long u = rev/10;
                long long a =ct-1;
                long long prev = 0;
                while(u)
                {
                    prev = prev*10+u%10;
                    u/=10;
                    a--;
                }
                long long l = pow(10,a)+0.25;
                nex+=poe-1-(prev*l);
            }
            ans+=(sum-nex);
            rev/=10;
            ct--;
        }
        return ans;
    }
};

/*

    0    = 0;
    1<=9 = 1;
    10<=99=(1+11+1+1+1+1+1+1+1+1)=20

    9=1
    99=20
    999=300
    9999=4000
    99999=50000
    999999=600000
    1199
    1000+199+100+99+9+9
    
    3001+199+99+21+
    300-(10-1)*20=120-99
    21 
*/