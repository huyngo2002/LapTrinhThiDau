// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q36
class Convert {
	public:
		static string toString(int n) {
			return to_string(n); 
		}
		static string toString(char c) {
			return string(1, c);
		}
		static string toString(double d) {
			string res = to_string(d);
			int lsd;
			for( lsd = res.length() - 1; lsd>0 && res[lsd] == '0'; lsd--);
			res = res.substr(0, lsd + 1);
			return res;
		}
		static string toString(Point p) {
			string s = "";
			s = s + "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
			return s;
		}
};
