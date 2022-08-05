//! 1h
#include <iostream>
using namespace std;

//* 인자 X_Y = X가 Y를 이기는 경우의 수
bool is_non_transitive(int A_B, int B_A, int B_C, int C_B, int C_A, int A_C)
{
    //* 비기는 경우가 있을 때
    if(A_B == B_A || B_C == C_B || C_A == A_C) return false;
    
    //* A -> B -> C 순서로 이길 때
    if(A_B > B_A && B_C > C_B && C_A > A_C) return true;
    //* C -> B -> A 순서로 이길 때
    if(A_B < B_A && B_C < C_B && C_A < A_C) return true;

    return false;
}

int solution()
{
    int A[4], B[4], C[4];
    int A_B = 0, B_A = 0;

    for (int i = 0; i < 4; i++) cin >> A[i];
    for (int i = 0; i < 4; i++) cin >> B[i];

    //* A <-> B 먼저 계산
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(A[i] < B[j]) A_B++;
            else if(A[i] == B[j]) continue;
            else B_A++;
        }
    }

    //* C 모든 경우 브루트 포스
    for (int a = 1; a <= 10; a++)
    {
        C[0] = a;
        for (int b = 1; b <= 10; b++)
        {
            C[1] = b;
            for (int c = 1; c <= 10; c++)
            {
                C[2] = c;
                for (int d = 1; d <= 10; d++)
                {
                    C[3] = d;
                    
                    int B_C = 0, C_B = 0, C_A = 0, A_C = 0;

                    //* B <-> C 계산
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            if(B[i] < C[j]) B_C++;
                            else if(B[i] == C[j]) continue;
                            else C_B++;
                        }
                    }

                    //* C <-> A 계산
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            if(C[i] < A[j]) C_A++;
                            else if(C[i] == A[j]) continue;
                            else A_C++;
                        }
                    }

                    if(is_non_transitive(A_B, B_A, B_C, C_B, C_A, A_C)) return true;
                }
            }
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;
    while(tc--)
    {
        cout << (solution()?"yes\n":"no\n");
    }
}