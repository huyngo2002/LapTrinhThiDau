// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q32
#include <iostream>
using namespace std;
class HTMLElement {
	private:
		string tagName, content;
	public:
		HTMLElement(string s) {
			int p = s.find(">");
			tagName = s.substr(1, p - 1);
			content = s.substr(p  + 1, s.length() - (p + 1) - (p + 2));
		}
		std::string getTagName() {
			return tagName;
		}
		std::string getContent() {
			return content;
		}
};
int main() {
	std::string str;
	getline(std::cin,str);
	HTMLElement html(str);
	std::cout<<html.getTagName()<<std::endl;
	std::cout<<html.getContent()<<std::endl;
	return 0;
}
