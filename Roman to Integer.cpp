class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        int idx = s.size() - 1;
        while(idx >= 0){
            if(s[idx] == 'I'){
                ret += 1;
                idx -= 1;
            }else if(s[idx] == 'V'){
                if(idx > 0 && s[idx-1] == 'I'){
                    ret += 4;
                    idx -= 2;
                }else{
                    ret += 5;
                    idx -= 1;
                }
            }else if(s[idx] == 'X'){
                if(idx > 0 && s[idx-1] == 'I'){
                    ret += 9;
                    idx -= 2;
                }else{
                    ret += 10;
                    idx -= 1;
                }
            }else if(s[idx] == 'L'){
                if(idx > 0 && s[idx - 1] == 'X'){
                    ret += 40;
                    idx -= 2;
                }else{
                    ret += 50;
                    idx -= 1;
                }
            }else if(s[idx] == 'C'){
                if(idx > 0 && s[idx - 1] == 'X'){
                    ret += 90;
                    idx -= 2;
                }else{
                    ret += 100;
                    idx -= 1;
                }
            }else if(s[idx] == 'D'){
                if(idx > 0 && s[idx - 1] == 'C'){
                    ret += 400;
                    idx -= 2;
                }else{
                    ret += 500;
                    idx -= 1;
                }
            }
            else if(s[idx] == 'M'){
                if(idx > 0 && s[idx - 1] == 'C'){
                    ret += 900;
                    idx -= 2;
                }else{
                    ret += 1000;
                    idx -= 1;
                }
            }
        }
        return ret;
    }
};