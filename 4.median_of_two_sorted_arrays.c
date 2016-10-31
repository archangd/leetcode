int min(int a, int b)
{
	return a < b ? a : b;
}

double findOne(int *A, int m, int *B, int n, int k)
{
	int mo, no;

	if (m < n)
		return findOne(B, n, A, m, k);
	if (n == 0)
		return A[k - 1];
	if (k == 1)
		return min(A[0], B[0]);
	
	no = (k / 2 < n)? (k / 2) : n;
	mo = k - no;
	
	if (A[mo - 1] == B[no - 1])
		return A[mo - 1];
	else if (A[mo - 1] > B[no - 1])
		return findOne(A, m, B + no, n - no, k - no);
	else // (A[mo - 1] < B[no - 1])
		return findOne(A + mo, m - mo, B, n, k - mo);
}

double findTwo(int *A, int m, int *B, int n, int k)
{
	int mo, no;

	if (m < n)
		return findTwo(B, n, A, m, k);
	if (n == 0)
		return (A[k - 1] + A[k]) / 2.0;
	if (k == 1) {
		if ((A[0] < B[0]) && m > 1)
			return (A[0] + min(B[0], A[1])) / 2.0;
		else if (m == 1 || n == 1)
			return (B[0] + A[0]) / 2.0;
		else
			return (B[0] + min(A[0], B[1])) / 2.0;
	}
	
	no = (k / 2 < n)? (k / 2) : n;
	mo = k - no;
	
	if (A[mo - 1] == B[no - 1]) {
		if (n > no)
			return (A[mo - 1] + min(A[mo], B[no])) / 2.0;
		else
			return (A[mo - 1] + A[mo]) / 2.0;
	}
	else if (A[mo - 1] > B[no - 1])
		return findTwo(A, m, B + no, n - no, k - no);
	else // (A[mo - 1] < B[no - 1])
		return findTwo(A + mo, m - mo, B, n, k - mo);
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	int sum = nums1Size + nums2Size;
	if (sum % 2)
		return findOne(nums1, nums1Size, nums2, nums2Size, (sum + 1) / 2);
	else
		return findTwo(nums1, nums1Size, nums2, nums2Size, sum / 2);
}
