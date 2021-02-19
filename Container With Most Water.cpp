class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftIdx = 0, rightIdx = height.size()-1;
        int ret = 0;
        while(leftIdx < rightIdx){
            ret = max(ret,min(height[leftIdx],height[rightIdx]) * (rightIdx - leftIdx));
            if(height[leftIdx] < height[rightIdx]){
                leftIdx++;
            }else{
                rightIdx--;
            }
            
        }
        return ret;
    }
};