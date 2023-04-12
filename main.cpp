// write a function to compute weighted average and weighted standard deviation fo a vector of data

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

// function to compute weighted average
double weighted_average(const vector<double>& data, const vector<double>& weights)
{
    double sum = 0.0;
    double sum_weights = 0.0;
    for (int i = 0; i < data.size(); ++i)
    {
        sum += data[i] * weights[i];
        sum_weights += weights[i];
    }
    return sum / sum_weights;
}

// function to compute weighted standard deviation
double weighted_stddev(const vector<double>& data, const vector<double>& weights)
{
    double sum = 0.0;
    double sum_weights = 0.0;
    double sum_sq = 0.0;
    for (int i = 0; i < data.size(); ++i)
    {
        sum += data[i] * weights[i];
        sum_weights += weights[i];
        sum_sq += data[i] * data[i] * weights[i];
    }
    return sqrt((sum_sq - sum * sum / sum_weights) / (sum_weights - 1));
}

// main fuction  to run the program on some test data
int main()
{
    vector<double> data = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    vector<double> weights = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    cout << "weighted average = " << weighted_average(data, weights) << endl;
    cout << "weighted stddev = " << weighted_stddev(data, weights) << endl;
    return 0;
}
