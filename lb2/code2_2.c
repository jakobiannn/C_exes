#include <stdio.h>

void main() {
	int day, month, year;
	printf("%s\n", "Write your date");

	printf("%s", "Day: ");
	scanf("%d", &day);

	printf("%s", "Number of month: ");
	scanf("%d", &month);

	printf("%s", "Year: ");
	scanf("%d", &year);

	switch (month) {
		case 1: printf("%s\n", "This month have 31 day");
		break;
		case 2: printf("%s\n", "This month have 28 day's");
		break;
		case 3: printf("%s\n", "This month have 31 day");
		break;
		case 4: printf("%s\n", "This month have 30 day");
		break;
		case 5: printf("%s\n", "This month have 31 day");
		break;
		case 6: printf("%s\n", "This month have 30 day");
		break;
		case 7: printf("%s\n", "This month have 31 day");
		break;
		case 8: printf("%s\n", "This month have 31 day");
		break;
		case 9: printf("%s\n", "This month have 30 day");
		break;
		case 10: printf("%s\n", "This month have 31 day");
		break;
		case 11: printf("%s\n", "This month have 30 day");
		break;
		case 12: printf("%s\n", "This month have 31 day");
		break;
	}
}
