// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q16
#include<iostream>
#include<cmath>
#include<iomanip>

class Point {
	public:
		Point() {
			x = 0;
			y = 0;
		}
		Point(double _x, double _y) {
			x = _x;
			y = _y;
		}
		double x, y;
};

class Triangle {
	public:
		Triangle(Point a, Point b, Point c) {
			point[0] = a;
			point[1] = b;
			point[2] = c;
		}

		//return the area of this triangle
		//????????
		double getArea() {
			double d_01 = (double)sqrt(pow(point[0].x - point[1].x, 2) + pow(point[0].y - point[1].y, 2));
			double d_02 = (double)sqrt(pow(point[0].x - point[2].x, 2) + pow(point[0].y - point[2].y, 2));
			double d_12 = (double)sqrt(pow(point[1].x - point[2].x, 2) + pow(point[1].y - point[2].y, 2));
			double p = (d_01 + d_02 + d_12) / 2.0;
			double s = (double)sqrt(p * (p - d_01) * (p - d_02) * (p - d_12));
			return s;
		}

		//override operator+ with one parameter which is also a object of Triangle and return the sum of their area.
		//??+?,????Triangle??,?????Triangle?????
		double operator+(Triangle &b){
			return getArea() + b.getArea();
		}
	private:
		Point point[3];
};

int main() {
	double x1, y1, x2, y2, x3, y3;
	std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
	Point a(x1, y1), b(x2, y2), c(x3, y3);
	std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
	Point a2(x1, y1), b2(x2, y2), c2(x3, y3);
	Triangle t1(a, b, c), t2(a2, b2, c2);
	std::cout<<std::fixed<<std::setprecision(2);
	std::cout<<t1.getArea()<<std::endl;
	std::cout<<t2.getArea()<<std::endl;
	std::cout<<t1 + t2<<std::endl;
}
