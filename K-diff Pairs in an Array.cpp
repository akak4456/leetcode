class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int start = 0,end = 0;
        int sz = nums.size();
        set<pair<int,int>> p;
        while(start < sz && end < sz){
            int a = nums[start];
            int b = nums[end];
            if(b-a == k){
                if(start != end)
                    p.insert(make_pair(a,b));
                end++;
            }else if(b-a < k){
                end++;
            }else if(b-a > k){
                start++;
                if(start>end){
                    end = start;
                }
            }
        }
        return p.size();
    }
};