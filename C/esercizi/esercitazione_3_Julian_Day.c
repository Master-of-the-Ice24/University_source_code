/*

Il programma prende come input 3 interi, che indicano una data, alla fine restituisce il nome
del giorno della settimana della data

*/

#include <stdio.h>

//D day, M, month, Y year
int getJulianDay() {
	int D, M, Y, N0, N1, N2, N3, JulianDay;

	printf("Enter Day, Month, Year: \n");
	scanf("%d%d%d", &D, &M, &Y);

	N0 = (M-14)/12;
	N1 = (1461*(Y+4800+N0))/4;
	N2 = (367*(M-2-12*N0))/12;
	N3 = (3*(Y+4900+N0))/400;

	JulianDay = N1 + N2 - N3 + D - 32075;

	return JulianDay;	
}

char *getDayName(int JulianDate) {
    switch (JulianDate % 7) {
        case 0:
            return "Monday";
        case 1:
            return "Tuesday";
        case 2:
            return "Wednesday";
        case 3:
            return "Thursday";
        case 4:
            return "Friday";
        case 5:
            return "Saturday";
        default:
            return "Sunday";
    }
}


int main() {
    int date = getJulianDay();
    char *name_of_the_day = getDayName(date);

	printf("The name of the day is: %s", name_of_the_day);

	return 0;	
}
