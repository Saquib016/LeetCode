class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26] = {0};
        for(auto c:s) freq[c-'a']++;
        for(auto c:t) freq[c-'a']--;
        for(int f:freq) if(f!=0) return false;
        return true;
    }

};