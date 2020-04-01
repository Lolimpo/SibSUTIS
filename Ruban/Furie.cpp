#include <bits/stdc++.h>

#define n 6
#define PI 3.14159265359

using namespace std;

typedef long long ll;
typedef long double ld;

ll sr = 0;

struct comp{
    ld real;
    ld img;
};

comp multiply(comp a, comp b)
{
    comp res;
    res.real = a.real * b.real - a.img * b.img;
    res.img = a.real * b.img + a.img * b.real;
    return res;
}

comp Exp(int k, int j, int del, int st)
{
    comp xp;
    xp.real = cos(pow(-1, st) * 2.0 * PI * k * j / del);
    xp.img = sin(pow(-1, st) * 2.0 * PI * k * j / del);
    return  xp;
}

void PrintMas(comp *arr)
{
    for(int i = 0; i < n; i++)
    {
        cout << fixed;
        cout << setprecision(4) << arr[i].real << " " << arr[i].img << endl;
    }
}

comp *furie(comp *arr)
{
    comp *A = new comp[n];
    comp temp;
    for(int i = 0; i < n; i++)
    {
        A[i].real = 0;
        A[i].img = 0;
        for(int j = 0; j < n; j++)
        {
            temp.real = cos(-2 * PI * j * i / (n * 1.));
            sr += 3;
            temp.img = sin(-2 * PI * j * i / (n * 1.));
            temp = multiply(temp, arr[j]);
            sr++;
            A[i].real += temp.real;
            A[i].img += temp.img;
            sr++;
        }
        A[i].real = A[i].real * (1. / n);
        A[i].img = A[i].img * (1. / n);
    }
    return A;
}

comp *furie_rev(comp *arr)
{
    comp *A = new comp[n];
    comp temp;
    for(int i = 0; i < n; i++)
    {
        A[i].real = 0.;
        A[i].img = 0.;
        for(int j = 0; j < n; j++)
        {
            temp.real = cos(2. * PI * j * i / (n * 1.));
            temp.img = sin(2. * PI * j * i / (n * 1.));
            //sr += 3;
            temp = multiply(temp, arr[j]);
            //sr++;
            A[i].real += temp.real;
            A[i].img += temp.img;
        }
    }
    return A;
}

comp* halfFurie(comp *arr, int p1, int p2)
{
    comp *A = new comp[n];
    comp **A1 = new comp*[p1];
    comp **A2 = new comp*[p1];
    for(int i = 0; i < p1; i++)
    {
        A1[i] = new comp[p2];
        A2[i] = new comp[p2];
    }
    for(int i = 0; i < p1; i++)
    {
        for(int j = 0; j < p2; j++)
        {
            A1[i][j].real = 0;
            A1[i][j].img = 0;
            A2[i][j].real = 0;
            A2[i][j].img = 0;
        }
    }
    int k1 = 0, k2 = 0, j1 = 0, j2 = 0;
    for(k1 = 0; k1 < p1; k1++)
    {
        for(j2 = 0; j2 < p2; j2++)
        {
            for(j1 = 0; j1 < p1; j1++)
            {
                A1[k1][j2].real += multiply(Exp(j1, k1, p1, 1), arr[j2 + p2 * j1]).real;
                A1[k1][j2].img += multiply(Exp(j1, k1, p1, 1), arr[j2 + p2 * j1]).img;
                sr += 3;
            }
            A1[k1][j2].real /= p1;
            A1[k1][j2].img /= p1;
        }
    }
    for(k1 = 0; k1 < p1; k1++)
    {
        for(k2 = 0; k2 < p2; k2++)
        {
            for(j2 = 0; j2 < p2; j2++)
            {
                A2[k1][k2].real += multiply(Exp(j2, (k1 + p1 * k2), p1 * p2, 1), A1[k1][j2]).real;
                A2[k1][k2].img += multiply(Exp(j2, (k1 + p1 * k2), p1 * p2, 1), A1[k1][j2]).img;
                sr += 3;
            }
            A2[k1][k2].real /= p2;
            A2[k1][k2].img /= p2;
        }
    }
    int k = 0;
    for(int i = 0; i < p2; i++)
    {
        for(int j = 0; j < p1; j++)
        {
            A[k].real = A2[j][i].real;
            A[k].img = A2[j][i].img;
            k++;
        }
    }
    return A;
}

comp* halfFurie_o(comp *arr)
{
    comp *A = new comp[n];
    for(int i = 0; i < n; i++)
    {
        A[i].real = 0;
        A[i].img = 0;
        for(int j = 0; j < n; j++)
        {
            A[i].real += multiply(Exp(i, j, n, 2), arr[j]).real;
            A[i].img += multiply(Exp(i, j, n, 2), arr[j]).img;
        }
    }
    return A;
}

int main()
{
    int p1, p2;
    cin >> p1 >> p2;
    struct comp *arr = new comp[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i].real >> arr[i].img;
        //{arr[i].real = rand()%101; arr[i].img = rand()%101;}
    system("cls");
    cout << "\nOrigin: " << endl;
    PrintMas(arr);
    cout << "\nFurie: " << endl;
    arr = furie(arr);
    PrintMas(arr);
    cout << "\nTrudoemkost: " << sr << endl;
    cout << "\nObratni: " << endl;
    arr = furie_rev(arr);
    PrintMas(arr);
    sr = 0;
    cout << "\nHalf-fast Furie: " << endl;
    arr = halfFurie(arr, p1, p2);
    PrintMas(arr);
    cout << "\nTrudoemkost: " << sr << endl;
    cout << "\nObratni: " << endl;
    arr = halfFurie_o(arr);
    PrintMas(arr);
    return 0;
}
