class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int poppedIdx = 0;
        for(int i=0;i<pushed.size();i++){
            st.push(pushed[i]);
            while(poppedIdx < popped.size() &&!st.empty()&& st.top() == popped[poppedIdx]){
                st.pop();
                poppedIdx++;
            }
        }
        return st.empty();
    }
};