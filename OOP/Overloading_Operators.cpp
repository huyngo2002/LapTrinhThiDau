// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q13
#include<iostream>
using namespace std;
class Coordinate {

		int x, y;
	public:
		int getX() {
			return x;
		}
		int getY() {
			return y;
		}
		void setX(int val) {
			x = val;
		}
		void setY(int val) {
			y = val;
		}
		void showCoordInfo() {
			cout << "(" << x << ", " << y << ")" << endl;
		}
		Coordinate() { // default constructor
			x = 0;
			y = 0;
		}
		Coordinate(const Coordinate &i) { // copy constructor
			x = i.x;
			y = i.y;
		}
		Coordinate(int X, int Y) {
			x = X;
			y = Y;
		}
		bool operator>(Coordinate &b) {
			if (x > b.x && y > b.y)
				return true;
			return false;
		}
		bool operator<(Coordinate &b) {
			if (x < b.x && y < b.y)
				return true;
			return false;
		}
		bool operator==(Coordinate &b) {
			if (x == b.x && y == b.y)
				return true;
			return false;
		}
		Coordinate operator + (Coordinate &b) {
			Coordinate result;
			result.x = x + b.x;
			result.y = y + b.y;
			return result;
		}
		Coordinate operator - (Coordinate &b) {
			Coordinate result;
			result.x = x - b.x;
			result.y = y - b.y;
			return result;
		}

};
