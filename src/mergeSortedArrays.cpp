/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int check(char *date1, char *date2){
	int i = 0, d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	while (*(date1 + i) != '-' && *(date2 + i) != '-'){
		d1 = (d1 * 10) + (date1[i] - '0');
		d2 = (d2 * 10) + (date2[i] - '0');
		i++;
	}
	i++;
	while (*(date1 + i) != '-' && *(date2 + i) != '-'){
		m1 = (m1 * 10) + (date1[i] - '0');
		m2 = (m2 * 10) + (date2[i] - '0');
		i++;
	}
	i++;
	while (*(date1 + i) != '\0'&& *(date2 + i) != '\0'){
		y1 = (y1 * 10) + (date1[i] - '0');
		y2 = (y2 * 10) + (date2[i] - '0');
		i++;
	}

	if (y1 == y2 && m1 == m2 && d1 == d2)
		return 0;
	if (y1 > y2){
		return 2;
	}
	if (y1 < y2)
		return 1;
	if (y1 == y2){
		if (m1 > m2)
			return 2;
		else if (m1 < m2)
			return 1;
		else if (m1 == m2){
			if (d1 > d2)
				return 2;
			else if (d1 < d2)
				return 1;
		}

	}
}


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL)
		return NULL;
	if (B == NULL)
		return NULL;
	if (A == NULL && B == NULL)
		return NULL;
	struct transaction *C = NULL;
	int i=0, j=0, n,k=0;
	C = (struct transaction *)malloc(sizeof(struct transaction)*(ALen+BLen));
	if (A != NULL && B != NULL){
		while (i != ALen && j != BLen){
			n = check(A[i].date, B[j].date);
			if (n == 1){
				C[k] = A[i];
				k++;
				i++;
			}
			if (n == 2){
				C[k] = B[j];
				k++;
				j++;
			}
			if (n == 0){
				C[k] = A[i];
				k++;
				i++;
				C[k] = B[j];
				k++;
				j++;
			}
		}
		while (i != ALen)
		{
			C[k] = A[i];
			k++;
			i++;
		}
		while (j != BLen)
		{
			C[k] = B[j];
			k++;
			j++;
		}
		return C;
	}

}