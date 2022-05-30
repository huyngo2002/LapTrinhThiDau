// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q33
class HTMLElementWithAttributes : public HTMLElement {
	public:
		HTMLElementWithAttributes(string s) : HTMLElement(s) {
			size_t p = s.find(">");
			tagName = s.substr(1, p-1);
			p = tagName.find(" ");
			if(p == NULL) {
				return;
			}
			string aString = tagName.substr(p);
			tagName = tagName.substr(0, p);
			string aName, aValue;
			while(aString.size() > 2) {
				p = aString.find("=");
				aName = aString.substr(1, p-1);
				aString.erase(0, p+2);
				p = aString.find("\"");
				aValue = aString.substr(0, p);
				aString.erase(0, p+1);
				//attributes.insert(pair<string,string>(aName, aValue));
				attributes[aName] = aValue;
			}
		}

		list<string> getAttributes() {
			list<string> res;
			map<string, string>::iterator it;
			for (it = attributes.begin(); it != attributes.end(); it++) {
				res.push_back(it->first);
			}
			return res;
		}

		string operator[](string key) {
			map<string, string>::iterator it;
			for (it = attributes.begin(); it != attributes.end(); it++) {
				if(it->first == key)
					return (it->second);
			}
		}
	private:
		map<string, string> attributes ;
};
int main() {
	std::string str;
	getline(std::cin,str);
	HTMLElementWithAttributes html(str);
	std::cout << html.getTagName() << endl ;
	std::list<std::string> key = html.getAttributes();
	for(std::string k : key)
		std::cout<<html[k]<<std::endl;
	return 0;
}
