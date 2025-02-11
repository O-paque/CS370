#ifndef STATS_H
#define STATS_H

#include <vector>
#include <cmath>

using namespace std;

double average(const vector<double>& data);
double standard_deviation(const vector<double>& data, double& average);

void stats(const vector<double>& data, double& min, double& max, double& avg, double& std_dev){
    // Min and Max variables assume a sorted vector has been passed to stats()
    min = data.front();
    max = data.back();
    avg = average(data);
    std_dev = standard_deviation(data, avg);
}

void sort (vector<double>& data) {
    for (int i = 0; i < data.size(); i++){
        for (int j = i+1; j < data.size(); j++){
            if (data[j] < data[i]){
                double temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

double average(const vector<double>& data) {
    double total = 0;
    for (int i = 0; i < data.size(); i++){
        total += data[i];
    }
    total /= data.size();
    return total;
}

double standard_deviation(const vector<double>& data, double& average) {
    double sq_sum = 0, temp;

    for (int i = 0; i < data.size(); i++){
        temp = data[i] - average;
        temp = pow(temp, 2);
        sq_sum += temp;
    }
    // Variance = sq_sum / N, standard deviation is sqrt(Variance)
    return sqrt(sq_sum / data.size());
}

#endif