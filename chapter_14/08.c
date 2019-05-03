#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXLASTNAME 30
#define MAXFIRSTNAME 30
#define CAPACITY 12

struct seat {
	int number;
	bool is_assigned;
	char last_name[MAXLASTNAME];
	char first_name[MAXFIRSTNAME];
};

char prompt_menu(void);
void show_nb_empty(struct seat [CAPACITY]);
void show_list_empty(struct seat [CAPACITY]);
void show_alphabetical(struct seat [CAPACITY]);
void assign_seat(struct seat *);
void delete_assignment(struct seat *);
void print_seat(struct seat);
void eatline(void);

int main(void)
{
	FILE * fp;
	struct seat plane[12] = {};
	struct seat tmp_seat;
	bool want_to_quit = false;
	if ((fp = fopen("seats.dat", "a+b")) == NULL) {
		fputs("Can't open seats.dat for read\n", stderr);
		exit(EXIT_FAILURE);
	}
	while (fread(&tmp_seat, sizeof(struct seat), 1, fp) == 1)
		plane[tmp_seat.number - 1] = tmp_seat;
	while (!want_to_quit) {
		switch (prompt_menu()) {
		case 'a':
			show_nb_empty(plane);
			break;
		case 'b':
			show_list_empty(plane);
			break;
		case 'c':
			show_alphabetical(plane);
			break;
		case 'd':
			assign_seat(plane);
			break;
		case 'e':
			delete_assignment(plane);
			break;
		case 'f':
			fclose(fp);
			if ((fp = fopen("seats.dat", "w+b")) == NULL) {
				fputs("Can't open seats.dat for write\n", stderr);
				exit(EXIT_FAILURE);
			}	
			for (int i = 0; i < CAPACITY; ++i) {
				if (plane[i].is_assigned)
					fwrite(plane + i, sizeof(struct seat), 1, fp);
			}
			fclose(fp);
			want_to_quit = true;
			break;
		default:
			puts("Invalid input, try again!");
		}
	}	
	return 0;
}

char prompt_menu(void)
{
	char ch = ' ';
	printf("To choose a function, enter its letter label:\n"
	       "a) Show number of empty seats\n"
	       "b) Show list of empty seats\n"
	       "c) Show alphabetical list of seats\n"
	       "d) Asssign a customer to a seat assignment\n"
	       "e) Delete a seat assignment\n"
	       "f) Quit\n");
	while (isspace(ch = getchar()))
		continue; // wait for non space input
	while (getchar() != '\n')
		continue; // get rid of rest of line
	return ch;
}

void show_nb_empty(struct seat seat[CAPACITY])
{
	int empty_count = 0;
	for (int i = 0; i < CAPACITY; ++i) {
		if (!seat[i].is_assigned)
			++empty_count;
	}
	printf("There are %d empty seats\n", empty_count);
}
	
void show_list_empty(struct seat seat[CAPACITY])
{
	printf("These seats are empty: ");
	for (int i = 0; i < CAPACITY; ++i) {
		if (!seat[i].is_assigned)
			printf("%d, ", i + 1);
	}
	printf("\b\b \n");
}

void show_alphabetical(struct seat seat[CAPACITY])
{
	struct seat * tmp;
	struct seat * pseats[CAPACITY];
	for (int i = 0; i < CAPACITY; ++i)
		pseats[i] = seat + i;
	for (int i = 0; i < CAPACITY; ++i) { // slow sorting
		for (int j = i; j < CAPACITY; ++j) {
			if (strcmp(pseats[i]->last_name, pseats[j]->last_name) > 0) {
				tmp = pseats[i];
				pseats[i] = pseats[j];
				pseats[j] = tmp;
			}
		}
	}
	for (int i = 0; i < CAPACITY; ++i) {
		if (pseats[i]->is_assigned)
			print_seat(*pseats[i]);
	}
}

void assign_seat(struct seat * seat)
{
	int seat_number;
	printf("Enter the seat number to assign, negative number to abort: ");
	scanf("%d", &seat_number);
	if (seat_number <= 0)
		return;
	eatline();
	printf("Enter the last name of this seat holder, [ENTER] to abort: ");
	scanf("%s",(seat + seat_number - 1)->last_name);
	if ((seat + seat_number - 1)->last_name[0] == '\n')
		return;
	printf("Enter the first name of this seat holder, [ENTER] to abort: ");
	scanf("%s",(seat + seat_number - 1)->first_name);
	if ((seat + seat_number - 1)->first_name[0] == '\n')
		return;
	seat[seat_number-1].is_assigned = true;
	seat[seat_number-1].number = seat_number;
}

void delete_assignment(struct seat * seat)
{
	int seat_number;
	printf("Enter a seat number to delete, negative value to abort\n");
	scanf("%d", &seat_number);
	eatline();
	if (seat_number > 0)
		seat[seat_number-1].is_assigned = false;
}

void print_seat(struct seat seat)
{
	printf("Seat %d: %s %s\n",
	       seat.number, seat.last_name, seat.first_name);
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}
