int reverse(int x) {
	int r = 0;
	int b = (x < 0);
	int overflow = 0;

	if (b)
		x = - x;
	do {
		if ((INT_MAX - x % 10) / 10.0 < r)
			return 0;
		r = r * 10 + x % 10;
		x = x / 10;
	} while (x != 0);

	return (b? (- r) : r);
}
