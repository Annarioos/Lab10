#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

double Fa(double x);
double Fb(double x);
double z(double a, double b);
double diff_squares(double a, double b);
double d_sum(double a, double b);

double sin_n(double x, int N);
double sin_eps(double x, double eps);

double cot_neg_n(double x, int N);
double cot_neg_eps(double x, double eps);

int main(void)
{
    double x, f1, f2;
    double res;
    int choice;
    int N, i;
    double eps;
    double s_std, s_n, s_eps;
    double c_std, c_n, c_eps;
    setlocale(LC_CTYPE, ".UTF8");

    printf("Задание 1\n");
    printf("F1(x) = x^2 - 3x + 9, если x <= 3;  1 / (x^3 + 3), если x > 3\n");
    printf("F2(x) = x * e^(sin(x^2))\n");
    printf("Введите x: ");
    scanf("%lf", &x);

    f1 = Fa(x);
    f2 = Fb(x);

    printf("fa(x) = %lf, fb(x) = %lf\n", f1, f2);

    printf("произведение = %lf, разность квадратов = %lf, удвоенная сумма = %lf\n\n",
        z(f1, f2), diff_squares(f1, f2), d_sum(f1, f2));

    do
    {
        printf("Меню:\n");
        printf("1 - значение F1(x)\n");
        printf("2 - значение F2(x)\n");
        printf("3 - произведение\n");
        printf("4 - разность квадратов\n");
        printf("5 - удвоенная сумма\n");
        printf("0 - выход из меню\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5)
        {
            printf("Введите x: ");
            scanf("%lf", &x);
            f1 = Fa(x);
            f2 = Fb(x);
        }

        switch (choice)
        {
        case 1:
            res = f1;
            printf("F1(%.4lf) = %lf\n\n", x, res);
            break;
        case 2:
            res = f2;
            printf("F2(%.4lf) = %lf\n\n", x, res);
            break;
        case 3:
            res = z(f1, f2);
            printf("Произведение = %lf\n\n", res);
            break;
        case 4:
            res = diff_squares(f1, f2);
            printf("Разность квадратов = %lf\n\n", res);
            break;
        case 5:
            res = d_sum(f1, f2);
            printf("Удвоенная сумма = %lf\n\n", res);
            break;
        case 0:
            printf("Выход из меню\n\n");
            break;
        default:
            printf("Неизвестный пункт меню\n\n");
            break;
        }
    } while (choice != 0);

    printf("Задание 2. sin(x) \n");
    printf("Введите x (в радианах): ");
    scanf("%lf", &x);
    printf("Введите число членов ряда N: ");
    scanf("%d", &N);
    printf("Введите точность eps: ");
    scanf("%lf", &eps);

    if (N < 1 || eps <= 0)
        printf("Ошибка: N должно быть >= 1, eps > 0\n\n");
    else
    {
        s_std = sin(x);

        printf("\n  N |    sin_N     |  отклонение\n");
        printf("----+--------------+--------------\n");
        for (i = 1; i <= N; i++)
        {
            s_n = sin_n(x, i);
            printf("%3d | %12.8lf | %+.4e\n", i, s_n, s_n - s_std);
        }

        s_eps = sin_eps(x, eps);
        printf("\nСтандартная sin(x)  = %.10lf\n", s_std);
        printf("Ряд по N = %d       = %.10lf, отклонение %+.4e\n",
            N, sin_n(x, N), sin_n(x, N) - s_std);
        printf("Ряд по eps = %g = %.10lf, отклонение %+.4e\n\n",
            eps, s_eps, s_eps - s_std);
    }

    printf("Задание 2.Вариант 9: cot(x) \n");
    printf("cot(x) = 1/x - (x/3 +x^3/45 + 2x^5/945 + 2x^7/4725 + ...)\n");
    printf("Введите x (0 < |x|< PI): ");
    scanf("%lf", &x);
    printf("Введите число членов ряда N (1...4): ");
    scanf("%d", &N);
    printf("Введите точность eps: ");
    scanf("%lf", &eps);

    if (x == 0 || fabs(x) >= 3.1415926535)
    {
        printf("Ошибка: x должен быть в диапазоне от -PI до PI(исключая 0)\n");
    }
    else if (N < 1 || eps <= 0)
    {
        printf("Ошибка: N должно быть >= 1, eps > 0\n");
    }
    else
    {
        c_std = 1.0 / tan(x);

        printf("\n  N |    cot_N     |  отклонение\n");
        printf("----+--------------+--------------\n");
        for (i = 1; i <= N; i++)
        {
            c_n = cot_neg_n(x, i);
            printf("%3d | %12.8lf | %+.4e\n", i, c_n, c_n - c_std);
        }

        c_eps = cot_neg_eps(x, eps);
        printf("\nСтандартная cot(x)  = %.10lf\n", c_std);
        printf("Ряд по N = %d      = %.10lf, отклонение %+.4e\n",
            N, cot_neg_n(x, N), cot_neg_n(x, N) - c_std);
        printf("Ряд по eps = %g= %.10lf, отклонение %+.4e\n",
            eps, c_eps, c_eps - c_std);
    }
    return 0;
}

double Fa(double x)
{
    double y;
    if (x <= 3)
        y = x* x -3 * x + 9;
    else
        y =1.0 /(x* x * x+ 3);
    return y;
}

double Fb(double x)
{
    double y;
    y = x * exp(sin(x *x));
    return y;
}

double z(double a, double b)
{
    return a* b;
}

double diff_squares(double a, double b)
{
    return a * a - b *b;
}

double d_sum(double a, double b)
{
    return 2* (a+ b);
}

double sin_n(double x, int N)
{
    double sum =0, t= x;
    int k;

    for (k = 1; k <= N; k++)
    {
        sum += t;
        t *= -x * x / ((2 * k) * (2 * k + 1));
    }
    return sum;
}

double sin_eps(double x, double eps)
{
    double sum = 0, t = x;
    int k = 1;

    while (fabs(t) >= eps)
    {
        sum += t;
        t *= -x * x / ((2 * k) * (2 * k + 1));
        k++;
    }
    return sum;
}

double cot_neg_n(double x, int N)
{
    double sum = 1.0 / x;
    double t = 0.0;
    int k;

    for (k = 1; k <= N; k++)
    {
        if (k == 1)      t = -(x/ 3.0);
        else if (k == 2) t = -(x * x* x / 45.0);
        else if (k == 3) t = -(2.0 * x * x* x * x *x / 945.0);
        else if (k == 4) t = -(2.0 * x* x * x* x * x * x * x / 4725.0);
        else break;

        sum += t;
    }
    return sum;
}

double cot_neg_eps(double x, double eps)
{
    double sum = 1.0 /x;
    double t= 0.0;
    int k = 1;

    while (k <= 4)
    {
        if (k == 1) t = -(x /3.0);
        else if (k == 2) t = -(x * x *x / 45.0);
        else if (k == 3) t = -(2.0 * x * x * x *x * x/ 945.0);
        else if (k == 4) t = -(2.0 * x* x * x * x * x * x* x / 4725.0);

        if (fabs(t) < eps) break;
        sum += t;
        k++;
    }
    return sum;
}
