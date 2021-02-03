//The script should take as input a pdb file and isolate the ATOM section and print each atom characteristics in a structure in an output file.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*struct pdbatom
{
	char atomnumber[10];
	char *atomtype;
	char *res;
	char *chainid;
	char *resnumber;
	char *x;
	char *y;
	char *z;
	char *alter;
	char *bfactor;
	char *atom;
};*/

int main ()
{
	FILE *pi, *po;
	char filename[100], chn, ch1, ch2, ch3, ch4;
	//filename=(char*)malloc(100);
	int i, m=0;
	printf("Type the filename:\n");
	scanf("%s", &filename);	
	pi=fopen(filename, "r");
	po=fopen("ATOMS.txt", "w");
	char *ch=(char *)malloc(81);
	if (pi!=NULL)
	{
	while(feof(pi)==0)
	{
		ch1=getc(pi);
			if (ch1!='\n')
			{			
				m++;
				if (ch1=='A')
				{	
					ch2=getc(pi);
					m++;
					if (ch2=='T')
					{
						m++;	
						ch3=getc(pi);
						if (ch3=='O')
						{
							m++;	
							ch4=getc(pi);
							if (ch4=='M')
							{
								while (chn!='\n')
								{
									chn=getc(pi);
									strcat(ch, chn);
								}
								printf("%s", ch);
								ch1=ch4;
								continue;
							}
							else
							{
								m--;
								ch1=ch4;
								continue;
							}
						}
						else
						{
							m--;
							ch1=ch3;
							continue;
						}
					}
					else
					{
						m--;
						ch1=ch2;
						continue;
					}
				}
				else
				{
					ch1=getc(pi);
					continue;
				}
			}
			else
			{
				ch1=getc(pi);
				continue;
			}
			ch1=getc(pi);
		}
		}
	else 
	{
		printf("Cannot open file! Please try again!");
	}
	//free(filename);
	free(ch);
	fclose(pi);
	fclose(po);
}
