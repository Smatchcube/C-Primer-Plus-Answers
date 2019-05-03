#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char * s_gets(char * st, int n);
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
struct book update_entry(struct book);
void eatline(void);

int main(void)
{
	struct book library[MAXBKS]; 
	int count = 0;
	int index;
	FILE * pbooks;
	int size = sizeof (struct book);
	if ((pbooks = fopen("book.dat", "a+b")) == NULL) {
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}
	
	rewind(pbooks);
	while (count < MAXBKS &&
		fread(&library[count], size, 1, pbooks) == 1) {
		if (count == 0)
			puts("Current contents of book.dat:");
		printf("%s by %s: $%.2f\n",library[count].title, 
				library[count].author, library[count].value);
		printf("Press d to delete this book, c to change "
				"it or enter to keep it: \n");
		switch (getchar()) {
		case 'd':
			eatline();
			break;
		case 'c':
			eatline();
			library[count] = update_entry(library[count]);
		case '\n':
		default:
			++count;
		}
	}
	if (count == MAXBKS) {
		fputs("The book.dat file is full.", stderr);
		exit(2);
	}
	fclose(pbooks);
	if ((pbooks = fopen("book.dat", "w+b")) == NULL) {
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}
	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
			&& library[count].title[0] != '\0') {
		puts("Now enter the author.");
		s_gets(library[count].author, MAXAUTL);
		puts("Now enter the value.");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			puts("Enter the next title.");
	}
	if (count > 0) {
		puts("Here is the list of your books:");
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n",library[index].title,
					library[index].author, library[index].value);
		fwrite(&library[0], size, count, pbooks);
	}
	else
		puts("No books? Too bad.\n");
	puts("Bye.\n");
	fclose(pbooks);
	return 0;
}

char * s_gets(char * st, int n) {
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

struct book update_entry(struct book entry)
{
	char title[MAXTITL];
	char author[MAXAUTL];
	char value[10];
	printf("Title: %s\n"
		"Enter new title or enter to keep unchanged: ",
		entry.title);
	s_gets(title, MAXTITL);
	if (title[0] != '\0')
		strcpy(entry.title,title);
	printf("Author: %s\n"
		"Enter new author or enter to keep unchanged: ",
		entry.author);
	s_gets(author, MAXAUTL);
	if (author[0] != '\0')
		strcpy(entry.author, author);
	printf("Value: %.2f\n"
		"Enter new value or enter to keep unchanged: ",
		entry.value);
	s_gets(value, MAXAUTL);
	if (value[0] != '\0') 
		entry.value = atoi(value);
	return entry;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}
