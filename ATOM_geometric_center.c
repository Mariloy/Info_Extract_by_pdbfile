//The script should take as input a pdb file and isolate the ATOM section and print each atom characteristics in a structure in an output file.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct pdbatom
{
	int atomnumber;
	char atomtype[5];
	char res[4];
	char chainid;
	int resnumber;
	float x;
	float y;
	float z;
	float occup;
	float bfactor;
	char atom;
};

void res_distance (struct pdbatom *as, int size)
{
	int i, j, aa, ab;
	char a[5], b[5], residue[4];
	float x1, x2, y1, y2, z1, z2, distance;
	printf("Type the numbers of the residues that you are aware of their distance. Let one gap between them\n");
	scanf("%d %d", &aa, &ab);
	if (aa<=as[size].resnumber && aa>=as[1].resnumber && ab<=as[size].resnumber && ab>=as[1].resnumber)
	{
	for (i=0;i<size;i++)
	{
		
		if (aa==as[i].resnumber)
		{
			a[0]=as[i].atomtype[0];
			a[1]=as[i].atomtype[1];
			if (a[0]=='C' && a[1]=='A'){
			x1=as[i].x;
			y1=as[i].y;
			z1=as[i].z;
			for (j=0; j<4; j++)
			{
				residue[j]=as[i].res[j];
			}
			printf("The 1st residue is of type %s\n", residue);
			printf("The coordinates of the 1st residue are: %.3f %.3f %.3f\n", x1, y1, z1);
			}
		}
		else if (ab==as[i].resnumber)
		{
			b[0]=as[i].atomtype[0];
			b[1]=as[i].atomtype[1];
			if (b[0]=='C' && b[1]=='A'){
			x2=as[i].x;
			y2=as[i].y;
			z2=as[i].z;
			for (j=0; j<4; j++)
			{
				residue[j]=as[i].res[j];
			}
			printf("The 2nd residue is of type %s\n", residue);
			printf("The coordinates of the 2nd residue are: %.3f %.3f %.3f\n", x2, y2, z2);
			}
		}
	}
	distance=sqrt(pow((x1-x2),2)+pow((y1-y2),2)+pow((z1-z2),2));
	printf("The distance is: %.3f", distance);
	}
	else
	{
		printf("One of the residue number that you have typed does not exist!");
	}
}

int main ()
{
	FILE *pi, *po;
	char chp, chn;
	int l=0, i=0, m=0;
	float x=0, y=0, z=0, xs=0, ys=0, zs=0;
	char *filename=(char *)calloc(10, sizeof(char));
	printf("Type the filename:\n");
	scanf("%s", filename);
	pi=fopen(filename, "r");
	po=fopen("ATOMS.txt", "w");
	char *ch=(char *)calloc(81, sizeof(char));
	if (pi!=NULL)
	{
		while (feof(pi)==0) //or !feof(pFile)
		{
			chp=getc(pi);
			if (chp=='\n')
			{
				chn=getc(pi);
				if (chn=='A')
				{
					chn=getc(pi);
					if (chn=='T')
					{
						chn=getc(pi);
						if (chn=='O')
						{
							chn=getc(pi);
							if (chn=='M')
							{
								m++;
							}
						}
					}
				}
			}
		}
	}
	else 
	{
		printf("Cannot open file.\n"); 
	}
	fclose(pi);
	
	pi=fopen(filename, "r");
	if (pi!=NULL)
	{
		chn=getc(pi);
		while(!feof(pi))
		{
			struct pdbatom line[m];
			if (chn=='\n') 
			{
				chn=getc(pi);
				if (chn=='A')
				{
					chn=getc(pi);
					if (chn=='T')
					{
						chn=getc(pi);
						if (chn=='O')
						{
							chn=getc(pi);
							if (chn=='M')
							{
								fscanf(pi, "%d %s %s %c %d %f %f %f %f %f %c", &line[l].atomnumber, line[l].atomtype, line[l].res, &line[l].chainid, &line[l].resnumber, &line[l].x, &line[l].y, &line[l].z, &line[l].occup, &line[l].bfactor, &line[l].atom);
								x+=line[l].x;
								y+=line[l].y;
								z+=line[l].z;
								fprintf(po, "Atom serial number: %d\nAtom name: %s\nResidue name: %s\nChain identifier: %c\nResidue number: %d\nX orthogonal A coordinate: %.3f\nY orthogonal A coordinate: %.3f\nZ orthogonal A coordinate: %.3f\nOccupancy: %.2f\nTemperature factor: %.2f\nElement symbol: %c\n", line[l].atomnumber, line[l].atomtype, line[l].res, line[l].chainid, line[l].resnumber, line[l].x, line[l].y, line[l].z, line[l].occup, line[l].bfactor, line[l].atom);									
								l++;
							}
						}
					}
				}
				else if (chn=='M')
				{
					chn=getc(pi);
					if (chn=='O')
					{
						chn=getc(pi);
						if (chn=='D')
						{
							chn=getc(pi);
							if (chn=='E')
							{
								chn=getc(pi);
								if (chn=='L')
								{
									i+=1;
									fprintf(po, "MODEL %d\n", i);
								}
							}
						}
					}
				}
				else if (chn=='E')
				{
					chn=getc(pi);
					if (chn=='N')
					{
						chn=getc(pi);
						if (chn=='D')
						{
							chn=getc(pi);
							if (chn==' ')
							{
								xs=x/l;
								ys=y/l;
								zs=z/l;
								fprintf(po, "\nCoordinates of the geometric center: %.3f, %.3f, %.3f", xs, ys, zs);
								res_distance(line, l);
								fprintf(po, "\nEND OF FILE!\n");
							}
						}
					}
				}
			}
			chn=getc(pi);
		}
	}
	else 
	{
		printf("Cannot open file! Please try again!");
	}
	free(filename);
	free(ch);
	fclose(pi);
	fclose(po);
	return(0);
}
