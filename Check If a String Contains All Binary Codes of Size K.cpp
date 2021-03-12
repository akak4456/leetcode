class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k)
            return false;
        set<string> setOfStrings;
        for(int i=0;i<=s.size()-k;i++){
            string sub = s.substr(i,k);
            setOfStrings.insert(sub);
        }
        return setOfStrings.size() == pow(2,k);
    }
};