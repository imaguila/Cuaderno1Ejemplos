/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
  
 
 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

void leer_numero(double *x);
void leer_sumandos(int *n);
double calcular_suma(double x,int n);
void escrbir_resultado(double suma);
FILE *f;

int main(){
	char c;
	double x,suma;
	int n;

	do{ 	clrscr();
			printf("SUMA SERIE x-x**2/2+x**3/3-x**4/4...\n");
			printf("====================================\n\n");
			leer_numero(&x);
			leer_sumandos(&n);
			suma=calcular_suma(x,n);
			escrbir_resultado(suma);
				f=fopen("zz.dat","a");
				fprintf(f,"x=%.2f   n=%d    S(x)=%.15f\n",x,n,suma);
            fclose(f);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}

void leer_numero(double *x){
	do{	printf("Introduzca valor de x (-1..+1): ");
			scanf(" %lf", x);
	}while((*x<=-1)||(*x>=1));
}

void leer_sumandos(int *n){
	do{	printf("\nIntroduzca nº de sumandos: ");
			scanf(" %d",n);
	}while(*n<=0);
}

double calcular_suma(double x,int n){
	double suma,p,term;
	int i;

	suma=0;
	p=x;
	i=1;
	term=p/i;
	while(i<=n){
		suma+=term;
		p*=(-x);
		++i;
		term=p/i;
	}
	return(suma);
}

void escrbir_resultado(double suma){
	printf("\nSuma= %.15f\n", suma);
}
