struct Node{
   map <char, Node*> m;
};
class Solution {
public:
   static bool cmp(string a, string b){
      return a.size() > b.size();
   }
   int insertNode(Node* head, string s){
      Node* curr = head;
      bool flag = false;
      for(int i = s.size() - 1; i >= 0; i--){
         char x = s[i];
         if(!curr->m[x]){
            flag = true;
            curr->m[x] = new Node();
         }
         curr = curr->m[x];
      }
      return flag? (int)s.size() : 0;
   }
   int minimumLengthEncoding(vector<string>& words) {
      int ret = 0;
      Node* head = new Node();
      sort(words.begin(), words.end(), cmp);
      int n = words.size();
      for(int i = 0; i < n; i++){
         int temp= insertNode(head, words[i]);
         if(temp){
            ret += (temp + 1);
         }
      }
      return ret;
   }
};