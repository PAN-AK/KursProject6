#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define SCREENW  60
#define SCREENH  40
typedef double (*Tfun)(double);



double ntrvl() {}



double F1(double x) {
    setlocale(LC_ALL, "RUS");
    if (x > 0) {
        double res_1 = exp((log(5 * x) * pow(sin(x), 2)) / cbrt(0.2 * pow(x, 8)));
        return res_1;
    }
    else {
        printf("x �� ����������� ���\n");
        return 0;
    }

}


double F2(double x) {
    double res_2;
    if (x < 0) {
        res_2 = (1 + 2 * x) / pow(x, 2);
    }
    else if (x >= 1) {
        res_2 = pow(sin(x * sqrt(1 + x)), 2);
    }
    else if (x >= 0 && x < 1) {
        res_2 = pow(sin(x * exp(0.2 * x)), 2);
    }
    return res_2;
}


void Tabfun(double x1, double x2, double step, char func) {
    int f;

    if (x1 >= x2)
        printf("\n������ ������� �� ��������. ��������� �������(������� ������� ��������, ����� �������)");

    printf("\n�����:");
    printf("\n1. ���������� ������� �� ��������� ()");
    printf("\n2. ���������� ������� �� ������������� [)");
    printf("\n3. ���������� ������� �� ������������� (]");
    printf("\n4. ���������� ������� �� ������� []");
    printf("\n��� �����: ");
    scanf("%d", &f);
    printf("\n|        x        |      F(x)      |   ");
    printf("\n|_________________|________________|");

    for (double v = (f % 2 != 0 ? x1 + step : x1); (f == 1 && v < x2) || (f == 2 && v < x2) || (f == 3 && v <= x2) || (f == 4 && v <= x2); v += step) {
        double result = (func == 'V') ? F1(v) : F2(v);
        printf("\n|     %8.4lf    |    %8.4lf    |", v, result);
    }
}


void plot(double x0, double x1, Tfun f) {
    char screen[SCREENW][SCREENH];
    double x, y[SCREENW];
    double ymin = INFINITY, ymax = -INFINITY;
    double hx, hy;
    int i, j;
    int xz, yz;

    hx = (x1 - x0) / (SCREENW - 1);
    for (i = 0, x = x0; i < SCREENW; ++i, x += hx) {
        y[i] = f(x);
        if (!isnan(y[i])) {
            if (y[i] < ymin) ymin = y[i];
            if (y[i] > ymax) ymax = y[i];
        }
    }


    if (ymin == INFINITY || ymax == -INFINITY) {
        printf("��� �������� ������� �� ���������� � �������� ���������.\n");
        return;
    }

    hy = (ymax - ymin) / (SCREENH - 1);
    yz = (int)floor(-ymin / hy + 0.5);
    xz = (int)floor((0. - x0) / hx + 0.5);


    for (j = 0; j < SCREENH; ++j)
        for (i = 0; i < SCREENW; ++i) {
            if (j == yz && i == xz) screen[i][j] = '+';
            else if (j == yz) screen[i][j] = '-';
            else if (i == xz) screen[i][j] = '|';
            else screen[i][j] = ' ';
        }


    for (i = 0; i < SCREENW; ++i) {
        j = (int)floor((ymax - y[i]) / hy + 0.5);
        if (j >= 0 && j < SCREENH) {
            screen[i][j] = '*';
        }
    }


    for (j = SCREENH - 1; j >= 0; --j) {
        for (i = 0; i < SCREENW; ++i) putchar(screen[i][j]);
        putchar('\n');
    }
}


int main() {
    setlocale(LC_ALL, "RUS");
    int a, b, c;
    double x, x_min, x_max, step;
    char choice;




    while (1) {
        printf("\n�������� ��������:\n");
        printf("1. ��������� �������� ������� F1(x)\n");
        printf("2. ��������� �������� ������� F2(x)\n");
        printf("3. ������� ������� �������� ������� F1(x) �� �������� ���������\n");
        printf("4. ������� ������� �������� ������� F2(x) �� �������� ���������\n");
        printf("5. ��������� ������ �������\n");
        printf("6. �����\n");
        printf("��� �����: ");
        scanf(" %d", &c);


        switch (c) {
        case 1:
            printf("������� �: \n");
            scanf("%lf", &x);
            printf("%lf", F1(x));
            break;
        case 2:
            printf("������� �: \n");
            scanf("%lf", &x);
            printf("%lf", F2(x));
            break;
        case 3:
            printf("\n�����:");
            printf("\n1. ���������� ������� �� ��������� ()");
            printf("\n2. ���������� ������� �� ������������� [)");
            printf("\n3. ���������� ������� �� ������������� (]");
            printf("\n4. ���������� ������� �� ������� []");
            printf("\n��� �����: ");
           
            printf("\n������� �������� ��:"); 
            scanf(" %lf", &x_min); 
            printf("\n��:"); 
            scanf(" %lf", &x_max);
            printf("\n�������� ������� V ��� Y:"); 
            scanf(" %c", &choice); 
            printf("\n������� ��� ���������:");
            scanf("%lf", &step);
            Tabfun(x_min, x_max, step, choice == 'V' ? F1 : F2);
            break;
        case 4:
            printf("\n�����:");
            printf("\n1. ���������� ������� �� ��������� ()");
            printf("\n2. ���������� ������� �� ������������� [)");
            printf("\n3. ���������� ������� �� ������������� (]");
            printf("\n4. ���������� ������� �� ������� []");
            printf("\n��� �����: ");

            printf("\n������� �������� ��:");
            scanf(" %lf", &x_min);
            printf("\n��:");
            scanf(" %lf", &x_max);
            printf("\n�������� ������� V ��� Y:");
            scanf(" %c", &choice);
            printf("\n������� ��� ���������:");
            scanf("%lf", &step);
            Tabfun(x_min, x_max, step ,choice == 'V' ? F1 : F2);
            break;
        case 5:
            printf("\n������� �������� ��:");
            scanf(" %lf", &x_min);
            printf("\n��:");
            scanf(" %lf", &x_max);
            printf("\n�������� ������� V ��� Y:");
            scanf(" %c", &choice);
            plot(x_min, x_max, choice == 'V' ? F1 : F2);
            break;
        default:
            printf("����� �� ���������.\n");
            return 0;
        }

    }
}
