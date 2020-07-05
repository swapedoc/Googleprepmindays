struct pt {
	double x, y;
};

bool cmp (pt a, pt b) {
	return ax <bx || ax == bx && ay <by;
}

bool cw (pt a, pt b, pt c) {
	return ax * (by-cy) + bx * (cy-ay) + cx * (ay-by) <0;
}

bool ccw (pt a, pt b, pt c) {
	return ax * (by-cy) + bx * (cy-ay) + cx * (ay-by)> 0;
}

void convex_hull (vector <pt> & a) {
	if (a.size () == 1) return;
	sort (a.begin (), a.end (), & cmp);
	pt p1 = a [0], p2 = a.back ();
	vector <pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i = 1; i <a.size (); ++ i) {
		if (i == a.size () - 1 || cw (p1, a [i], p2)) {
			while (up.size ()> = 2 &&! cw (up [up.size () - 2], up [up.size () - 1], a [i]))
				up.pop_back ();
			up.push_back (a [i]);
		}
		if (i == a.size () - 1 || ccw (p1, a [i], p2)) {
			while (down.size ()> = 2 &&! ccw (down [down.size () - 2], down [down.size () - 1], a [i]))
				down.pop_back ();
			down.push_back (a [i]);
		}
	}
	a.clear ();
	for (size_t i = 0; i <up.size (); ++ i)
		a.push_back (up [i]);
	for (size_t i = down.size () - 2; i> 0; --i)
		a.push_back (down [i]);
}

73 70 41 81 29
78 60 55 75 32
50 70 50 60 45
70 35 85 75 30
45 63 69 60 45
90 50 40 75 25
77 68 47 78 28
62 55 53 55 58
49 63 67 60 53
47 62 68 60 55
50 70 50 60 45
65 45 60 60 60
45 60 76 60 50
85 20 80 75 30
55 67 54 54 46
54 67 54 66 62
75 52 60 65 55
57 62 51 55 50
85 30 52 50 95
60 55 56 40 45
75 66 60 80 42
85 30 52 50 95
72 75 31 37 43
70 60 41 40 55
80 35 60 45 95
65 65 41 40 50
65 75 38 40 45
70 55 48 60 66
75 40 60 75 42
m21>arctic>akm>hvk>ak117
monowar>>chicom
chicom>rus-79u