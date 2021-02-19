class Solution {
    public int findKthPositive(int[] arr, int k) {
        int last = 1;
        for(int i = 0; i < arr.length; i++){
            int newK = k - (arr[i] - last);
            if(newK <= 0){
                break;
            }
            k = newK;
            last = arr[i]+1;
        }
        return last + (k-1);
    }
}