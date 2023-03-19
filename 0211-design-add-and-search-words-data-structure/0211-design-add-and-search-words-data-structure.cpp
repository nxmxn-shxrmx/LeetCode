  class TrieNode
    {
        public:
            TrieNode* child[26];
            bool end;
            TrieNode()
            {
                end = 0;
                for(int i = 0;i<26;++i)
                    child[i]=NULL;
            }
    };
class WordDictionary {
public:
 
    TrieNode* r;
    WordDictionary() {
        r = new TrieNode();
    }
    
    void addWord(string word) {
      
        TrieNode* cur = r;
        for(auto c:word)
        {
            
            if(cur->child[c-'a']==NULL)
                cur->child[c-'a'] = new TrieNode();
            cur = cur->child[c-'a'];
        }
        cur->end=1;
    }
    
    bool f(int i,string &w,TrieNode* &cur)
    {
        if(i==w.size())return cur->end;
        if(w[i]=='.')
        {
            for(int j = 0;j<26;++j)
            {
                if(cur->child[j]!=NULL)
                    if(f(i+1,w,cur->child[j]))return 1;
            }
            return 0;
        }
        
        if(cur->child[w[i]-'a']==NULL)return 0;
        return f(i+1,w,cur->child[w[i]-'a']);   
        
    }
    bool search(string word) {
        TrieNode* u = r;
        return f(0,word,u);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */