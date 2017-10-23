#include <stdio.h>

void bubble_sort(int *nums, int cnt)
{
	int i, j;
	for(i = 0; i < cnt - 1; i++) {
		for(j = cnt - 1; j > 0; j--) {
			if(nums[j] < nums[j - 1]) {
				int tmp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = tmp;
			}
		}
	}
}

int main(void)
{
	char s[1024] = {0};

	/* input size */
	printf("input counts: ");

	int cnt;
	scanf("%d", &cnt);

	int nums[100];

	printf("input numbers: ");

	int i;
	for(i = 0; i < cnt; i++) {
		scanf("%d", &nums[i]);
	}

	bubble_sort(nums, cnt);	

	sprintf(s, "%safter sort: ", s);

	for(i = 0; i < cnt; i++) {
		sprintf(s, "%s%d ", s, nums[i]);
	}

	printf("%s\n", s);

	return 0;
}
