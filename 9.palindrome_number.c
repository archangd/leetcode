bool isPalindrome(int x) {
	int rev = 0;

	if (x < 0)
		return false;

	if (x == 0)
		return true;

	while (42) {
		rev = rev * 10 + x % 10;
		if (rev == 0)
			return false;

		x = x / 10;

		if (x == rev)
			return true;

		if (x < rev)
			return (x == rev / 10);
	}
}
