char* convert(char* s, int num_row) {
	int length = strlen(s);
	char *retval = (char *)malloc(length + 1);
	int i, r, mem, mem1, mem2;
	int num_per_trk;

	for (i = 0; i < length + 1; i++)
		retval[i] = 0;

	num_per_trk = (num_row > 2)? (2 * num_row - 2) : num_row;
	
	mem = 0;
	for (r = 0; r < num_row; r++) {
		if (r == 0 || r == num_row - 1) {
			for (i = 0; i * num_per_trk + r < length; i++)
				retval[mem + i] = s[i * num_per_trk + r];
			mem += i;
			continue;
		}
		for (i = 0; i * num_per_trk + r < length; i++)
			retval[mem + i * 2] = s[i * num_per_trk + r];
		mem1 = mem + i * 2;
		for (i = 0; i * num_per_trk + num_per_trk - r < length; i++)
			retval[mem + i * 2 + 1] = s[i * num_per_trk + num_per_trk - r];
		mem2 = mem + i * 2 + 1;
		mem = (mem1 < mem2)? mem1 : mem2;
	}

	return retval;
}
