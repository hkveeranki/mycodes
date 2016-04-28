#include<iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int p, q, r, s, t, u;
inline double f(double x) {return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;}
double solve() {
	double lo = 0, hi = 1;
	while (lo + (1e-7) < hi) {
		double x = (lo + hi) / 2;
		if (f(lo) * f(x) <= 0) 
			hi = x;
		 else 
			lo = x;
	}
	return (lo + hi) / 2;
}
int main() {
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) 
		if (f(0) * f(1) > 0) cout<<"No solution"<<endl;
		 else printf("%.4lf\n", solve());
	return 0;
}
