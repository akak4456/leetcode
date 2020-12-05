class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> g;
        for(int i=0;i<equations.size();i++){
            g[equations[i][0]].emplace(equations[i][1],values[i]);
            g[equations[i][0]].emplace(equations[i][0],1.0);
            g[equations[i][1]].emplace(equations[i][0],1.0/values[i]);
            g[equations[i][1]].emplace(equations[i][1],1.0);
        }
        vector<double> res;
        for(auto item:queries){
            if(!g.count(item[0])||!g.count(item[1])) res.push_back(-1.0);
            else{
                queue<pair<string,double>> qs;
                unordered_set<string> used;
                qs.push({item[0],1.0});
                used.insert(item[0]);
                bool find = false;
                while(!qs.empty()&&!find){
                    queue<pair<string,double>> nex;
                    while(!qs.empty()&&!find){
                        pair<string,double> tp = qs.front();
                        qs.pop();
                        
                        //check whether we find the divident
                        if(tp.first == item[1]){
                            find = true;
                            res.push_back(tp.second);
                            break;
                        }
                        
                        for(pair<string,double> values:g[tp.first]){
                            if(used.find(values.first) == used.end()){
                                values.second *= tp.second;
                                nex.push(values);
                                used.insert(values.first);
                            }
                        }
                    }
                    
                    qs = nex;
                }
                
                if(!find) res.push_back(-1.0);
            }
        }
        
        return res;
    }
    
};