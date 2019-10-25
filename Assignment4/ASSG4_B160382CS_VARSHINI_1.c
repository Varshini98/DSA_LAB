#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include <stdbool.h>

void chaining();
void linearProbing();
void quadraticProbing();
void doubleHashing();


bool checkPrime(int x)
{
	int i;
	for(i = 2; i < x; i++)
	{
		if(x % i == 0)
			return false;
	}
	return true;
}

int findPrime(int x)
{
	x--;
	while(x > 2)
	{
		if(checkPrime(x))
			return x;
		x--;
	}
	return x;
}

int main()
{
	char _ch;
	scanf("%c", &_ch);
	if(_ch == 'a')
		linearProbing();
	else if(_ch == 'b')
		quadraticProbing();
		else if(_ch=='c')
			doubleHashing();
	/**	else if(_ch=='d')
			chaining();
			**/
	return 0;
}

void linearProbing()
{
	int m, i, ele;
	scanf("%d", &m);
	int hashTable[m];
	for(i = 0; i < m; i++)
	{
		hashTable[i] = 0;
	}
	char c;
	while(1)
	{
		scanf("%c", &c);
		if(c == 'i')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + i) % m;
				if(hashTable[hashValue] == 0)
				{
					hashTable[hashValue] = ele;
					break;
				}
			}
		}
		else if(c == 's')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + i) % m;
				if(hashTable[hashValue] != 0)
				{
					if(hashTable[hashValue] == ele)
					{
						printf("1\n");
						break;
					}
				}
				else
				{
					printf("-1\n");
					break;
				}
			}
		}
		else if(c == 'd')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + i) % m;
				if(hashTable[hashValue] != 0)
				{
					if(hashTable[hashValue] == ele)
					{
						hashTable[hashValue] = -1;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		else if(c == 'p')
		{
			for(i = 0; i < m; i++)
			{
				if(hashTable[i] > 0)
					printf("%d (%d)\n", i, hashTable[i]);
				else
					printf("%d ()\n", i);
			}
		}
		else if(c == 't')
		{
			return;
		}
	}
}

void quadraticProbing()
{
	int m, i, ele;
	scanf("%d", &m);
	int hashTable[m];
	for(i = 0; i < m; i++)
	{
		hashTable[i] = 0;
	}
	char c;
	while(1)
	{
		scanf("%c", &c);
		if(c == 'i')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + (i * i) % m) % m;
				if(hashTable[hashValue] == 0)
				{
					hashTable[hashValue] = ele;
					break;
				}
			}
		}
		else if(c == 's')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + (i * i) % m) % m;
				if(hashTable[hashValue] != 0)
				{
					if(hashTable[hashValue] == ele)
					{
						printf("1\n");
						break;
					}
				}
				else
				{
					printf("-1\n");
					break;
				}
			}
		}
		else if(c == 'd')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + (i * i) % m) % m;
				if(hashTable[hashValue] != 0)
				{
					if(hashTable[hashValue] == ele)
					{
						hashTable[hashValue] = -1;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		else if(c == 'p')
		{
			for(i = 0; i < m; i++)
			{
				if(hashTable[i] > 0)
					printf("%d (%d)\n", i, hashTable[i]);
				else
					printf("%d ()\n", i);
			}
		}
		else if(c == 't')
		{
			return;
		}
	}
}

void doubleHashing()
{
	int m, i, ele;
	scanf("%d", &m);
	int hashTable[m];
	int r = findPrime(m);
	for(i = 0; i < m; i++)
	{
		hashTable[i] = 0;
	}
	char c;
	while(1)
	{
		scanf("%c", &c);
		if(c == 'i')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + (i * (r - ele % r)) % m) % m;
				if(hashTable[hashValue] == 0)
				{
					hashTable[hashValue] = ele;
					break;
				}
			}
		}
		else if(c == 's')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + (i * (r - ele % r)) % m) % m;
				if(hashTable[hashValue] != 0)
				{
					if(hashTable[hashValue] == ele)
					{
						printf("1\n");
						break;
					}
				}
				else
				{
					printf("-1\n");
					break;
				}
			}
		}
		else if(c == 'd')
		{
			scanf("%d", &ele);
			for(i = 0; i < m; i++)
			{
				int hashValue = (ele % m + (i * (r - ele % r)) % m) % m;
				if(hashTable[hashValue] != 0)
				{
					if(hashTable[hashValue] == ele)
					{
						hashTable[hashValue] = -1;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		else if(c == 'p')
		{
			for(i = 0; i < m; i++)
			{
				if(hashTable[i] > 0)
					printf("%d (%d)\n", i, hashTable[i]);
				else
					printf("%d ()\n", i);
			}
		}
		else if(c == 't')
		{
			return;
		}
	}
}
