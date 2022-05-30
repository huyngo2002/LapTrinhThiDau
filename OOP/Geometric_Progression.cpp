// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q15
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class F{
	private:
		double a, r;
	public:
		F(double _a, double _r){
			a = _a;
			r = _r;
		}
		double at(int x){
			return a * pow(r, x);
		}
		double* S(){
			if (-1 < r and r < 1){
				if (r == 1)	return NULL;
				double res = a / (1 - r);
				double *k = new double[1];
				k[0] = res;
				return k;
			}
			else{
				return NULL;
			}
		}
};

int main()
{
	int j, k;
	double a, r;
	cin>>a>>r;
	F f(a, r);
	for(k = 0;k < 3;k ++)
		printf("%.2lf\n", f.at(k));
	double *s = f.S();
    if(s == NULL)
      printf("NULL\n");
  else
	printf("%.2lf\n", *s);
}
