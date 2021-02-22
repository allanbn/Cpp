#include <iostream>

#define ui unsigned int

using namespace std;

ui _pow(int x, int n)
{
  ui p = 1;
  if (n == 0)
    return 1;
  if (x == 2)
  {
    p = p << n;
    return p;
  }

  ui y = _pow(x, n / 2);
  if (n % 2 == 1)
    return x * y * y;
  return y * y;
}

int main()
{
  int cases;
  cin >> cases;
  while (cases--)
  {
    ui n;
    cin >> n;
    cout << (ui)_pow(2, n)-1 << "\n";
  }
  return 0;
}