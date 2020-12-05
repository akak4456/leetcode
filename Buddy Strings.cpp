class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.empty())
            return false;
        if(A.size() != B.size())
            return false;
        int cnt = 0;
        int pos[2] = {-1,-1};
        int aCnt[26];
        for(int i=0;i<26;i++){
            aCnt[i] = 0;
        }
        for(int i=0;i<A.size();i++){
            aCnt[A[i]-'a']++;
            if(A[i] != B[i]){
                if(cnt == 2){
                    return false;
                }
                pos[cnt] = i;
                cnt++;
            }
        }
        cout << cnt << endl;
        if(cnt == 0){
            for(int i=0;i<26;i++){
                if(aCnt[i] >= 2)
                    return true;
            }
            return false;
        }else if(cnt == 1){
            return false;
        }else{
            return A[pos[0]] == B[pos[1]] && A[pos[1]] == B[pos[0]];
        }
        return false;
    }
};