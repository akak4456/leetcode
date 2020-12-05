struct Trie{
    Trie* nxt[26] = {nullptr,};
    bool terminated = false;
};
class Solution {
public:
    vector<int> cache;
    void insert(string word,Trie* root){
        if(word.empty()){
            root->terminated = true;
            return;
        }
        int idx = word[0] - 'a';
        if(root->nxt[idx] == nullptr){
            root->nxt[idx] = new Trie();
        }
        word.erase(0,1);
        insert(word,root->nxt[idx]);
    }
    int isBreak(string s, Trie* root,int start){
        //cout << s << endl;
        if(s.size() <= start)
            return 1;
        int& ret = cache[start];
        if(ret != -1) return ret;
        ret = 0;
        int cnt = 1;
        Trie* newRoot = root->nxt[s[start]-'a'];
        while(newRoot != nullptr){
            if(newRoot->terminated){
                if(isBreak(s,root,start+cnt)){
                    return ret = 1;
                }
            }
           // cout << s << ' ' << cnt << endl;
            if(start+cnt >= s.size())
                break;
            newRoot = newRoot->nxt[s[start+cnt]-'a'];
            cnt++;
        }
        return ret = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        cache = vector<int>(s.size(),-1);
        Trie* root = new Trie();
        for(int i=0;i<wordDict.size();i++)
            insert(wordDict[i],root);
        return isBreak(s,root,0);
    }
};