class Solution {
public:
    int bit_mask = 0;
    string ret = "";
    bool finish = false;
    bool isPossible(string src, int start, int origin){
        int mask = origin;
        for(int i=start;i<src.size();i++){
            mask |= (1<<(src[i]-'a'));  
        }
        return bit_mask == mask;
    }
    void solve(string ans,int used,string src,int start){
      //  cout << ans << ' '<<start << endl;
        if(finish)
            return;
        if(used == bit_mask){
            finish = true;
            ret = ans;
            return;
        }
        for(int i=0;i<26;i++){
            if(((bit_mask&(1<<i))>0)&&(used&(1<<i))==0){
                for(int idx=start;idx<src.size();idx++){
                    if(src[idx] == ('a'+i)){
                        if(isPossible(src,idx,used)){
                            string tmp = ans;
                            tmp += 'a'+i;
                            solve(tmp,used | (1<<i),src,idx+1);
                        }
                        break;
                    }
                }
            }
        }
    }
    string removeDuplicateLetters(string s) {
        for(int i=0;i<s.size();i++){
            bit_mask |= (1<<(s[i]-'a'));            
        }
        solve("",0,s,0);
        return ret;
    }
};