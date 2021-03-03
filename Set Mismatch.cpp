class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> s;
        int duplicate = -1;
        for(int i=1;i<=nums.size();i++){
            s.insert(i);
        }
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]) == s.end()){
                duplicate = nums[i];
            }
            s.erase(nums[i]);
        }
        vector<int> ret;
        ret.push_back(duplicate);
        ret.push_back(*s.begin());
        return ret;
    }
};