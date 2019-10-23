//dp(i, j) word1[0, i - 1] change to word2[0, j - 1]
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        dp_ = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1, -1));
        return minDistance(word1, word2, l1, l2);
    }
    vector<vector<int>> dp_;
    int minDistance(string word1, string word2, int l1, int l2) {
        if(l1 == 0) return l2;
        if(l2 == 0) return l1;
        if(dp_[l1][l2] >= 0) return dp_[l1][l2];

        int ans = 0;
        if(word1[l1 - 1] == word2[l2 - 1])
            ans = minDistance(word1, word2, l1 - 1, l2 - 1);
        else {
            ans = min(minDistance(word1, word2, l1 - 1, l2 - 1), //replace
                  min(minDistance(word1, word2, l1, l2 - 1), //insert
                      minDistance(word1, word2, l1 - 1, l2))) + 1; //delete
        }
        return dp_[l1][l2] = ans;
    }
};

//
