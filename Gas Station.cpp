class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size();
        for(int start = 0;start < sz;start++){
            int tank = gas[start];
            bool canDo = true;
            for(int i=1;i<sz;i++){
                tank -= cost[(start+i-1+sz)%sz];
                if(tank < 0){
                    canDo = false;
                    break;
                }
                tank += gas[(start+i)%sz];
            }
            if(canDo&&tank >= cost[(start-1+sz)%sz]){
                return start;
            }
        }
        return -1;
    }
};