#include <stdio.h>
int main() {
	int arr[5], i;
	for(i=0; i<5;i++){
		printf("%p\n",&arr[i]);
	}
	printf("Address of the array: %p", arr);
	return 0;
}
