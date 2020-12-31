class Solution {
    public int largestRectangleArea(int[] heights) {
        if(heights.length == 0){
            return 0;
        }
        if(heights.length == 1){
            return heights[0];
        }
        int[] left = Arrays.copyOfRange(heights,0,heights.length/2);
        int[] right = Arrays.copyOfRange(heights,heights.length/2,heights.length);
        int ret = Math.max(largestRectangleArea(left),largestRectangleArea(right));
        
        int leftIdx,rightIdx;
        leftIdx = rightIdx = heights.length/2;
        int midMaxArea = heights[leftIdx];
        int midMinHeight = heights[leftIdx];
        while(leftIdx-1 >= 0 && rightIdx+1 < heights.length){
            if(heights[leftIdx-1] >= heights[rightIdx+1]){
                midMinHeight = Math.min(heights[leftIdx-1],midMinHeight);
                leftIdx--;
            }else{
               midMinHeight = Math.min(heights[rightIdx+1],midMinHeight);
                rightIdx++;
            }
            midMaxArea = Math.max(midMaxArea,(rightIdx-leftIdx+1)*midMinHeight);
        }
        while(leftIdx-1 >= 0){
            midMinHeight = Math.min(heights[leftIdx-1],midMinHeight);
            leftIdx--;
            midMaxArea = Math.max(midMaxArea,(rightIdx-leftIdx+1)*midMinHeight);
        }
        while(rightIdx+1 < heights.length){
            midMinHeight = Math.min(heights[rightIdx+1],midMinHeight);
            rightIdx++;
             midMaxArea = Math.max(midMaxArea,(rightIdx-leftIdx+1)*midMinHeight);
        }
        ret = Math.max(ret,midMaxArea);
        return ret;
    }
}