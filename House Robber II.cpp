class Solution {
public:
    int cache1[100];
    int cache2[100];
    int solve1(vector<int>& nums, int start){
        if(start > nums.size()-2){
            return 0;
        }
        int& ret = cache1[start];
        if(ret != -1) return ret;
        ret = solve1(nums,start+1);//안훔침
        ret = max(ret,solve1(nums,start+2)+nums[start]);//훔침
        return ret;
    }
    int solve2(vector<int>& nums, int start){
        if(start > nums.size()-1){
            return 0;
        }
        int& ret = cache2[start];
        if(ret != -1) return ret;
        ret = solve2(nums,start+1);//안훔침
        ret = max(ret,solve2(nums,start+2)+nums[start]);//훔침
        return ret;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        memset(cache1,-1,sizeof(cache1));
        memset(cache2,-1,sizeof(cache2));
        return max(solve1(nums,0),solve2(nums,1));
    }
};