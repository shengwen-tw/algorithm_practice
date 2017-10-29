#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void max_heapify(int *nums, int start, int end)
{
	int father = start;
	int child = 2 * father + 1;

	if(child <= end) {
		//pick the larger child
		if((child + 1 <= end) && (nums[child] < nums[child + 1])) {
			child++;
		}

		//swap if child is larger than father
		if(nums[child] > nums[father]) {
			swap(&nums[father], &nums[child]);
			max_heapify(nums, child, end); //continue comparing with the grandchild node
		}
	}
}

void heap_sort(int *nums, int _size)
{
	int last = _size - 1;

	//build max heap
	int i;
	for(i = (last - 1) / 2; i >= 0; i--) { //from last root node to top root node
		max_heapify(nums, i, _size - 1);
	}

	/* sort by:
	 * (first) swap the first node and the last node
	 * (second) heapifing the array from first node to last minus 1 node
	 */
	for(i = last; i > 0; i--) {
		swap(&nums[0], &nums[i]);
		max_heapify(nums, 0, i - 1);
	}
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

	heap_sort(nums, nums_size);

	/* print after sort */
	print_nums("after sort: ", nums, nums_size);

	return 0;
}
