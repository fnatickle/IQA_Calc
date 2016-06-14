#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*  Oxigênio Dissolvido : Peso 0.17 */
double q9 (double indcetesb) {
	double A = 100.8, B = -106, C = -3745;
	if (indcetesb > 140.0)
		return 47.0;
		indcetesb = A * exp (pow ((indcetesb + B), 2) / C);
	return indcetesb;
}

/* Coliformes Fecais : Peso 0.15 */
double q1 (double indcetesb) {
	double A = 98.03, B = -36.45, C = 3.14, D = 0.067;
	if (indcetesb > 10.0)
		return 3.0;
		/* Alteração na base do Log para estimação da qualidade da água em função da quantidade de coliformes fecais. */
		indcetesb = A + (B * log10(indcetesb)) + (C * pow(log10 (indcetesb), 2)) + (D * pow(log10 (indcetesb), 3));
	return indcetesb;
}

/* pH : Peso 0.12 */
double q2 (double indcetesb) {
	double A = 0.05421, B = 1.23, C = -0.09873;
 	if (indcetesb >= 12) 
     	return 3.0;     
    if ( indcetesb <= 2 ) 
	 	return 2.0;	 
	    indcetesb = A * pow(indcetesb, ((B * indcetesb) + (C * pow(indcetesb, 2)))) + 5.213; 
    return indcetesb; 
} 

/* Demanda Bioquímica de Oxigênio : Peso 0.1 */ 
double q3 (double indcetesb) { 
	/* Alteração no valor da "Variável B" para melhor apuração dos dados. */
	double A = 102.6, B = -0.1101; 
    if (indcetesb > 30) 
	   	return 2.0; 
	    indcetesb = A * exp((B * indcetesb)); 
    return indcetesb; 
} 

/* Fósforo total : Peso 0.1 */
double q5 (double indcetesb) {  
	double A = 213.7, B = -1.68, C = 0.3325; 
    if (indcetesb > 10.0) 
	  	return 5.0; 
		indcetesb = A * exp((B * pow(indcetesb, C))); 
    return indcetesb; 
} 

/* Nitrogênio total : Peso 0.1 */ 
double q4 (double indcetesb) { 
	double A = 98.96, B = -0.2232, C = -0.006457; 
	if (indcetesb > 90) 
     	return 1.0; 
		indcetesb = A * pow(indcetesb, (B + (C * indcetesb))); 
	return indcetesb; 
} 

/* Turbidez : Peso 0.08 */
double q7 (double indcetesb) { 
	double A = 97.34, B = -0.01139, C = -0.04917; 
    if (indcetesb > 100) 
    	return 5.0; 
		indcetesb = A * exp((B * indcetesb) + (C * sqrt(indcetesb))); 
	return indcetesb; 
} 

/* Variação de Temperatura : Peso 0.1 */ 
double q6 (double indcetesb ) {
	double A = 0.0003869, B = 0.1815, C = 0.01081; 
    if (indcetesb <= -5) 
	   	return 1; 
    if (indcetesb > 15) 
	 	return 9;	 
		indcetesb = (1 /((A * pow((indcetesb + B), 2))+ C));
	return indcetesb; 
}
/* Sólidos Totais : Peso 0.08 */ 
double q8 (double indcetesb) { 
	double A = 80.26, B = -0.00107, C = 0.03009, D = -0.1185; 
    if (indcetesb > 500) 
		return 30.0; 
		indcetesb = (A * exp((B * indcetesb) + (C * sqrt(indcetesb)))) + (D * indcetesb ); 
	return indice; 
} 
