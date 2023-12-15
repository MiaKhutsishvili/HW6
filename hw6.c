//Kimia Khudsiani 40223030

#include <stdio.h>
#include <math.h>

struct eq
{
    double root1;
    double root2;
    double delta;
};

struct eq solver (double, double, double);

int main()
{
    double a, b, c;
    printf ("Enter a: "); scanf ("%lf", &a);
    printf ("Enter b: "); scanf ("%lf", &b);
    if (!a && !b)
    {
        printf ("Error: a & b cannot be 0 at the same time.\n");
        return 0;
    }
    printf ("Enter c: "); scanf ("%lf", &c);
    if (solver(a, b, c).delta < 0)
        printf ("This equation has no real roots!\n");
    else if (!solver(a, b, c).delta)
        printf ("1 root: %lf\n", solver(a, b, c).root1);
    else
        printf ("2 roots: %lf & %lf\n", solver(a, b, c).root1, solver(a, b, c).root2);
    return 0;
}

struct eq solver (double a, double b, double c)
{
    struct eq toSolve;
    if (!a)
    {
        toSolve.delta = 0;
        toSolve.root1 = -c / b;
        return toSolve;
    }
    toSolve.delta = (b * b) - (4 * a * c);
    if (toSolve.delta >= 0)
        toSolve.root1 = (sqrt (toSolve.delta) - b) / (2 * a),
        toSolve.root2 = (-(sqrt (toSolve.delta)) - b) / (2 * a);
    return toSolve;
}
