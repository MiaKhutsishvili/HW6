// Kimia Khudsiani 40223030

#include <stdio.h>
#include <math.h>

struct eq 
{
    double a, b, c;
    double roots[2];
    double delta;
};

int solver (struct eq *);

int main()
{
    struct eq toSolve;
    printf ("Enter a: "); scanf ("%lf", &toSolve.a);
    printf ("Enter b: "); scanf ("%lf", &toSolve.b);
    printf ("Enter c: "); scanf ("%lf", &toSolve.c);
    if (!toSolve.a && !toSolve.b)
    {
        printf ("Error! a & b cannot be 0 at the same time.\n");
        return 0;
    }
    switch (solver (&toSolve))
    {
        case 0:
            printf ("This equation has no real roots!\n");
            break;
        case 1:
            printf ("There is 1 root: %lf\n", toSolve.roots[0]);
            break;
        case 2:
            printf ("There are 2 roots: %lf & %lf\n", toSolve.roots[0], toSolve.roots[1]);
    }
    return 0;
}

int solver (struct eq * ptr)
{
    double a = ptr->a, b = ptr->b, c = ptr->c;
    if (!ptr->a)
    {
        ptr->roots[0] = -c / b;
        return 1;
    }
    ptr->delta = b * b - 4 * a * c;
    if (ptr->delta < 0)
        return 0;
    ptr->roots[0] = (-b + sqrt(ptr->delta)) / (2 * a);
    ptr->roots[1] = (-b - sqrt(ptr->delta)) / (2 * a);
    if (!ptr->delta)
        return 1;
    return 2;
}
