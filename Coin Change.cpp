class Solution {
public:
    int cache[10000][12];
    int solve(vector<int>& coins,int remainAmount,int step){
        //cout << remainAmount << ' ' << step << endl;
        if(remainAmount == 0){
            return 0;
        }
        if(remainAmount < 0){
            return 987654321;
        }
        if(step >= coins.size())
            return 987654321;
        int& ret = cache[remainAmount][step];
        if(ret != -1) return ret;
        ret = min(solve(coins,remainAmount,step+1),solve(coins,remainAmount-coins[step],step)+1);
        return ret;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(cache,-1,sizeof(cache));
        int ans = solve(coins,amount,0);
        if(ans == 987654321)
            return -1;
        else
            return ans;
    }
};