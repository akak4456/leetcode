class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] > 0) ret.push_back(asteroids[i]);
            else if (ret.empty() || ret.back() < 0) 
                ret.push_back(asteroids[i]);
            else if (ret.back() <= -asteroids[i]) {
                if (ret.back() < -asteroids[i]) --i; // repeat bigMinus
                ret.pop_back(); // remove smallPlus
            }
        }
        return ret;
    }
};