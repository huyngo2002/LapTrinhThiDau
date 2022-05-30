// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q7
Segment(Coordinate _a, Coordinate _b) {
	a = _a;
	b = _b;
}
Coordinate *getIntersection(Segment s) { // ??????????,??????????????,???????NULL
	float a1 = (float)(b.getY() - a.getY())/(b.getX() - a.getX());
	float b1 = (float)a.getY() - a1*a.getX();
	float a2 = (float)(s.b.getY() - s.a.getY())/(s.b.getX() - s.a.getX());
	float b2 = (float)s.a.getY() - a2*s.a.getX();
	if(a1 == a2) {
		return NULL;
	}
	int x = (b2 - b1)/(a1 - a2);
	int y1 = a1*x + b1;
	if(a.getX() < b.getX()) {
		if(x < a.getX() or x > b.getX())
			return NULL;
	} else {
		if(x > a.getX() or x < b.getX())
			return NULL;
	}

	int y2 = a2*x + b2;
	if(y2 != y1)
		return NULL;



	Coordinate *c = new Coordinate(x, y1);
	return c;
}
float length() {
	double d = (double)(pow(a.getX()-b.getX(), 2) + pow(a.getY()-b.getY(), 2));
	return (float)sqrt(d);
}
