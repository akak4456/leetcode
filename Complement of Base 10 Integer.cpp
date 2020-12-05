class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0)
            return 1;
        if(N == 1)
            return 0;
        string tmp = "";
        while(N > 0){
            tmp += (N%2) +'0';
            N /= 2;
        }
        int sum = 0;
        int mul = 1;
        for(int i=0;i<tmp.size();i++){
            if(tmp[i] == '0'){
                sum += mul;
            }
            mul *= 2;
        }
        return sum;
    }
};