#ifndef KNNSTRING_H
#define KNNSTRING_H

#include "KNN.h"
#include <string>
#include <vector>
#include <algorithm>

class KNNString : public KNN<vector<string>> {
private:
    int levenshteinDistance(const string& s1, const string& s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({ dp[i][j - 1],
                                         dp[i - 1][j],
                                         dp[i - 1][j - 1]
                                       });
            }
        }
        return dp[m][n];
    }

public:
    KNNString(int k) : KNN<vector<string>>(k) {}

    double similarityMeasure(vector<string> val1, vector<string> val2) override {
        double totalDistance = 0;
        int size = min(val1.size(), val2.size());
        for(int i = 0; i < size; i++) {
            totalDistance += levenshteinDistance(val1[i], val2[i]);
        }
        return totalDistance;
    }
};

#endif