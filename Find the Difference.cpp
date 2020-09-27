class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            int idx = t[i]-'a';
            cnt[idx]--;
            if(cnt[idx] < 0)
                return t[i];
        }
        return t.back();
    }
};