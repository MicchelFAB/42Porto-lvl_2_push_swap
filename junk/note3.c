#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int arr[9] = {2, 7, 10, 12, 22, -20, 11, 5, 15};
	int i;
	int j;
	
	i = 0;
	while(i < 3)
	{
		j = 0;
		while (j < 3)
		{
			printf("%3d ", arr[i * 3 + j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}