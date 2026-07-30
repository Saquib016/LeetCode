
class Solution {
public:
    bool isPalindrome(string s){
        int i = 0,j=s.size()-1;
        while (i < j) {
    if (!isalnum(s[i])) { i++; }        // Skip one non-alphanumeric on the left
    else if (!isalnum(s[j])) { j--; }   // Skip one non-alphanumeric on the right
    else if (tolower(s[i]) != tolower(s[j])) { return false; }
    else { i++; j--; }
}

        return true;
    }
};