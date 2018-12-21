#include <stdio.h>

const int DUNBAR_NUMBER = 150;

int main(void)
{
	int week = 0;
	int friend_count = 5;
	
	printf(" week | friends\n"
	       "------+---------\n");
	while (friend_count <= DUNBAR_NUMBER) {
		friend_count -= ++week;
		friend_count *= 2;
		printf("%5d |%8d\n", week, friend_count);
	}
	return 0;
}
