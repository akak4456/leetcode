class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length() == 0)
            return 0;
        int maxLen = 1;
        String window = "";
        for(int i = 0;i<s.length();i++){
            while(window.length() > 0&&window.indexOf(s.charAt(i)) != -1){
                window = window.substring(1);
            }
            window += s.charAt(i);
            maxLen = Math.max(maxLen,window.length());
        }
        return Math.max(maxLen,window.length());
    }
}