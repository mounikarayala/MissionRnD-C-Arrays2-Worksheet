/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int length(char *date){
	int i = 0;
	while (date[i] != '\0'){
		i++;
	}
	return i;
}

int checkGreater(char *date1, char *date2){
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
	if (y1 > y2){
		return 2;
	}
	else if (y1 < y2)
		return 1;
	else if (y1 == y2){
		if (m1 > m2)
			return 2;
		else if (m1 < m2)
			return 1;
		else if (m1 == m2){
			if (d1 > d2)
				return 2;
			else if (d1 < d2)
				return 1;
			else
				return 0;
		}

	}
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (len < 0)
		return -1;
	int l = length(date);
	if (l != 10)
		return -1;
	int i, n, count = 0;
	for (i = 0; i < len; i++){
		n = checkGreater(date, Arr[i].date);
		if (n == 1){
			count++;
		}
	}
	return count;
}
