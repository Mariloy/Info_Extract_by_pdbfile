#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int bases(char *, char, int);

int main ()
{
	printf("This is a program that prints in an output file, named repeats.txt the length of the sequence and the number and position of bases' repeats. The input is a file with the sequence in fasta format.");
	FILE *pFile;
	int m=0;
	int a=0,t=0,c=0,g=0, b=0, u=0, d=0, h=0;
	char ch;
	char filename[100];
	printf("\nEnter filename sized up to 100 characters with the fasta formatted sequence:\n");\
	scanf("%s", filename);
	pFile=fopen(filename,"r");
	FILE *prepeats;
	prepeats=fopen("repeats.txt","w");
	if (pFile!=NULL)
	{
		ch=getc(pFile);
		while (ch!='\n')
		{
			ch=getc(pFile);
		}
		ch=getc(pFile);
		while (feof(pFile)==0) 
		{			
			ch=getc(pFile);
		if (ch!='\n')
		{			
			m++;
			while (ch=='A')
			{
				a+=1;
				if (a>=3)
				{
					fprintf(prepeats, "Position %d: %d repeats of A\n", m, a);
					m+=a;
					a=0;
					break;
					}
				
				else
				{
					a=0;
					break;
				}
			}

			while (ch=='T')
			{
				t+=1;
				if (t>=3)
		{
			fprintf(prepeats, "Position %d: %d repeats of T\n", m, t);
			m+=t;
			t=0;
			break;
		}
		
		else if (t<3)
		{
			t=0;
			break;
		}
		}

			while (ch=='C')
		{
			c+=1;
	
		if (c>=3)
		{
			fprintf(prepeats, "Position %d: %d repeats of C\n", m, c);
			m+=c;
			c=0;
			break;
		}
		
		else if (c<3)
		{
			c=0;
			break;
		}
		}

			while (ch=='G')
		{
			g+=1;
		
		if (g>=3)
		{
			fprintf(prepeats, "Position %d: %d repeats of G\n", m, g);
			m+=g;
			g=0;
			break;
		}
		else if (g<3)
		{
			g=0;
			break;
		}
		}
			continue;
		}	
	else
		{
			continue;
		}
		
}
fprintf(prepeats, "\nSequence length:%d\n", m);
}
	else 
	{
		printf("Cannot open file.\n"); 
	}
	fclose(pFile);
	fclose(prepeats);
}

