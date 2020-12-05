class Solution {
public:
    vector<vector<int>> ret;
    void solve(vector<int>& candidates,int target,int start,vector<int> cur,int curSum){
        if(curSum > target){
            return;
        }
        if(curSum == target){
            ret.push_back(cur);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            cur.push_back(candidates[i]);
            curSum += candidates[i];
            solve(candidates,target,i,cur,curSum);
            cur.pop_back();
            curSum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        solve(candidates,target,0,tmp,0);
        return ret;
    }
};