class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0)
            return 1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(nums[i] != i+1){
                if(nums[i] <= 0 || nums[i] >= n)
                    break;
                if(nums[i] == nums[nums[i]-1])
                    break;
                int temp = nums[i];
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }
        }
        for(int i=0;i<n;i++){
        if(nums[i] != i+1){
            return i+1;
        }
    }
        return n+1;
    }
};