#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

double S(double a);
char tr(int r, int c, int a, char sym);

int main(void)
{
    char sym, c;
    int side;
    int choice;
    int row, col;
    double s;
    setlocale(LC_CTYPE, ".UTF8");

    printf("Фигура: перевернутый прямоугольный треугольник(Вариант 9)\n");
    printf("Введите символ, из которого будет строиться фигура: ");
    scanf(" %c", &sym);
    printf("Введите сторону треугольника a (высоту в символах): ");
    scanf("%d", &side);

    if (side < 1)
        printf("Ошибка: сторонадолжна быть больше 0\n");
    else
    {
        do
        {
            printf("\nМеню:\n");
            printf("1 -рассчитать площадь\n");
            printf("2 -вывести определение фигуры\n");
            printf("3 -нарисовать фигуру\n");
            printf("0 -выход\n");
            printf("Ваш выбор: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                s = S(side);
                printf("Площадь треугольника = %.2f\n", s);
                break;
            case 2:
                printf("Прямоугольный равнобедренный треугольник, повернутый вершиной вниз.\n");
                printf("Имеет боковые стороны 'a',угол между которыми равен 90 градусов.\n");
                break;
            case 3:
                printf("\n");

                for (row = 0; row < side; row++)
                {
                    for (col = 0; col < (2 * side - 1); col++)
                    {
                        c = tr(row, col, side, sym);
                        putchar(c);
                    }
                    printf("\n");
                }
                break;
            case 0:
                printf("Выход из программы\n");
                break;
            default:
                printf("Неизвестный пункт меню\n");
                break;
            }
        } while (choice !=0);
    }
    return 0;
}

double S(double a)
{
    double s;
    s = 0.5 *a *a;
    return s;
}

char tr(int r, int c, int a, char sym)
{
    if (c < r)
    {
        return ' ';
    }
    if (r == 0 && c< (2 * a -1))
    {
        return sym;
    }
    if (r == a - 1 && c == r)
    {
        return sym;
    }
    if (c == r)
    {
        return sym;
    }
    if (c == (2 * a- 2 - r))
    {
        return sym;
    }
    return ' ';
}
