#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Utils {
public:
	static vector<float> RK4(vector<float> v, vector<float> (*f)(vector<float>), float h = 2.0);
};

#endif
