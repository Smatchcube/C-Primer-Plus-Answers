#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define BOLD 4
#define ITALIC 2
#define UNDERLINE 1
#define ID 0xff000
#define IDSHIFT 12
#define SIZE 0xfe0
#define SIZESHIFT 5
#define ALIGNMENT 0x18
#define ALIGNMENTSHIFT 3

typedef unsigned long font;

void print_font(font *);
char prompt_menu(void);
void change_font(font *);
void change_size(font *);
void change_alignment(font *);
void toggle_bold(font *);
void toggle_italic(font *);
void toggle_underline(font *);
void eatline(void);

int main(void)
{
	font f = 0x1180;
	bool want_to_quit = false;
	while (!want_to_quit) {
		print_font(&f);
		switch (prompt_menu()) {
		case 'f':
			change_font(&f);
			break;
		case 's':
			change_size(&f);
			break;
		case 'a':
			change_alignment(&f);
			break;
		case 'b':
			toggle_bold(&f);
			break;
		case 'i':
			toggle_italic(&f);
			break;
		case 'u':
			toggle_underline(&f);
			break;
		case 'q':
			want_to_quit = true;
			break;
		default:
			puts("Action invalid, try again.");
		}
	}
	puts("Bye!");
	return 0;
}

void print_font(font *f)
{
	char * alignment[3] = {"left", "center", "right"};
	printf(" ID SIZE ALIGNMENT   B   I   U\n"
	       "%3u %4u %6s     %3s %3s %3s\n\n",
	       (*f & ID) >> IDSHIFT, (*f & SIZE) >> SIZESHIFT,
	       alignment[(*f & ALIGNMENT) >> ALIGNMENTSHIFT],
	       *f & BOLD ? "on" : "off", *f & ITALIC ? "on" : "off",
	       *f & UNDERLINE ? "on" : "off");
}

char prompt_menu(void)
{
	char choice;
	printf("f)change font    s)change size    a)change alignment\n"
	       "b)toggle bold    i)toggle italic  u)toggle underline\n"
	       "q)quit\n");
	while (scanf("%c", &choice), isspace(choice))
		continue;  //wait for non-space input
	eatline();
	return choice;
}

void change_font(font *f)
{
	unsigned char new_font_id;
	printf("Enter font ID (0-255): ");
	scanf("%hhu", &new_font_id);
	eatline();
	*f &= ~ID;
	*f |= new_font_id << IDSHIFT;
}

void change_size(font *f)
{
	unsigned char new_font_size;
	printf("Enter font size (0-127): ");
	scanf("%hhu", &new_font_size);
	eatline();
	*f &= ~SIZE;
	*f |= new_font_size << SIZESHIFT;
}

void change_alignment(font *f)
{
	unsigned char new_alignment;
	printf("Select alignment:\n"
	       "l)left   c)center   r)right\n");
	while (scanf("%c", &new_alignment), isspace(new_alignment))
		continue; //wait for non-space input;
	eatline();
	*f &= ~ALIGNMENT;
	switch (new_alignment) {
	case 'l':
		break; //already set to 0
	case 'c':
		*f |= 1 << ALIGNMENTSHIFT;
		break;
	case 'r':
		*f |= 2 << ALIGNMENTSHIFT;
		break;
	default:
		puts("Choice invalid, operation canceled");
		break;
	}
}

void toggle_bold(font *f)
{
	*f ^= BOLD;
}

void toggle_italic(font *f)
{
	*f ^= ITALIC;
}

void toggle_underline(font *f)
{
	*f ^= UNDERLINE;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}
