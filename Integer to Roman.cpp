class Solution {
public:
    string intToRoman(int num) {
        string ret = "";
        while(num > 0){
            if(num >= 1000){
                ret += "M";
                num -= 1000;
            }else if(num >= 900){
                ret += "CM";
                num -= 900;
            }else if(num >= 500){
                ret += "D";
                num -= 500;
            }else if(num >= 400){
                ret += "CD";
                num -= 400;
            }else if(num >= 100){
                ret += "C";
                num -= 100;
            }else if(num >= 90){
                ret += "XC";
                num -= 90;
            }else if(num >= 50){
                ret += "L";
                num -= 50;
            }else if(num >= 40){
                ret += "XL";
                num -= 40;
            }else if(num >= 10){
                ret += "X";
                num -= 10;
            }else if(num >= 9){
                ret += "IX";
                num -= 9;
            }else if(num >= 5){
                ret += "V";
                num -= 5;
            }else if(num >= 4){
                ret += "IV";
                num -= 4;
            }else{
                ret += "I";
                num -= 1;
            }
        }
        return ret;
    }
};