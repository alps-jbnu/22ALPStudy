#define MAX 4000001

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> primeN;
bool isPrime[MAX];
int n;
int c;

void findPrimeNumber()
{
  fill(isPrime, isPrime + MAX, true);

  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i < MAX; i++)
  {
    long long j = i;
    while (true)
    {
      j += i;
      if (j >= MAX)
        break;
      if (!isPrime[j])
        continue;
      else
        isPrime[j] = false;
    }
  }
  for (int i = 2; i < MAX; i++)
  {
    if (isPrime[i])
      primeN.push_back(i);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  findPrimeNumber();

  cin >> n;
  int st = 0;
  int en = 0;
  long long sum = 0;

  while (true)
  {
    if (st == en - 1 && sum > n)
      break;
    if (sum < n)
    {
      if (en == primeN.size())
        break;
      sum += primeN[en++];
    }

    else if (sum == n)
    {
      c++;
      if (en == primeN.size())
        break;
      sum += primeN[en++];
      sum -= primeN[st++];
    }
    else
      sum -= primeN[st++];
  }
  cout << c << "\n";

  return 0;
}