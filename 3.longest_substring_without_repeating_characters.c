int lengthOfLongestSubstring (char *s)
{
	int *hash, i, k = 0, temp, key, val;
	int length = 0, max_length = 0;

	hash = (int *)malloc(sizeof(int) * 128);
	for (i = 0; i < 128; i++)
		hash[i] = -1;

	for (i = 0; s[i] != '\0'; i++) {
		key = (int)(s[i]);
		val = hash[key];
		hash[key] = i;
		if (val >= k) {
			temp = k;
			k = val + 1;
			if (length > max_length)
				max_length = length;
			length -= (k - temp - 1);
		} else
			length++;
	}
	if (length > max_length)
		max_length = length;

	free(hash);
	return max_length;
}
