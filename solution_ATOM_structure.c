//The script should take as input a pdb file and isolate the ATOM section and print each atom characteristics in a structure in an output file.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pdbatom
{
	char at[4];
	int atomnumber;
	char atomtype[5];
	char res[4];
	char chainid;
	int resnumber;
	float x;
	float y;
	float z;
	float alter;
	float bfactor;
	char atom;
};

int main ()
{
	FILE *pi, *po;
	char chn;
	int l=0, i=1;
	float x=0, y=0, z=0, xs=0, ys=0, zs=0;
	char *filename=(char *)calloc(10, sizeof(char));
	printf("Type the filename:\n");
	scanf("%s", filename);
	pi=fopen(filename, "r");
	po=fopen("ATOMS.txt", "w");
	char *ch=(char *)calloc(81, sizeof(char));
	if (pi!=NULL)
	{
		fprintf(po, "MODEL 1\n");
		chn=getc(pi);
	while(!feof(pi))
	{
		struct pdbatom line[10000];
		chn=getc(pi);
		l++;
		if (chn!='\n') 
		{
			//chn=getc(pi);
			//struct pdbatom line[l];
			fscanf(pi, "%s %d %s %s %c %d %f.3 %f.3 %f.3 %f.2 %f.2 %c", line[l].at, &line[l].atomnumber, line[l].atomtype, line[l].res, &line[l].chainid, &line[l].resnumber, &line[l].x, &line[l].y, &line[l].z, &line[l].alter, &line[l].bfactor, &line[l].atom);
		
		if (line[l].at[0]=='A' && line[l].at[1]=='T' && line[l].at[2]=='O' && line[l].at[3]=='M')
		{
			x+=line[l].x;
			y+=line[l].y;
			z+=line[l].z;
			fprintf(po, "Atom number: %d\nAtom type: %s\nResidue: %s\nChain identifier: %c\nResidue number: %d\nx coordinate: %f.3\ny coordinate: %f.3\nz coordinate: %f.3\nPosition possibility: %f.2\nBfactor: %f.2\nAtom: %c\n", line[l].atomnumber, line[l].atomtype, line[l].res, line[l].chainid, line[l].resnumber, line[l].x, line[l].y, line[l].z, line[l].alter, line[l].bfactor, line[l].atom); 
		}
		else if(line[l].at[0]=='E' && line[l].at[1]=='N' && line[l].at[2]=='D' && line[l].at[3]=='M')
		{
			i+=1;
			fprintf(po, "MODEL %d\n", i);
		}
		else if(line[l].at[0]=='E' && line[l].at[1]=='N' && line[l].at[2]=='D' && line[l].at[3]==' ')
		{
			xs=x/l;
			ys=y/l;
			zs=z/l;
			fprintf(po, "The coordinates of the geometric center are the following: %f.3, %f.3, %f.3", xs, ys, zs);
			fprintf(po, "END OF FILE!");
		}
		}
		else
		{
			chn=getc(pi);
		}
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
