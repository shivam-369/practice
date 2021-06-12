#include <iostream>
using namespace std;
#define ll long long int

int getCount(int n, int a[], int b[], int c[], int x, int y, int z, int m)
{
    int count = 0;
    int mod;
    for (int i = 0; i < n; i++)
    {
        mod = ((x % m * a[i] % m) + (y % m * b[i] % m) - (z % m * c[i] % m)) % m;
        if (mod == 0)
        {
            count++;
        }
    }
    return count;
}

int main(int argc, char **argv)
{
    int n, m, k, lx, rx, ly, ry, lz, rz;
    int count = 0;
    cin >> n >> m >> k;
    int *a = new int[n], *b = new int[n], *c = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        a[i] %= m;
        b[i] %= m;
        c[i] %= m;
    }
    cin >> lx >> rx;
    cin >> ly >> ry;
    cin >> lz >> rz;
    for (int x = lx; x <= min(rx, lx + m); x++)
    {
        for (int y = ly; y <= min(ry, ly + m); y++)
        {
            for (int z = lz; z <= min(rz, lz + m); z++)
            {
                count = getCount(n, a, b, c, x, y, z, m);
                if (count == k)
                {
                    cout << x << " " << y << " " << z << endl;
                    break;
                }
            }
            if (count == k)
                break;
        }
        if (count == k)
            break;
    }
    if (count != k)
    {
        cout << -1 << endl;
    }
    delete[] a;
    delete[] b, delete[] c;
    return 0;
}