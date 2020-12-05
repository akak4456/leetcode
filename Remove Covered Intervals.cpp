class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<bool> deleted = vector<bool>(intervals.size(),false);
        int ret = intervals.size();
        for(int i=0;i<intervals.size();i++){
            if(deleted[i])
                continue;
            for(int j=0;j<intervals.size();j++){
                if(i != j&&intervals[j][0] <= intervals[i][0]&&intervals[i][1] <= intervals[j][1]){
                    deleted[i] = true;
                    ret--;
                    break;
                }
            }
        }
        return ret;
    }
};