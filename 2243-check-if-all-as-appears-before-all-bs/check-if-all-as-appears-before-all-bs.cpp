class Solution {
public:
    bool checkString(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i = 1;i<s.size();i++){
            if(st.top()=='b' && s[i]=='a') return false;
            else if((st.top()=='a' || st.top()=='b')&& s[i] == 'b') st.push(s[i]);
            else st.push(s[i]);
        }
        return true;
    }
};