#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return 1 / (1 + pow(x, 2));
}

int main() {
    double lower, upper, integration = 0.0, stepSize;
    int subInterval;

    cout << "Enter lower limit of integration: ";
    cin >> lower;
    cout << "Enter upper limit of integration: ";
    cin >> upper;
    cout << "Enter number of sub intervals: ";
    cin >> subInterval;

    stepSize = (upper - lower) / subInterval;
    cout << "Step size: " << stepSize << std::endl;

    for (int i = 1; i < subInterval; i++) {
        double k = lower + i * stepSize;
        integration += 2 * f(k);
    }

    integration += f(lower) + f(upper);
    integration = (integration* stepSize) / 2.0;

    cout << "\nRequired value of integration is: " << integration << std::endl;

    return 0;
}
