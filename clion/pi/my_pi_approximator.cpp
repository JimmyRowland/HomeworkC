#include <string>
#include <iostream>
#include "my_pi_approximator.h"

double pi(int n) {
    int i;
    double val = 0.0;
    for (i = 1; i <= n; i++) {
        if (i % 2 == 1) val += (4.0 / (2.0 * i - 1));
        else val -= (4.0 / (2.0 * i - 1));
    }
    return val;
}