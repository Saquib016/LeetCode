class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        vector<int> maxsuf(word1.size(),0);
        int i = word1.size()-1;
        int j = word2.size()-1;
        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
            int suffsize = (word2.size()-(j+1))+1;
            maxsuf[i] = suffsize;
            i--;
            j--;
            }
            else{
                if(i+1<word1.size())
                maxsuf[i] = maxsuf[i+1];
                i--;
            }
        }
        i = 0;
         j= 0;
        vector<int> word;
        bool change = false;
        while(i<word1.size()&& j<word2.size()){
            if(word1[i]==word2[j]){
                word.push_back(i);
                i++;
                j++;
            }
            // not change and (either last or the suffix can still be matched)
            else if(!change && (j==word2.size()-1 ||
                     ((size_t)(i+1)<word1.size() && maxsuf[i+1]>=(word2.size()-(j+1))))){
                change = true;
                word.push_back(i);
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j!=word2.size()) return {};
        return word;
    }

};