#ifndef KNNDOUBLE_H
#define KNNDOUBLE_H

#include "KNN.h"
#include <utility>
#include <cmath>

class KNNDouble : public KNN<pair<double, double>> {
public:
    KNNDouble(int k) : KNN<pair<double, double>>(k) {}

    double similarityMeasure(pair<double, double> val1, pair<double, double> val2) override {
        double diff1 = val1.first - val2.first;
        double diff2 = val1.second - val2.second;
        return sqrt(pow(diff1, 2) + pow(diff2, 2));
    }
};

#endif