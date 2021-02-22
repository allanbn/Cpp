#include <iostream>

#define LINES 3

using namespace std;

void halfPyramid(int lines)
{
  /**
   * The pattern is:
   *     *
   *     **
   *     ***
  */
  int i, j;
  for (i = 1; i <= lines; i++)
  {
    for (j = 1; j <= i; j++)
    {
      cout << "*";
    }
    cout << "\n";
  }
  return;
}

void halfPyramidToLeft(int lines)
{
  /**
   * The pattern is:
   *      *
   *     **
   *    ***
  */
  int i, j;
  for (i = 1; i <= lines; i++)
  {
    for (j = 1; j <= lines-i; j++)
    {
      cout << " ";
    }
    for (j = 1; j <= i; j++)
    {
      cout << "*";
    }
    cout << "\n";
  }
  return;
}

void halfUpsideDownPyramid(int lines)
{
  /**
   * The pattern is:
   *     ***
   *     **
   *     *
  */
  int i, j;
  for (i = 1; i <= lines; i++)
  {
    for (j = i; j <= lines; j++)
    {
      cout << "*";
    }
    cout << "\n";
  }
  return;
}

void halfUpsideDownPyramidToLeft(int lines)
{
  /**
   * The pattern is:
   *     ***
   *      **
   *       *
  */
  int i, j;
  for (i = 1; i <= lines; i++)
  {
    for (j = 1; j < i; j++)
    {
      cout << " ";
    }
    for (j = i; j <= lines; j++)
    {
      cout << "*";
    }
    cout << "\n";
  }
  return;
}

void fullUpsideDownPyramid(int lines)
{
  /**
   * The pattern is:
   *     *****
   *      ***
   *       *
  */
  int i, j, k;
  for (i = lines; i >= 1; i--)
  {
    for (j = lines-i; j >= 1; j--)
    {
      cout << " ";
    }
    for (k = i*2-1; k >= 1; k--)
    {
      cout << "*";
    }
    cout << "\n";
  }
  return;
}

void fullPyramid(int lines)
{
  /**
   * The pattern is:
   *      *
   *     ***
   *    *****
  */
  int i, j, k;
  for (i = 1; i <= lines; i++)
  {
    for (j = 1; j <= lines-i; j++)
    {
      cout << " ";
    }
    for (k = 1; k <= 2*i-1; k++)
    {
      cout << "*";
    }
    cout << "\n";
  }
  return;
}

void diamondPattern(int lines)
{
/**
 * The pattern is:
 *      *  
 *     ***
 *    *****
 *     ***
 *      *
*/
  int i, j, k, n;
  // Upside print
  for (i = 1; i <= (lines/2)+1; i++)
  {
    for (j = 1; j <= lines-i; j++)
    {
      cout << " ";
    }
    for (k = 1; k <= 2*i-1; k++)
    {
      cout << "*";
    }
    cout << "\n";
  }
  // Downside print
  for (i = (lines/2); i >= 1; i--)
  {
    for (j = lines-i; j >= 1; j--)
    {
      cout << " ";
    }
    for (k = i*2-1; k >= 1; k--)
    {
      cout << "*";
    }
    cout << "\n";
  }
  return;
} 

int main()
{
  halfPyramid(LINES);
  cout << "\n";
  halfUpsideDownPyramid(LINES);
  cout << "\n";
  halfPyramidToLeft(LINES);
  cout << "\n";
  halfUpsideDownPyramidToLeft(LINES);
  cout << "\n";
  diamondPattern(LINES);
  cout << "\n";
  fullPyramid(LINES);
  cout << "\n";
  fullUpsideDownPyramid(LINES);
  return 0;
}