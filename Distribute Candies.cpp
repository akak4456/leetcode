class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> uniqueType;
        for(int i=0;i<candyType.size();i++){
            uniqueType.insert(candyType[i]);
        }
        return min(uniqueType.size(),candyType.size()/2);
    }
};