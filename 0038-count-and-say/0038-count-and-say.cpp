class Solution {
public:
    string ans(int i,string s){
        if(i==1) return s;
        string s1 = "";
            for(int j=0;j<s.size();j++){
            int c = 1;
                while(j+1<s.size() && s[j]==s[j+1]){
                    j++;
                    c++;
                }
                s1 += to_string(c)+s[j];
            }
        return ans(i-1,s1);
                
    }
    string countAndSay(int n) {
        
        return ans(n,"1");

    }
};