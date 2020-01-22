#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int lettura(float*x, int n) {
	int i;
	for (i=0; i<n; i++) {
		scanf ("%f", &x[i]);
	}
	return 0;
}

float media(float* x, int n) {
	int i;
	float m, sum=0;
	for (i=0; i<n; i++) {
		sum+=x[i];
	}
	m=sum/n;
	return m;
}
		
float deviazione(float* x, int n, float m) {
	int i;
	float sum, sigmas;
	sum=0;
	for (i=0; i<n; i++) {sum += pow((x[i]-m), 2);}
	sigmas=sqrt(sum/(n-1));
	return sigmas;
}

float semidispersione(float* x, int n) {
	int i;
	float max=-123456789,min=123456789,semid;
	for (i=0; i<n; i++) {
		if (max<x[i]) max=x[i];
		if (min>x[i]) min=x[i];
	}
    semid=(max-min)/2;
	return semid;
}

int main() {
	int i,b;
	int size;
	float sum=0,sigma,m,sigmam,semid;
	ritorna:printf("WELCOME TO DEVY: the multi-tool for physic experiment\n########################\n\n");
	printf("Please, insert the number of values to average and deviate\n");
	scanf ("%d", &size);                                                    //read vector's dimension
	float *a= (float*) malloc(size* sizeof(float));                         //dinamic vector allocation
	printf("Insert the values:\n");
	lettura(a,size);                    //values reading               	   
	m=media(a, size);                   //average of values
	sigma=deviazione(a, size, m);       //standard relative deviation 
	sigmam=sigma/sqrt(size);            //standard average deviation
	semid=semidispersione(a, size);     //maximum semi-dispersion
	printf("The average of %d entered values is:\n", size);                   //results printing
	printf("%f\n", m);
	printf("The standard relative deviation is:\n");
	printf("%f\n", sigma);
	printf("The standard average deviation is:\n");
	printf("%f\n", sigmam);
	printf("The maximum semi-dispersion is:\n");
	printf ("%f", semid);
	printf("\n\n");
	printf("If you would to repeate the operation insert 1, otherwise insert 0\n");
	int r;
	scanf ("%d", &r);
	if (r==1) goto ritorna;
	return 0;
}
