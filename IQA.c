#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Calculos.h"

int main (void) {

double O2, CF, pH, DBO, FT, NT, TU, deltaT, ST, IQA, R1, R2, R3, R4, R5, R6, R7, R8, R9;

printf("Coliformes Fecais (NMP/100 ml):");  
scanf("%lf", &CF); 
printf("Potencial Hidrogeniônico (pH):"); 
scanf("%lf", &pH); 
printf("DBO - Demanda Bioquímica de Oxigênio(mg/L): "); 
scanf("%lf", &DBO); 
printf("Nitrato Total (mg/L): "); 
scanf("%lf", &NT); 
printf("Fosfato Total (mg/L): "); 
scanf("%lf", &FT); 
printf("Variação de Temperatura(°C):"); 
scanf("%lf", &deltaT); 
printf("Turbidez (UNT): "); 
scanf("%lf", &TU); 
printf("OD - Oxigênio Dissolvido (%% saturação): "); 
scanf("%lf", &O2); 
printf("Sólidos Totais (mg/L): "); 
scanf("%lf", &ST); 

R1 = q1(CF);
R2 = q2(pH);
R3 = q3(DBO);
R4 = q4(NT);
R5 = q5(FT);
R6 = q6(deltaT);
R7 = q7(TU);
R8 = q8(ST);
R9 = q9(O2);

IQA = pow(R1,0.15) * pow(R2,0.12) * pow(R3,0.10) * pow(R4,0.10)* pow(R5,0.10) * pow(R6,0.10) * pow(R7,0.08) * pow(R8,0.08) * pow(R9,0.17);

if(IQA <20 && IQA >= 0){
 		printf("IQA: %lf\nQualidade: Péssima\n",IQA);
 		}
 		else if(IQA <37 && IQA >= 20){
 	printf("IQA: %lf\nQualidade: Ruim\n",IQA);
 		}
 		else if(IQA <51 && IQA >= 37){
 		printf("IQA: %lf\nQualidade: Aceitável\n",IQA);
 			}
 			else if(IQA <80 && IQA >= 51){
 			printf("IQA: %lf\nQualidade: Boa\n",IQA);
 				}
 				else if(IQA >= 80){
 				printf("IQA: %lf\nQualidade: Ótima\n",IQA);
 					}else {
 					printf("Sem valores o suficiente.\n");
 				}
return 0;
}
