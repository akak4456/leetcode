class Solution {
public:
    bool isPalindrome(string s){
        int left = 0;
        int right = s.size()-1;
        while(right > left){
            if(s[left++] != s[right--])
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s == "")
            return 0;
        else if(isPalindrome(s))
            return 1;
        else
            return 2;
    }
};