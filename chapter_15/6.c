#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

struct font {
	unsigned char font_id     :8;
	unsigned char font_size   :7;
	unsigned char alignement  :2;
	bool          bold        :1;
	bool          italic      :1;
	bool          underline   :1;
};

void print_font(struct font *);
char prompt_menu(void);
void change_font(struct font *);
void change_size(struct font *);
void change_alignment(struct font *);
void toggle_bold(struct font *);
void toggle_italic(struct font *);
void toggle_underline(struct font *);
void eatline(void);

int main(void)
{
	struct font f = {1, 12, 0, 0, 0, 0};
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

void print_font(struct font *f)
{
	char * alignment[3] = {"left", "center", "right"};
	printf(" ID SIZE ALIGNMENT   B   I   U\n"
	       "%3u %4u %6s     %3s %3s %3s\n\n",
	       f->font_id, f->font_size, alignment[f->alignement],
	       f->bold ? "on" : "off", f->italic ? "on" : "off",
	       f->underline ? "on" : "off");
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

void change_font(struct font *f)
{
	unsigned char new_font_id;
	printf("Enter font ID (0-255): ");
	scanf("%hhu", &new_font_id);
	eatline();
	f->font_id = new_font_id;
}

void change_size(struct font *f)
{
	unsigned char new_font_size;
	printf("Enter font size (0-127): ");
	scanf("hhu", &new_font_size);
	eatline();
	f->font_size = new_font_size;
}

void change_alignment(struct font *f)
{
	unsigned char new_alignment;
	printf("Select alignment:\n"
	       "l)left   c)center   r)right\n");
	while (scanf("%c", &new_alignment), isspace(new_alignment))
		continue; //wait for non-space input;
	eatline();
	switch (new_alignment) {
	case 'l':
		f->alignement = 0;
		break;
	case 'c':
		f->alignement = 1;
		break;
	case 'r':
		f->alignement = 2;
		break;
	default:
		puts("Choice invalid, operation canceled");
		break;
	}
}

void toggle_bold(struct font *f)
{
	f->bold ^= 1;
}

void toggle_italic(struct font *f)
{
	f->italic ^= 1;
}

void toggle_underline(struct font *f)
{
	f->underline ^= 1;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}
