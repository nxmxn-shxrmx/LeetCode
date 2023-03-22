class Tree
{
    public:
        Tree* child[26];
        bool is;
        Tree()
        {
            for(int i = 0;i<26;++i)
                child[i]=NULL;
            is= 0;
                
        }
};
class Trie {
public:
     Tree* h;
    Trie() {
       h = new Tree();
    }

    void insert(string word) {
        Tree *u = h;
        for(auto c:word)
        {
            if(u->child[c-'a']==NULL)
                u->child[c-'a']=new Tree();
            u = u->child[c-'a'];
        }
        u->is = 1;
    }
    
    bool search(string word) {
        Tree *u = h;
        for(auto c:word)
        {
            if(u->child[c-'a']==NULL)return 0;
            u=u->child[c-'a'];
        }
        return u->is;
    }
    
    bool startsWith(string word) {
        Tree *u = h;
        for(auto c:word)
        {
            if(u->child[c-'a']==NULL)return 0;
            u=u->child[c-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */