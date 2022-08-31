class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
     long long i=2;
     while(true)
     {
         long long a = i/2;
         long long n = a+1;
         long long st = a*(a+1)/2;
         long long sum= n * (2*st + a*a)/2;
        
         // cout<<4*sum<<" "<<i<<"\n";
         if(neededApples<=4*sum)
         {
             return 4*(i);
         }
             i+=2;
     }
        return 0;
    }
};