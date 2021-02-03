#include <stdio.h>

int main()
{
	FILE *pFile;
	char t;
	int i=1, m=0;
	char filename[100];
	printf("Enter filename sized up to 100 characters:\n");\
	scanf("%s", filename);
	pFile=fopen(filename,"r");
	if (pFile!=NULL)
	{
		while (feof(pFile)==0) //or !feof(pFile)
		{
			m++;
			t=getc(pFile);
			if (t=='\n')
			{
				i++;
			}
			else 
			{
				continue;
			}
			
		}
		printf("The lines of the file are: %d and the characters are: %d", i, m);
	}
	else 
	{
		printf("Cannot open file.\n"); 
	}
	fclose(pFile);
}
