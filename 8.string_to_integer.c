int myAtoi(char *str) {
	int retval = 0;
	int pos = 1;
	int temp= 0;
	char *c;

	for (c = str; *c != '\0'; c++) {
		if (*c == '\n' || *c == '\r' || *c == '\t' || *c == ' ')
			continue;
		if (*c == '-') {
			pos = -1;
			c++;
			break;
		}
		if (*c == '+') {
			c++;
			break;
		}
		if (*c >= '0' && *c <= '9')
			break;
		return 0;
	}

	for (; *c != '\0'; c++) {
		if (*c >= '0' && *c <= '9') {
			temp = *c - '0';
			if (pos > 0 && (retval > (INT_MAX - temp) / 10.0))
				return INT_MAX;
			if (pos < 0 && (- retval < (INT_MIN + temp) / 10.0))
				return INT_MIN;
			retval = retval * 10 + temp;
			continue;
		}
		return retval * pos;
	}

	return retval * pos;
}
