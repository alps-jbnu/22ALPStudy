#include <iostream>
using namespace std;

long long n, m, curMove;

void rec(long long l, long long x, long long y, int deg) {
	if (l == 0) {
		cout << x << " " << y << "\n";
		return;
	}

	if (deg == 0) {
		if (curMove + l * l >= m) rec(l / 2, x - l, y - l, 90);
		else if (curMove + l * l * 2 >= m) { curMove += l * l; rec(l / 2, x - l, y, 0); }
		else if (curMove + l * l * 3 >= m) { curMove += l * l * 2; rec(l / 2, x, y, 0); }
		else { curMove += l * l * 3; rec(l / 2, x, y - l, 270); }
	}
	else if (deg == 90) {
		if (curMove + l * l >= m) rec(l / 2, x - l, y - l, 0);
		else if (curMove + l * l * 2 >= m) { curMove += l * l; rec(l / 2, x, y - l, 90);  }
		else if (curMove + l * l * 3 >= m) { curMove += l * l * 2; rec(l / 2, x, y, 90);  }
		else { curMove += l * l * 3; rec(l / 2, x - l, y, 180);  }
	}
	else if (deg == 180) {
		if (curMove + l * l >= m) rec(l / 2, x, y, 270);
		else if (curMove + l * l * 2 >= m) { curMove += l * l; rec(l / 2, x, y - l, 180); }
		else if (curMove + l * l * 3 >= m) { curMove += l * l * 2; rec(l / 2, x - l, y - l, 180);  }
		else { curMove += l * l * 3; rec(l / 2, x - l, y, 90);  }
	}
	else if (deg == 270) {
		if (curMove + l * l >= m) rec(l / 2, x, y, 180);
		else if (curMove + l * l * 2 >= m) { curMove += l * l; rec(l / 2, x - l, y, 270);  }
		else if (curMove + l * l * 3 >= m) { curMove += l * l * 2; rec(l / 2, x - l, y - l, 270);  }
		else { curMove += l * l * 3; rec(l / 2, x, y - l, 0);  }
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	rec(n / 2, n, n, 0);

	return 0;
}