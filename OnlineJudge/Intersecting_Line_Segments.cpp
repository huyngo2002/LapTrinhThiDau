// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q24
#include <iostream>
#include <vector>
using namespace std;

class Coordinate {
	public:
		int x, y;
};

class Segment {
	public:
		Coordinate a, b;
};

class CartesianPlane {
	public:
		bool isIntersecting(Segment, Segment);
		void solution();
};

int main() {
	CartesianPlane plane;
	plane.solution();
	return 0;
}

bool CartesianPlane::isIntersecting(Segment s1, Segment s2) {
	// Calculating the equation of the line of the segment `s1`.
	float A1 = s1.b.y - s1.a.y;
	float B1 = s1.a.x - s1.b.x;
	float C1 = A1 * s1.a.x + B1 * s1.a.y;

	// Calculating the equation of the line of the segment `s2`.
	float A2 = s2.b.y - s2.a.y;
	float B2 = s2.a.x - s2.b.x;
	float C2 = A2 * s2.a.x + B2 * s2.a.y;

	// Calculating the determinant.
	float det = A1 * B2 - A2 * B1;

	// If the determinant is zero, the lines are parallel or colinear.
	if (det == 0) {
		return false;
	}

	// Calculating the point of intersection.
	float x = (B2 * C1 - B1 * C2) / det;
	float y = (A1 * C2 - A2 * C1) / det;

	// Calculating the ratio of the distance between the intersection point and the segment endpoints.
	float rx1 = (x - s1.a.x) / (s1.b.x - s1.a.x);
	float ry1 = (y - s1.a.y) / (s1.b.y - s1.a.y);
	float rx2 = (x - s2.a.x) / (s2.b.x - s2.a.x);
	float ry2 = (y - s2.a.y) / (s2.b.y - s2.a.y);

	// Checking if the point of intersection is on both lines.
	return ((rx1 >= 0 && rx1 <= 1) || (ry1 >= 0 && ry1 <= 1)) &&
	       ((rx2 >= 0 && rx2 <= 1) || (ry2 >= 0 && ry2 <= 1));
}

void CartesianPlane::solution() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<Segment> segments(N);
		for (int i = 0; i < N; ++i) {
			cin >> segments[i].a.x >> segments[i].a.y;
			cin >> segments[i].b.x >> segments[i].b.y;
		}
		int count = N;
		for (int i = 0; i < N - 1; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (isIntersecting(segments[i], segments[j])) {
					count += 2;
				}
			}
		}
		cout << count << endl;
		if (T) {
			cout << endl;
		}
	}
}
