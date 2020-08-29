#include <stdio.h>
#include <math.h>


const double Precision = 1e-6;


int SolveSquare (double a, double b, double c, 
				 double* x1, double* x2);



int main() 
{
	double a = 0, b = 0 , c = 0;
	printf("Vvedite koefficienti kvadratnogo uravneniya:\n");
	
	printf("Koefficient pri vtoroi stepeni x:\na = ");
	scanf("%lg", &a);
	
	printf("Koefficient pri pervoi stepeni x:\nb = ");
	scanf("%lg", &b);
	
	printf("Svobodnij koefficient: \nc = ");
	scanf("%lg", &c);
	
	
	printf("------------------------------------------------------------\n");
	double x1 = 0, x2 = 0;
	int nRoots = 0;
	nRoots = SolveSquare(a, b, c, &x1, &x2);
	if (nRoots == -1) 
	{
		printf("Uravnenie ne kvadratnoe, no vot koren:\n");
		printf("x = %.3lg\n", x1);
	}
	else if (nRoots == 0) 
	{
		printf("Uravnenie ne imeet deistvitelnih reshenij");
	}
	else if (nRoots == 1)
	{
		printf("x = %.3lg\n", x1);
	}
	else if (nRoots == 2)
	{
		printf(" x1 = %.3lg\n x2 = %.3lg\n", x1, x2);
	}
	return 0; 
	
}



int SolveSquare (double a, double b, double c,
				 double* x1, double* x2)
{
	
	if (a <= 0+Precision && a >= 0-Precision) 
	{
		*x1 = -b/c;
		return -1;
	}
	else
	{
		double discr = b*b-4*a*c;
		if (discr > (0+Precision))
		{
			*x1 = (-b-sqrt(discr))/(2*a);
			*x2 = (-b+sqrt(discr))/(2*a);
			return 2;	
		}
		else if ((discr <= (0+Precision)) && (discr >= (0-Precision)))
		{
			*x1 = -b/(2*a);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
}
