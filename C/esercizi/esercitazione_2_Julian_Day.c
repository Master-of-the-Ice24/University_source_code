/*

Il programma prende come input 3 interi per 2 volte, che indicano 2 date, alla fine restituisce la differenza tra la prima 
data e laseconda in formato Giuliano

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


int main() {
    int date1, date2, difference;

    date1 = getJulianDay();
    date2 = getJulianDay();
    difference = date1 - date2;

	printf("\nThe Julian difference is %d\n\n", difference);

	return 0;	
}
