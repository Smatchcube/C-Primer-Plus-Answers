#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE    45

struct film {
	char title[TSIZE];
	int rating;
	struct film * next;
};

void display_movie_list(struct film *);
void display_movie_list_reverse(struct film *);
char * s_gets(char * st, int n);

int main(void)
{
	struct film * head = NULL;
	struct film * prev, * current;
	char input[TSIZE];

	puts("Enter first movie title:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
		current = (struct film *) malloc(sizeof(struct film));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter yoyr rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title (empty line to stop):");
		prev = current;
	}

	if (head == NULL) {
		puts("No data entered");
	} else {
		puts("Here is the movie list:");
		display_movie_list(head);
		puts("Here is the movie list in reverse order");
		display_movie_list_reverse(head);
	}

	current = head;
	while (current != NULL) {
		head = current->next;
		free(current);
		current = head;
	}
	printf("Bye!\n");

	return 0;
}
		

void display_movie_list(struct film * movies)
{
	do {
		printf("Movies: %s  Rating: %d\n",
		       movies->title, movies->rating);
		movies = movies->next;
	} while (movies != NULL);
}

void display_movie_list_reverse(struct film * movies)
{
	if (movies->next != NULL)
		display_movie_list_reverse(movies->next);
	printf("Movies: %s  Rating: %d\n",
	       movies->title, movies->rating);
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
