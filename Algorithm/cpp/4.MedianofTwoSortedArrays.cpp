/*
 * 4.Median of Two Sorted Arrays
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 *
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 */

#include <stdio.h>

int binarySearch(int A[], int low, int high, int key)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (key == A[mid]) return mid;
		if (key > A[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return low;
}

double findMedianSortedArrayHelper(int A[], int m, int B[], int n, int lowA, int highA, int lowB, int highB)
{
	int mid = lowA + (highA - lowA) / 2;
	int pos = binarySearch(B, lowB, highB, A[mid]);
	int num = mid + pos;

	if (num == (m + n) / 2)
	{
		if ((m + n) % 2 == 1)
		{
			return A[mid];
		}

		int next;

		if (mid > 0 && pos > 0)
		{
			next = A[mid - 1] > B[pos - 1] ? A[mid - 1] : B[pos - 1];
		}
		else if (pos > 0)
		{
			next = B[pos - 1];
		}
		else if (mid > 0)
		{
			next = A[mid - 1];
		}
		return (A[mid] + next) / 2.0;
	}
	if (num < (m + n) / 2)
	{
		lowA = mid + 1;
		lowB = pos;
		if (highA - lowA > highB - lowB)
		{
			return findMedianSortedArrayHelper(A, m, B, n, lowA, highA, lowB, highB);
		}
		return findMedianSortedArrayHelper(B, n, A, m, lowB, highB, lowA, highA);
	}
	if (num > (m + n) / 2)
	{
		highA = mid - 1;
		highB = pos - 1;
		if (highA - lowA > highB - lowB)
		{
			return findMedianSortedArrayHelper(A, m, B, n, lowA, highA, lowB, highB);
		}
		return findMedianSortedArrayHelper(B, n, A, m, lowB, highB, lowA, highA);
	}
}

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
	if (m == 0 & n == 0) return 0.0;
	if (m == 0) return n % 2 == 1 ? B[n / 2] : (B[n / 2 - 1] + B[n / 2]) / 2.0;
	if (n == 0) return m % 2 == 1 ? A[m / 2] : (A[m / 2 - 1] + A[m / 2]) / 2.0;

	if (m > n)
	{
		return findMedianSortedArrayHelper(A,m,B,n,0,m-1,0,n-1);
	}
	return findMedianSortedArrayHelper(B, n, A, m, 0, n - 1, 0, m - 1);
}

int main()
{
	int r1[] = {1,2};
	int r2[] = {3,4};

	int n1 = sizeof(r1) / sizeof(r1[0]);
	int n2 = sizeof(r2) / sizeof(r2[0]);

	printf("Median is 1.5 = %f\n", findMedianSortedArrays(r1, n1, r2, n2));
}
