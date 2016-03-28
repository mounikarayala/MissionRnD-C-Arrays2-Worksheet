/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int checkEqual(char *date1, char *date2){
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
	if ((y1 == y2) && (m1 == m2) && (d1 == d2))
		return 0;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	if (A == B)
		return A;
	if (ALen < 0 || BLen < 0)
		return NULL;
	int i, j, n, pos,k=0;
	struct transaction *C = NULL;
	for (i = 0; i < ALen; i++){
		for (j = 0; j < BLen; j++){
			n = checkEqual(A[i].date, B[j].date);
			if (n == 0){
				C = (struct transaction *)calloc(1,sizeof(struct transaction));
				C[k] = A[i];
				k++;
			}
		}
	}
	return C;
}