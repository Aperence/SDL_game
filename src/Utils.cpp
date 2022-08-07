#include "Utils.h"
#include <vector>

vector<float> operator *(float h, vector<float> v) {
	vector<float> ret = vector<float>(v.size());
	for (size_t i = 0; i < v.size(); i++)
	{
		ret[i] = h * v[i];
	}
	return ret;
}

vector<float> operator +(vector<float> v1, vector<float> v2) {
	vector<float> ret= vector<float>(v1.size());
	for (size_t i = 0; i < v1.size(); i++)
	{
		ret[i] = v1[i] + v2[i];
	}
	return ret;
}

vector <float> operator /( vector<float> v, float h) {
	vector<float> ret = vector<float>(v.size());
	for (size_t i = 0; i < v.size(); i++)
	{
		ret[i] =  v[i] / h;
	}
	return ret;
}

vector<float> Utils::RK4(vector<float> v, vector<float> (*f)(vector<float>), float h) {
	vector<float> K0 = h * f(v);
	vector<float> K1 = h * f(h / 2.0 * K0 + v);
	vector<float> K2 = h * f(h / 2.0 * K1 + v);
	vector<float> K3 = h * f(K2 + v);
	return v + (K0 + K1 + K2 + K3)/6;
}