#include <stdio.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	int a, b, c, max1, max2;
	int *n1, *n2;
	int sum, odd;

	sum = (nums1Size + nums2Size - 1) / 2;
	odd = (nums1Size + nums2Size) % 2;
	a = 0;
	if (nums1Size >= nums2Size) {
		n1 = nums1;
		n2 = nums2;
		max1 = nums1Size - 1;
		max2 = nums2Size - 1;
		b = nums2Size - 1;
	} else {
		n1 = nums2;
		n2 = nums1;
		max1 = nums2Size - 1;
		max2 = nums1Size - 1;
		b = nums1Size - 1;
	}

	if (b == -1) {
		if (odd)
			return n1[sum];
		else
			return (n1[sum] + n1[sum + 1]) / 2.0;
	}

	if (n2[0] >= n1[sum]) {
		if (odd)
			return n1[sum];
		else if (sum == max1)
			return (n1[sum] + n2[0]) / 2.0;
		else
			return (n1[sum] + min(n2[0], n1[sum + 1])) / 2.0;
	}

	if (n2[b] <= n1[sum - b] && sum == b) {
		if (odd)
			return n1[0];
		else
			return (n2[b] + n1[0]) / 2.0;
	}

	if (n2[b] <= n1[sum - b - 1]) {
		if (odd)
			return n1[sum - b - 1];
		else
			return (n1[sum - b - 1] + n1[sum - b]) / 2.0;
	}

	if (n2[b] >= n1[sum - b - 1] && n2[b] <= n1[sum - b]) {
		if (odd)
			return n2[b];
		else
			return (n2[b] + n1[sum - b]) / 2.0;
	}

	while (42) {
		c = (a + b) / 2;
		if ((n2[c] >= n1[sum - c - 1]) && (n2[c] <= n1[sum - c])) {
			if (odd)
				return n2[c];
			else if (c != max2)
				return (n2[c] + min(n2[c + 1], n1[sum - c])) / 2.0;
			else
				return (n2[c] + n1[sum - c]) / 2.0;
		}
		else if (n2[c] > n1[sum - c])
			b = c;
		else if (a == c) {
			if (odd)
				return n1[sum - c - 1];
			else
				return (n1[sum - c - 1] + min(n1[sum - c], n2[c + 1])) / 2.0;
		} else
			a = c;
	}
}


int main()
{
	int a[] = {2};
	int b[] = {1, 3, 4};
	printf("%f\n", findMedianSortedArrays(a, 1, b, 3));
}
