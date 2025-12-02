#ifndef KNN_H
#define KNN_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class KNN {
protected:
    int k;

public:
    KNN() : k(1) {}

    KNN(int _k) : k(_k) {}

    virtual ~KNN() {}
    virtual double similarityMeasure(T val1, T val2) = 0;
    vector<int> findNearestNeighbors(const vector<T>& trainData, T target) {
        vector<pair<double, int>> distances;
        for (int i = 0; i < trainData.size(); ++i) {
            double dist = similarityMeasure(trainData[i], target);
            distances.push_back({dist, i});
        }
        sort(distances.begin(), distances.end(), [](const pair<double, int>& a, const pair<double, int>& b) {
            return a.first < b.first;
        });
        vector<int> resultIndices;
        int limit = (k < distances.size()) ? k : distances.size();
        for (int i = 0; i < limit; ++i) {
            resultIndices.push_back(distances[i].second);
        }
        return resultIndices;
    }
};

#endif