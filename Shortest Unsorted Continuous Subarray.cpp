class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxVal = -987654321;
        int minVal = 987654321;
        int idx1=-1,idx2=-1;
        for(int i=0;i<nums.size();i++){
            if(maxVal < nums[i]){
                maxVal = nums[i];
            }else if(nums[i] < maxVal){
                idx1 = i;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] < minVal){
                minVal = nums[i];
            }else if(minVal < nums[i]){
                idx2 = i;
            }
        }
        cout << idx1 << ' ' << idx2 << endl;
        if(idx1 == -1)
            return 0;
        else
            return idx1-idx2+1;
    }
};