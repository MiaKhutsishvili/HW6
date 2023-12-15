// Kimia Khudsiani 40223030
#include <stdio.h>
#include <math.h>

double a, b, c;
int solver (double *);

int main()
{
    double roots[2];
    printf ("Enter a, b, c: ");
    scanf ("%lf%lf%lf", &a, &b, &c);
    if (!a && !b)
    {
        printf ("Error!\n");
        return 0; 
    }
    switch (solver (roots))
    {
        case 0:
            printf ("This equation has no real roots.\n");
            break;
        case 1:
            printf ("There is 1 root:\n%lf\n", roots[0]);
            break;
        case 2:
            printf ("There are 2 roots:\n%lf & %lf\n", roots[0], roots[1]);
    }
    return 0;
}

int solver (double * roots)
{
    if (!a)
    {
        roots[0] = -c / b;
        return 1;
    }
    double delta = b * b - 4 * a * c;
    if (delta < 0)
        return 0;
    roots[0] = (-b + sqrt(delta)) / (2 * a);
    roots[1] = (-b - sqrt(delta)) / (2 * a);
    if (!delta)
        return 1;
    return 2;
}
