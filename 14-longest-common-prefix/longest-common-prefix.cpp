class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        if(strs.empty()) return "";
        for(int i=1;i<strs.size();i++){
            string comp = strs[i];
            while(comp.find(prefix)!=0){
                prefix = prefix.substr(0,prefix.size()-1);
                if(prefix.empty()) return "";
            }
        }
        return prefix;
    }
};