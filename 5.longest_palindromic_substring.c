char *longestPalindrome(char *s)
{
	int i = 0, max_length = 0, length = 0;
	char *c = s;
	char *temp = s, *retval;
	
	for (i = 0; s[i] != '\0'; i++) {
		length = 1;
		for (int j = 1; j <= i; j++) {
			if (s[i + j] == '\0' || s[i + j] != s[i - j])
				break;
			length += 2;
		}
		if (length > max_length) {
			max_length = length;
			temp = s + (i - (length - 1) / 2);
		}

		if (s[i] == s[i + 1]) {
			length = 2;
			for (int j = 1; j <= i; j++) {
				if (s[i + 1 + j] == '\0' || s[i + 1 + j] != s[i - j])
					break;
				length += 2;
			}
			if (length > max_length) {
				max_length = length;
				temp = s + (i - (length - 2) / 2);
			}
		}
	}

	retval = (char *)malloc(sizeof(char) * (max_length + 1));
	for (i = 0; i < max_length; i++)
		retval[i] = *(temp + i);
	retval[i] = '\0';
	return  retval;
}
