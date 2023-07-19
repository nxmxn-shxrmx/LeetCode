class Solution {
public:
    #define ll unsigned long long 
    string sum(string  a,string b)
    {
        string ans = "";
        int c = 0;
        if(a.size()>b.size())
            swap(a,b);
        int j = a.size()-1;
        int i =b.size()-1; 
        while(j>=0)
        {
            int u = (c+ a[j]-'0')+(b[i]-'0');
            int y = u%10;
            ans = to_string(y)+ans;
            c = u/10;
            i--;
            j--;
        }
        while(i>=0)
        {
            int u = c+b[i]-'0';
            int y = u%10;
            ans = to_string(y)+ans;
            c=u/10;

            i--;
        }
        if(c)ans = "1"+ans;
        
    //    cout<<a<<" "<<b<<" "<<ans<<"\n";
       return ans;    
        
    }
    bool f(int i,string a,string b,string c,string &num)
    {
       
        if(i==num.size()-1)
        {
            if(a=="-1"||b=="-1")return 0;
            
            if(c=="0")return 0;
            if(c=="-1")
                c = "";
            c= c+num[i];
            string p = sum(a,b);
          
            if(p==c)
            return 1;
            return 0;
        }
        if(c=="0")return 0;
       
        if(a=="-1")
        {
            a="";
            a +=num[i];
            return f(i+1,a,b,c,num);
        }
        else if(b=="-1")
        {
            if(a=="0")
            {
                b = "";
                b += num[i];
                return f(i+1,a,b,c,num);
            }
            string u = "";
            u+=num[i];
            return f(i+1,a+(num[i]),b,c,num) || f(i+1,a,u,c,num);
        }
        else if(c=="-1")
        {
            if(b=="0")
            {
                c= "";
                c+=num[i];
            
                if(sum(a,b)==c)return f(i+1,b,c,"-1",num);
                
                return f(i+1,a,b,c,num);
            }
            string p="";
            p+=num[i];
         
            if(sum(a,b)==p)
                return  f(i+1,b,p,"-1",num);
            return f(i+1,a,b+num[i],c,num) || f(i+1,a,b,p,num);
        }
        else
        {
            
         string p=c+num[i];
            if(sum(a,b)==p) return  f(i+1,b,p,"-1",num);
            
            return f(i+1,a,b,p,num);
        }
        return 0;
        
    }
    bool isAdditiveNumber(string num) {
        string a ="-1";
        string b = "-1";
        string c= "-1";
        return f(0,a,b,c,num);
    }
};