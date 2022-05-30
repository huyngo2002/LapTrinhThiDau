// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q17
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class PokerCard {
	public:
		PokerCard(std::string s, int f) {
			suit = s;
			face = f;
		}
		friend std::ostream &operator<<(std::ostream &out, const PokerCard &p) {
			out<<"["<<p.face<<" of "<<p.suit<<"]";
			return out;
		}

		//Please finish the operator override
		//????????
		//spade > heart > diamond > club
		//1 > 13 > 12 > 11 > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2
		bool operator>(PokerCard &b) {
			if (face == 1 && b.face != 1)
				return true;
			if (face > b.face and b.face != 1)
				return true;
			if (face > b.face and b.face == 1)
				return false;
			if (face == b.face) {
				if (suit == b.suit)
					return false;
				if (suit == "spade")
					return true;
				if (suit == "heart") {
					if (b.suit == "spade")
						return false;
					else
						return true;
				}
				if (suit == "diamond") {
					if (b.suit == "club")
						return true;
					else
						return false;
				}
				if (suit == "club")
					return false;
			}
			if (face < b.face)
				return false;
		}
		bool operator<(PokerCard &b) {
			if (face == 1 && b.face != 1)
				return false;
			if (face > b.face and b.face != 1)
				return false;
			if (face > b.face and b.face == 1)
				return true;
			if (face == b.face) {
				if (suit == b.suit)
					return false;
				if (suit == "spade")
					return false;
				if (suit == "heart") {
					if (b.suit == "spade")
						return true;
					else
						return false;
				}
				if (suit == "diamond") {
					if (b.suit == "club")
						return false;
					else
						return true;
				}
				if (suit == "club")
					return true;
			}
			if (face < b.face)
				return true;
		}
		bool operator==(PokerCard &b) {
			if (face == b.face && suit == b.suit)
				return true;
			else
				return false;
		}

	private:
		std::string suit;
		int face;
};

int main() {
	PokerCard **card = (PokerCard **)malloc(sizeof(PokerCard *) * 52);

	std::string s[] = {"spade", "heart", "diamond", "club"};
	int j, k;
	for(j = 0; j < 4; j ++)
		for(k = 1; k <= 13; k ++)
			card[j * 13 + k - 1] = new PokerCard(s[j], k);
	for(j = 0; j < 52; j ++) {
		for(k = 0; k < 52; k ++) {
			std::cout<<*(card[j])<<">"<<*(card[k])<<":"<<(*(card[j])>*(card[k]))<<std::endl;
			std::cout<<*(card[j])<<"<"<<*(card[k])<<":"<<(*(card[j])<*(card[k]))<<std::endl;
			std::cout<<*(card[j])<<"=="<<*(card[k])<<":"<<(*(card[j])==*(card[k]))<<std::endl;
		}
	}
}
