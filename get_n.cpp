#include<list>
#include<iostream>
#include<iterator>

using namespace std;

struct Point
{
	int x;
	int y;
};

list<Point> get_neighbors(Point s) {
	int offsetx[] = { 0, 0, 1 , 1, 1, -1, -1, -1 };
	int offsety[] = { -1, 1, -1, 0, 1, -1, 0, 1 };
	list<Point> send;
	Point ss;
	for (int i = 0; i < 8; i++) {
		ss.x = s.x + offsetx[i];
		ss.y = s.y + offsety[i];
		send.push_back(ss);
	}
	
	for (auto i : send) {
		int wx = i.x;
		int wy = i.y;
		if (wx == -1 || wx == 10) {
			send.remove(i);
			continue;
		}
		if (wy == -1 || wy == 10) {
			send.remove(i);
		}
	}
	return(send);
}

int main() {
	list<Point> t;
	Point e;
	e.x = 9;
	e.y = 9;
	t = get_neighbors(e);
	cout << (t.begin())->x << "hi " << endl;
	for (auto i = t.begin(); i != t.end(); i++) {
		cout << i->x << ' ' << i->y << endl;
	}
}