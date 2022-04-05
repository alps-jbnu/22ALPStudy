#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    double a, b, c;
    cin >> a >> b >> c;

    double discr = b * b - 4 * a * c;
    //* 서로 다른 두 실근
    if(discr > 0)
    {
        double sq = sqrt(discr);
        //* 유리수근이 아닐 경우
        if(sq != trunc(sq)) cout << "둘다틀렸근";
        //* 정수
        else
        {
            double root1 = (-b + sq) / (2 * a);
            double root2 = (-b - sq) / (2 * a);
            // cout << root1 << ", " << root2 << "\n";

            double l1 = log2(root1);
            double l2 = log2(root2);
            // cout << l1 << ", " << l2 << "\n";

            //* 이수근
            if(l1 == trunc(l1) && l2 == trunc(l2) && l1 > 0 && l2 > 0) cout << "이수근";
            //* 둘다 정수
            else if(root1 == trunc(root1) && root2 == trunc(root2)) cout << "정수근";
            //* 나머지
            else cout << "둘다틀렸근";
        }
    }
    //* 중근이거나 허근
    else cout << "둘다틀렸근";
}