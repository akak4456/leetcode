class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int bar = 0;
        int sz = nums.size();
        int mul = nums[0];
        int ret = 0;
        while(start <sz && end < sz){
            if(mul < k){
              //  cout << " A\n";
                end++;
                if(end < sz){
                    mul *= nums[end];
                }
            }else{
               // cout << " B\n";
                mul /= nums[start];
                ret += (long long int)(end-start)*(end-start+1)/2-(long long int)(bar-start)*(bar-start+1)/2;
                bar = end;
                start++;
                if(start > end){
                    end = start;
                    mul = nums[start];
                }
            }
        }
       ret += (long long int)(end-start)*(end-start+1)/2-(long long int)(bar-start)*(bar-start+1)/2;
        return ret;
    }
};