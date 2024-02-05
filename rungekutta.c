#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(void) {
    float x[15];
    float y[15];
    float Ki1[15];
    float XiPlusH[15];
    float YiPlusHK[15];
    float Ki2[15];
    float YiPlus1[15];
    float e[15];

    float varX =0, varY =1, varKi1, varXiPlusH, varYiPlusHK, varKi2, varYiPlus1, varE;
    float h;

    printf("What do you want H to be?\n");
    scanf("%f", &h);

    for (int i = 0; i < 15; i++) {

        varKi1 = (3.4*(((varX*varX)) + 2.5))/((varY*varY) - 4.8);
        varXiPlusH = varX + h;
        varYiPlusHK = varY + (h*varKi1);
        varKi2 = (3.4*((varXiPlusH*varXiPlusH) + 2.5))/((varYiPlusHK*varYiPlusHK) - 4.8);
        varYiPlus1 = varY + ((h/2) * (varKi1 + varKi2));
        varE = ((varYiPlus1 - varY)/varY) * 100;


        x[i] = varX;
        y[i] = varY;
        Ki1[i] = varKi1;
        XiPlusH[i] = varXiPlusH;
        YiPlusHK[i] = varYiPlusHK;
        Ki2[i] = varKi2;
        YiPlus1[i] = varYiPlus1;
        e[i] = varE;

        varX = varXiPlusH;
        varY = varYiPlus1;


        }

        printf(" we have the differential equation: dy/dx = 3.4(x^2 + 2.5) / y^2 - 4.8. And we approximate it using Runge Kutta\n\n\n");

    printf ("--Xi-- \t| --Yi-- \t| --Ki1-- \t| --Xi+h-- \t| --Yi+hk-- \t| --Ki2-- \t| --Yi+1-- \t| --e-- \n");
    for (int j =0; j < 15; j++) {
        printf ("%.3f \t| %.3f \t| %.3f \t| %.3f \t| %.3f \t| %.3f \t| %.3f \t| %.3f%%\n", x[j], y[j], Ki1[j], XiPlusH[j], YiPlusHK[j], Ki2[j], YiPlus1[j], e[j]);
        printf ("____________________________________________________________________________________________________________________\n");

    }
}

