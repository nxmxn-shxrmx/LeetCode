//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long x) {
        if(x<=10)
            return x;
        long long u = 0;
        string s = to_string(x);
        u+=s[0]-'0';
        for(int i =1;i<s.size();++i)
        {
            if(abs(s[i]-s[i-1])==1)
                u = u*10 + s[i]-'0';
            else if(s[i]<s[i-1])
            {
                u--;
                int y = u/10;
                y = y%10;
                int p = u%10;
                if(abs(y-p)!=1)
                   u= jumpingNums(u);
                p = u%10;
                if(p==9)
                    p = 8;
                else 
                    p +=1;
                while(i<s.size())
                {
                    u = u*10+p;
                    if(p==9)
                        p = 8;
                    else
                        p+=1;
                    ++i;
                }
                break;
            }
            else if(s[i]>s[i-1])
            {
                int p = u%10;
                if(p==9)
                    p = 8;
                else 
                    p +=1;
                while(i<s.size())
                {
                    u = u*10+p;
                    if(p==9)
                        p = 8;
                    else
                        p+=1;
                    ++i;
                }
                break;
            }
            else
            {
                if(s[i]=='0')
                {
                     u--;
                int p = u%10;
                if(p==9)
                    p = 8;
                else 
                    p +=1;
                while(i<s.size())
                {
                    u = u*10+p;
                    if(p==9)
                        p = 8;
                    else
                        p+=1;
                    ++i;
                }
                break;
                }
                else
                {
                    
                    int p = u%10;
                    p -=1;
                while(i<s.size())
                {
                    u = u*10+p;
                    if(p==9)
                        p = 8;
                    else
                        p+=1;
                    ++i;
                }
                break;
                }
            }
            
        }
        return u;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends