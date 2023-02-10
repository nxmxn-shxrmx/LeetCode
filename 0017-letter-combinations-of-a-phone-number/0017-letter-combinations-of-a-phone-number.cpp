class Solution {
public:
    map<int,string>m;
    vector<string>ans;
    void collect(int i,string digits,string str)
    {
        if(digits.size()==i)
            ans.push_back(str);
        
        for(auto c:m[digits[i]-'0'])
            collect(i+1,digits,str+c);
    }
    vector<string> letterCombinations(string digits) {
     
        if(digits.size()==0)return {};
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
    collect(0,digits,"");
    return ans;
    }
};