// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q42
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Convert {
	public:
		Convert() {};
		Convert(string s):str(s) {
			flag = 0;
			if(str.find(".") != string::npos)
				flag = 1;
		}
		int toInt() {
			if(flag==0) {
				int n;
				stringstream s;
				s << str;
				s >> n;
				return n;
			}
			return 0;
		}
		double toDouble() {
			if(flag==1) {
				return stold(str);
			}
			return 0;
		}
	private:
		string str;
		int flag;
};
