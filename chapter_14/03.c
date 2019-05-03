#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

char * s_gets(char * st, int n);
int compare_title(struct book, struct book);
int compare_price(struct book, struct book);
void sort_books(struct book * [], int nb_books, int (* cmp)(struct book, struct book));



int main(void)
{
	struct book library[MAXBKS]; /* array of book structures */
	int count = 0;
	int index;
	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
	       && library[count].title[0] != '\0') {
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}
	struct book * ptr_books[count]; // array to book structures for easy sorting
	for (int i = 0; i < count; ++i)
		ptr_books[i] = library + i;
	if (count > 0) {
		printf("Here is the list of your books in order entered:\n");
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", (*ptr_books[index]).title,
			       (*ptr_books[index]).author, (*ptr_books[index]).value);
		printf("Here is the list of your books alphabetized:\n");
		sort_books(ptr_books, count, compare_title);
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", (*ptr_books[index]).title,
			       (*ptr_books[index]).author, (*ptr_books[index]).value);
		printf("Here is the list of your books in increasing price:\n");
		sort_books(ptr_books, count, compare_price);
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", (*ptr_books[index]).title,
			       (*ptr_books[index]).author, (*ptr_books[index]).value);
	} else
		printf("No books? Too bad.\n");
	return 0;
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
		else {
			while (getchar() != '\n')
				continue;
		}
	}
	return ret_val;
}

int compare_title(struct book b1, struct book b2)
{
	return strcmp(b1.title, b2.title);
}

int compare_price(struct book b1, struct book b2)
{
	return b1.value - b2.value;
}

void sort_books(struct book * library[], int nb_books, int (* cmp)(struct book, struct book))
{
	struct book * temp;
	int top, seek;

	for (top = 0; top < nb_books-1; ++top) {
		for (seek = top + 1; seek < nb_books; ++seek) {
			if (cmp(*library[top], *library[seek]) > 0) {
				temp = library[top];
				library[top] = library[seek];
				library[seek] = temp;
			}
		}
	}
}
