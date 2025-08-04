class Solution {
public:
    string frequencySort(string s) {
       map<char,int> n;
        
        for(char c: s) {
            n[c]++;
        }
        
        vector<pair<char,int>> out;
        copy(n.begin(), n.end(), back_inserter(out));
        
        sort(out.begin(), out.end(), [](const pair<char,int>& a, const pair<char,int>& b) {
            if (a.second == b.second) {
                return a.first < b.first; 
            }
            return a.second > b.second;   
        }); 
        
       string result = ""; 
       
        for (auto& pair : out) {
            int i = pair.second;
            while(i>0){
            result+=pair.first; 
            i--;
            }
        }
        
        return result;
     
    }
};