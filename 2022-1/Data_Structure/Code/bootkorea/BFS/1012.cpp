#include <iostream>
#include <algorithm>

using namespace std;

int M, N, K;
bool land[51][51] = { 0, };
bool parkjunsang[51][51] = { 0, };

int moveX[4] = { 1, 0, -1, 0 };
int moveY[4] = { 0, 1, 0, -1 };

void DFS(int x, int y) {
   if (land[x][y] == 1)
   {
      land[x][y] = 0;
      
      for (int i = 0; i < 4; i++)
      {
         int X = moveX[i] + x;
         int Y = moveY[i] + y;

         if (x >= 0 && y >= 0 && x < M && y < N)
         {
            DFS(X, Y);
         }
      }
   }
}

int main(void) {
   
   int T, cnt;
   int x, y;

   cin >> T;

   while (T--)
   {
      cnt = 0;
      cin >> M >> N >> K;

      for (int i = 0; i < M; i++)
      {
         for (int j = 0; j < N; j++)
         {
            land[i][j] = 0;
         }
      }

      for (int i = 0; i < K; i++)
      {
         cin >> x >> y;
         land[x][y] = 1;
      }

      for (int i = 0; i < M; i++)
      {
         for (int j = 0; j < N; j++)
         {
            if (land[i][j] == 1)
            {
               DFS(i, j);
               cnt++;
            }
         }
      }

      cout << cnt << "\n";
   }
   return 0;
}