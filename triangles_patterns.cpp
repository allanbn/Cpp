#include <bits/stdc++.h>

using namespace std;
/**
 *                            *  
 *                           ***
 *                          *****
 *                           ***
 *                            *
*/
int main()
{
  int i, j, k, n;
  // parte de cima
  for (i = 1; i <= (5/2)+1; i++)
  {
    for (j = 1; j <= 5-i; j++)
    {
      cout << " ";
    }
    for (k = 1; k <= 2*i-1; k++)
    {
      cout << "*";
    }
    cout << endl;
  }
  // parte de baixo
  for (i = (5/2); i >= 1; i--)
  {
    for (j = 5-i; j >= 1; j--)
    {
      cout << " ";
    }
    for (k = i*2-1; k >= 1; k--)
    {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}