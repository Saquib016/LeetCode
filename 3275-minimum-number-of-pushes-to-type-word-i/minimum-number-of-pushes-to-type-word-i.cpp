class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int totalPushes = 0;
        
        // Group letters by chunks of 8 based on keypad capacity
        for (int i = 0; i < n; i++) {
            if (i < 8) {
                totalPushes += 1;  // First 8 letters take 1 push each
            } else if (i < 16) {
                totalPushes += 2;  // Next 8 letters take 2 pushes each
            } else if (i < 24) {
                totalPushes += 3;  // Next 8 letters take 3 pushes each
            } else {
                totalPushes += 4;  // Remaining letters take 4 pushes each
            }
        }
        
        return totalPushes;
    }
};
