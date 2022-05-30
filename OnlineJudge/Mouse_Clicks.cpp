// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q25
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Icon {
	public:
		int x, y;
		Icon(int x1, int y1)  {
			x = x1;
			y = y1;
		}
};

class Region {
	public:
		int x1, y1, x2, y2;
		Region(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

class Mouse {
	public:
		void solution();
		bool icon_visibility(Icon);
		void print_selected_icons_or_region(int, int);

	private:
		vector<Icon> icons;
		vector<Region> regions;
};

int main() {
	Mouse mouse;
	mouse.solution();
	return 0;
}

void Mouse::solution() {
	char command;
	int x1, y1, x2, y2;

	while (cin >> command && command != '#') {
		if (command == 'I') {
			cin >> x1 >> y1;
			icons.push_back(Icon(x1, y1));
		} else if (command == 'R') {
			cin >> x1 >> y1 >> x2 >> y2;
			regions.push_back(Region(x1, y1, x2, y2));
		} else if (command == 'M') {
			cin >> x1 >> y1;
			print_selected_icons_or_region(x1, y1);
		}
	}
}

bool Mouse::icon_visibility(Icon icon) {
	for (int i = 0; i < regions.size(); i++) {
		if (icon.x >= regions[i].x1 && icon.y >= regions[i].y1 &&
		        icon.x <= regions[i].x2 && icon.y <= regions[i].y2) {
			return false;
		}
	}
	return true;
}

void Mouse::print_selected_icons_or_region(int x, int y) {
	for (int i = regions.size() - 1; i >= 0; i--) {
		if (x >= regions[i].x1 && y >= regions[i].y1 &&
		        x <= regions[i].x2 && y <= regions[i].y2) {
			cout << char('A' + i) << endl;
			return;
		}
	}

	int min_dist = 1000000;

	for (int i = 0; i < icons.size(); i++) {
		if (icon_visibility(icons[i])) {
			min_dist = min(min_dist, (x - icons[i].x) * (x - icons[i].x) + (y - icons[i].y) * (y - icons[i].y));
		}
	}

	for (int i = 0; i < icons.size(); i++) {
		int dist = (x - icons[i].x) * (x - icons[i].x) + (y - icons[i].y) * (y - icons[i].y);
		if (icon_visibility(icons[i]) && dist == min_dist) {
			cout << setw(3) << i + 1;
		}
	}
	cout << endl;
}
