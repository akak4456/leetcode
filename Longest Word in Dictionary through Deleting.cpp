class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int maxSz = 0;
        string ret = "";
        for(int idx = 0;idx<d.size();idx++){
            int dPos = 0;
            bool canDo = false;
            for(int t=0;t<s.size();t++){
                if(s[t] == d[idx][dPos]){
                    dPos++;
                }
                if(dPos == d[idx].size()){
                    canDo = true;
                    break;
                }
            }
            if(canDo){
                if(ret == ""||d[idx].size() > maxSz){
                    maxSz = d[idx].size();
                ret = d[idx];
                }else if(d[idx].size() == maxSz&&d[idx].compare(ret) < 0){
                    maxSz = d[idx].size();
                ret = d[idx];
                }
                
            }
        }
        return ret;
    }
};