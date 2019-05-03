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
	int flight;
};

char prompt_menu(void);
int promp_flight(void);
void show_nb_empty(struct seat [CAPACITY], int flight);
void show_list_empty(struct seat [CAPACITY], int flight);
void show_alphabetical(struct seat [CAPACITY], int flight);
void assign_seat(struct seat *, int flight);
void delete_assignment(struct seat *, int flight);
void print_seat(struct seat);
void eatline(void);

char * flight_names[4] = {"102", "311", "444", "519"};

int main(void)
{
	FILE * fp;
	int flight;
	struct seat plane[4][12] = {};
	struct seat tmp_seat;
	bool want_to_quit = false;
	if ((fp = fopen("seats.dat", "a+b")) == NULL) {
		fputs("Can't open seats.dat for read\n", stderr);
		exit(EXIT_FAILURE);
	}
	while (fread(&tmp_seat, sizeof(struct seat), 1, fp) == 1)
		plane[tmp_seat.flight-1][tmp_seat.number - 1] = tmp_seat;
	while (!want_to_quit) {
		switch(flight = promp_flight()) {
		case 1:
		case 2:
		case 3:
		case 4:
			break;
		case 0:
			fclose(fp);
			if ((fp = fopen("seats.dat", "w+b")) == NULL) {
				fputs("Can't open seats.dat for write\n", stderr);
				exit(EXIT_FAILURE);
			}
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < CAPACITY; ++j) {
					if (plane[i][j].is_assigned) {
						plane[i][j].flight = i + 1;
						fwrite(plane[i] + j, sizeof(struct seat), 1, fp);
					}
				}
			}
			fclose(fp);
			want_to_quit = true;
			break;	
		}
		if (!want_to_quit) {
			switch (prompt_menu()) {
			case 'a':
				show_nb_empty(plane[flight-1], flight-1);
				break;
			case 'b':
				show_list_empty(plane[flight-1], flight-1);
				break;
			case 'c':
				show_alphabetical(plane[flight-1], flight-1);
				break;
			case 'd':
				assign_seat(plane[flight-1], flight-1);
				break;
			case 'e':
				delete_assignment(plane[flight-1], flight-1);
				break;
			case 'f':
				break;
			default:
				puts("Invalid input, try again!");
			}
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
	       "f) Choose another flight\n");
	while (isspace(ch = getchar()))
		continue; // wait for non space input
	while (getchar() != '\n')
		continue; // get rid of rest of line
	return ch;
}

int promp_flight(void)
{
	int flight_number;
	printf("Choose a flight:\n"
	       "1) %s\n"
	       "2) %s\n"
	       "3) %s\n"
	       "4) %s\n"
	       "0) quit\n",
	       flight_names[0], flight_names[1],
	       flight_names[2], flight_names[3]);
	scanf("%d", &flight_number);
	eatline();
	return flight_number;
}

void show_nb_empty(struct seat seat[CAPACITY], int flight)
{
	int empty_count = 0;
	for (int i = 0; i < CAPACITY; ++i) {
		if (!seat[i].is_assigned)
			++empty_count;
	}
	printf("There are %d empty seats in flight %s.\n",
	       empty_count, flight_names[flight]);
}
	
void show_list_empty(struct seat seat[CAPACITY], int flight)
{
	printf("These seats are empty in flight: ", flight_names[flight]);
	for (int i = 0; i < CAPACITY; ++i) {
		if (!seat[i].is_assigned)
			printf("%d, ", i + 1);
	}
	printf("\b\b \n");
}

void show_alphabetical(struct seat seat[CAPACITY], int flight)
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
	printf("Seats occupied in flight %s:\n", flight_names[flight]);
	for (int i = 0; i < CAPACITY; ++i) {
		if (pseats[i]->is_assigned)
			print_seat(*pseats[i]);
	}
}

void assign_seat(struct seat * seat, int flight)
{
	int seat_number;
	printf("Current flight: %s\n", flight_names[flight]);
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

void delete_assignment(struct seat * seat, int flight)
{
	int seat_number;
	printf("Enter a seat number to delete in flight %s, negative value to abort\n",
		flight_names[flight]);
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
