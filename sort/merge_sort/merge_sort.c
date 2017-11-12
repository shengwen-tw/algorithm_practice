#include <stdio.h>
#include <stdlib.h>

void merge_sort_recursive(int arr[], int sort_tmp[], int start, int end, int len)
{
	if(start >= end) {
		return;
	}

	//divide into half
	int half_len = (end - start) / 2;
	int start1 = start;
	int start2 = start + half_len + 1;
	int end1 = start + half_len;
	int end2 = end;

	//divide and conquer
	merge_sort_recursive(arr, sort_tmp, start1, end1, half_len);
	merge_sort_recursive(arr, sort_tmp, start2, end2, half_len);

	//merge two arrays and sorting
	int i = start;
	while(start1 <= end1 && start2 <= end2) {
		sort_tmp[i++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	}

	while(start1 <= end1) {
		sort_tmp[i++] = arr[start1++];
	}

	while(start2 <= end2) {
		sort_tmp[i++] = arr[start2++];
	}

	//copy back from temp store
	for(i = start; i <= end; i++) {
		arr[i] = sort_tmp[i];
	}

}

void merge_sort(int *arr, int len)
{
	int *sort_tmp = (int *)malloc(sizeof(int) * len);

	merge_sort_recursive(arr, sort_tmp, 0, len - 1, len);

	free(sort_tmp);
}

void print_nums(char *s, int *nums, int _size)
{
	char _s[100] = {0};

	int i;
	for(i = 0; i < _size; i++) {
		sprintf(_s, "%s%d ", _s, nums[i]);
	}
	printf("%s%s\n", s, _s);
}

int main(void)
{
	char s[100] = {0};

	int nums[] = {1, 5, 3, 100, 105, 50, 77, 32, 21, 11};
	int nums_size = sizeof(nums) / sizeof(int);

	/* print before sort */
	print_nums("before sort: ", nums, nums_size);

	merge_sort(nums, nums_size);

	/* print after sort */
	print_nums("after sort: ", nums, nums_size);

        return 0;
}
