// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q6
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int get(int n1, int n2) {
	if(n1>n2)
		swap (n1, n2);
	if((n1==1&&n2==1)||(n1==1&&n2==2))
		return 1;
	else if((n1==1&&n2==3)||(n1==2&&n2==2))
		return 2;
	else if ((n1==2&&n2==3)||(n1==3&&n2==3))
		return 3;
	else
		return 0;
}
int main() {
	ios::sync_with_stdio(false), cin. tie(0);
	int n;
	cin>>n;
	map<string, int>m;
	map<string, pair<string, string>>mp;
	string str1, str2;
	while(n--) {
		cin>>str1>>str2;
		if(str2=="non-existent")
			m[str1] = 1;
		else if(str2=="recessive")
			m[str1] = 2;
		else if(str2=="dominant")
			m[str1] = 3;
		else {
			if(mp[str2].second=="#")
				mp[str2].second = str1;
			else
				mp [str2] = {str1,"#"};
		}
	}
	int k = mp.size();
	while (k) {
		for (auto it:mp)
			if(!m[it.first] &&(m[it. second.first] &&m[it.second. second])) {
				m[it.first] = get (m[it.second.first], m[it.second. second]);
				k--;
			}
	}

	for(auto it:m) {
		cout<<it.first<< ' ';
		    if(it.second<=1)
		    cout<<"non-existent\n";
		    else if (it. second==2)
		    cout<<"recessive\n";
		    else
		    cout<<"dominant\n";
	    }
		    return 0;
}
