class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ret = 987654321;
        int sz = A.size();
        for(int num=1;num<=6;num++){
            int cnt = 0;
            bool canFinish = true;
            for(int i=0;i<sz;i++){
                if(A[i] != num){
                    if(B[i] != num){
                        canFinish = false;
                        break;
                    }else{
                        cnt++;
                    }
                }
            }
            if(canFinish){
                ret = min(ret,cnt);
            }
            cnt = 0;
            canFinish = true;
            
             for(int i=0;i<sz;i++){
                if(B[i] != num){
                    if(A[i] != num){
                        canFinish = false;
                        break;
                    }else{
                        cnt++;
                    }
                }
            }
            if(canFinish){
                ret = min(ret,cnt);
            }
        }
        if(ret == 987654321){
            return -1;
        }
        return ret;
    }
};