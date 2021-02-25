class Solution {
public:
    int solve(string src){
        cout << src << endl;
        if(src.size() == 0)
            return 1;
        stack<char> st;
        int ret = 0;
        int startPos = 0;
        for(int i=0;i<src.size();i++){
            if(src[i] == '('){
                st.push(src[i]);
            }else{
                st.pop();
                if(st.empty()){
                    ret += solve(src.substr(startPos+1,i-startPos-1));
                    startPos = i+1;
                }
            }
        }
        return ret * 2;
    }
    int scoreOfParentheses(string S) {
        return solve(S) / 2;
    }
};