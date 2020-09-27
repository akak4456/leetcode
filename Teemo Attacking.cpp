class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ret = 0;
        int nxt = 0;
        int sz = timeSeries.size();
        while(nxt < sz){
            int start = timeSeries[nxt];
            int end = start + duration - 1;
            nxt++;
            while(nxt<sz && timeSeries[nxt] <= end){
                end = timeSeries[nxt] + duration - 1;
                nxt++;
            }
            ret += end-start+1;
        }
        return ret;
    }
};