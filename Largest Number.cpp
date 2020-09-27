bool sortBy(string a, string b){
    return (a+b) < (b+a);
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numList[10];
        for(int i=0;i<nums.size();i++){
            string tmp = to_string(nums[i]);
            numList[tmp[0]-'0'].push_back(tmp);
        }
        for(int i=0;i<10;i++){
            sort(numList[i].begin(),numList[i].end(),sortBy);
        }
        string ret = "";
        for(int i=9;i>=0;i--){
            for(int j=numList[i].size()-1;j>=0;j--){
                ret += numList[i][j];
            }
        }
        while(ret[0] == '0' && ret.size() > 1){
            ret.erase(0,1);
        }
        return ret;
    }
};