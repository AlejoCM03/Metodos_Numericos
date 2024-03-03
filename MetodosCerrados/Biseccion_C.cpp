#include<stdio.h>
#include<math.h>

double funcion(double x);
void biseccion(double xi, double xu, double errorMin, int maxIter);

int main(){
	
	double xi=0.0, xu=0.0, errorMin=0.0;
	int maxIter=0 ;
	
	printf("Dame el limite inferior del intervalo: ");
	scanf("%lf", &xi);
	printf("\n");
	
	printf("Dame el limite superior del intervalo: ");
	scanf("%lf", &xu);
	printf("\n");
	
	printf("Especifica el numero de iteraciones: ");
	scanf("%d", &maxIter);
	printf("\n");
	
	printf("Especifica el error minimo del calculo: ");
	scanf("%lf", &errorMin);
	printf("\n");
	
	biseccion(xi, xu, errorMin, maxIter);
	
	return 0;
}

double funcion(double x){
	//return 2*pow(x,3)+4*pow(x,2)+7*x+3;
	//return exp(-x)-x;
}

void biseccion(double xi, double xu, double errorMin, int maxIter){
	
	double xrAnt = 0.0, xr = 0.0, error = 0.0;
	int i=0;
	
	if(funcion(xi) * funcion(xu) > 0){
		printf("No existe la raiz en ese intervalo\n");
	}
	else{
		do{
			i++;
			xrAnt = xr;
			xr = (xi+xu)/2;
		
			error = fabs(((xr - xrAnt)/xr)*100);
			
			if(funcion(xi) * funcion(xr) < 0){
				xu = xr;
			}
			else if(funcion(xi) * funcion(xr) > 0){
				xi = xr;
			}
			else{
				error = 0;
			}
		
		printf("Valor xi= %lf\nValor xr= %lf\nValor xu= %lf\n", xi,xr,xu);
		
		printf("\n\t\tNumero de iteracion: \n\t\tError = ", i, error);
		
		printf("SE CONCLUYO LA ITERACION %d",i);
		}while(i <= maxIter || error > errorMin);
		
		printf("\n\nValor de la raiz: %.4lf", xr);
	}
}
