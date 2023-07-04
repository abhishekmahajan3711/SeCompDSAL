// Given sequence k = k1 <k2 < … <kn of n sorted keys, with a search probability pi for each 
// key ki . Build the Binary search tree that has the least search cost given the access 
// probability for each key? 

#include <iostream>
using namespace std;

float p[20], q[20];
int a[20];
int w[20][20], c[20][20], r[20][20];
int n;
int min_value(int i, int j)
{
    int m, k;
    int minimum = 9999;
    for (m = r[i][j - 1]; m <= r[i + 1][j]; m++)
    {
        if ((c[i][m - 1] + c[m][j]) < minimum)
        {
            minimum = c[i][m - 1] + c[m][j];
            k = m;
        }
    }
    return k;
}
void create_obst()
{

    for (int i = 0; i < n; i++)
    {
        // for j-i=0
        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;

        // for j-i=1
        w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        r[i][i + 1] = i + 1;
    }
    c[n][n] = 0;
    r[n][n] = 0;
    w[n][n] = q[n];

    // for j-i=2,3,4....n
    for (int m = 2; m <= n; m++)
    {
        for (int i = 0; i <= n - m; i++)
        {
            int j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            int k = min_value(i, j);
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
            r[i][j] = k;
        }
    }
    cout << "\n\nOptimal BST is :: ";
    cout << "\nw[0][" << n << "] :: " << w[0][n];
    cout << "\nc[0][" << n << "] :: " << c[0][n];
    cout << "\nr[0][" << n << "] :: " << r[0][n];
}
void print(int l1, int r1)
{
    if (l1 >= r1)
        return;
    if (r[l1][r[l1][r1] - 1] != 0)
        cout << "\n Left child of " << r[l1][r1] << " :: " << a[r[l1][r[l1][r1] - 1]];
    if (r[r[l1][r1]][r1] != 0)
        cout << "\n Right child of " << r[l1][r1] << " :: " << a[r[r[l1][r1]][r1]];
    print(l1, r[l1][r1] - 1);
    print(r[l1][r1], r1);
    return;
}

int main()
{
    cout << "Enter total number of nodes" << endl;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter the" << i << "node : " << endl;
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter the" << i << "succesfull probability" << endl;
        cin >> p[i];
    }
    for (int i = 0; i <= n; i++)
    {
        cout << "Enter the" << i + 1 << "   unsuccesfull probability" << endl;
        cin >> q[i];
    }
    create_obst();
    print(0, n);
    return 0;
}
