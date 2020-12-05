class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size();
        while(left <= right){
            //cout << left << ' ' << right << endl;
            int mid = (left+right)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                left = mid+1;
            }else if(nums[mid] > target){
                right = mid-1;
            }
        }
        return -1;
    }
};