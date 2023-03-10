class Solution {
public:
    map<string,bool>m;
    bool scramble(string s1,string s2){
        if(s1==s2)
            return true;
        if(s1.size()!=s2.size())return 0;
        if(m[s1+s2])
            return false;
        vector<int>v(27);
         for(int i = 0;i<s1.size();++i)
         {

            v[s1[i]-'a']++;
                         v[s2[i]-'a']--;
         }
         for(auto c:v)
             if(c!=0)return 0;
        for(int k=1;k<=s1.size()-1;++k)
        {                                                                                            if(scramble(s1.substr(0,k),s2.substr(0,k))&&                                                   scramble(s1.substr(k),s2.substr(k)))return 1;
            if(scramble(s1.substr(0,k),s2.substr(s1.size()-k))&&
              scramble(s1.substr(k),s2.substr(0,s1.size()-k)))return 1;
        }
     m[s1+s2]=1;
        return 0;
    }
    
    bool isScramble(string s1, string s2) {
        return scramble(s1,s2);
    }
};

