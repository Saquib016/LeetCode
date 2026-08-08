class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        for(auto c: s) freq[c-'a']++;
        for(int i =0;i<s.size();i++){
            int c = s[i];
            if(freq[c-'a']==1) return i;
        }
        return -1;

    }
};