class Solution {
public:
    const int MOD = 1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) {
       int cnt[1000];
        sort(arr.begin(),arr.end());//작은 수부터 큰 수까지
        cnt[0] = 1;
        for(int rootIdx=1;rootIdx<arr.size();rootIdx++){
            long long int calcCnt = 1;
            for(int firstIdx = 0;firstIdx<rootIdx;firstIdx++){
                if(arr[rootIdx]%arr[firstIdx] == 0){
                    for(int secondIdx = firstIdx;secondIdx < rootIdx;secondIdx++){
                        if(arr[rootIdx]/arr[firstIdx] == arr[secondIdx]){
                            if(arr[firstIdx] == arr[secondIdx]){
                                calcCnt += ((long long int)cnt[firstIdx] * cnt[secondIdx])%MOD;
                            }else{
                                calcCnt += ((long long int)cnt[firstIdx] * cnt[secondIdx] * 2)%MOD;
                            }
                            calcCnt %= MOD;
                            break;
                        }
                    }
                }
            }
            cnt[rootIdx] = calcCnt;
        }
        int ret = 0;
        for(int i=0;i<arr.size();i++){
            ret += cnt[i];
            ret %= MOD;
        }
        return ret;
    }
};