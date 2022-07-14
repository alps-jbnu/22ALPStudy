#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 2e9;


class Token
{
private:
    bool _isOp;
    optional<char> _op;
    optional<int> _num;

public:
    explicit Token(char ch) : _isOp(true), _op(ch) {}
    explicit Token(int num) : _isOp(false), _num(num) {}
    explicit Token(const Token& n1, const Token& op, const Token& n2) : _isOp(false)
    {
        assert(op._isOp);
        switch (*op._op)
        {
        case '+':
            _num = *n1._num + *n2._num;
            break;
        case '-':
            _num = *n1._num - *n2._num;
            break;
        case '*':
            _num = *n1._num * *n2._num;
            break;
        case '/':
            _num = *n1._num / *n2._num;
            break;
        default:
            assert(false);
        }
    }

    bool isOp() const { return _isOp; }
    int getNum() const { assert(!_isOp); return *_num; }
    char getOp() const { assert(_isOp); return *_op; }
    int getOpPriority() const
    {
        assert(_isOp);
        switch (*_op)
        {
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
        }
        assert(false);
        return -1;
    }
};

Token getOp(int idx)
{
    switch (idx)
    {
    case 0:
        return Token('+');
    case 1:
        return Token('-');
    case 2:
        return Token('*');
    case 3:
        return Token('/');
    }
    assert(false);
    return Token(' ');
}

// 2. 후위 표기식 계산
int calcExp(const vector<Token>& exp)
{
    stack<Token> numSt;
    for (const Token& t : exp)
    {
        if (t.isOp())
        {
            assert(numSt.size() >= 2);
            Token n2 = numSt.top();
            numSt.pop();
            Token n1 = numSt.top();
            numSt.pop();
            
            numSt.push(Token(n1, t, n2));
        }
        else // t is num
        {
            numSt.push(t);
        }
    }
    assert(numSt.size() == 1);
    return numSt.top().getNum();
}

// 1. 후위 표기식 생성
auto genExp(const vector<Token>& A, const vector<Token>& ops) -> vector<Token> 
{
    const int N = A.size();
    vector<Token> result;
    result.reserve(2*N-1);
    result.push_back(A[0]);

    stack<Token> opSt;
    for (int i=0;i<N-1;++i)
    {
        const auto& op = ops[i];
        const auto& num = A[i+1];

        while (!opSt.empty() && opSt.top().getOpPriority() >= op.getOpPriority())
        {
            result.push_back(opSt.top());
            opSt.pop();
        }
        opSt.push(op);
        
        result.push_back(num);
    }

    while (!opSt.empty())
    {
        result.push_back(opSt.top());
        opSt.pop();
    }

    return result;
}

int calcExp(const vector<Token>& A, const vector<Token>& ops)
{
    // 1. 후위 표기식 생성
    auto exp = genExp(A, ops);
    // 2. 후위 표기식 계산
    return calcExp(exp);
}

void backtrack(array<int,4>& remainOps, vector<Token>& opOrders, const vector<Token>& A, pair<int,int>& result)
{
    if (opOrders.size() == A.size()-1)
    {
        const int val = calcExp(A, opOrders);
        result.first = min(result.first, val);
        result.second = max(result.second, val);
        return;
    }

    for (int i=0;i<4;++i)
    {
        if (remainOps[i] > 0)
        {
            --remainOps[i];
            opOrders.push_back(getOp(i));
            backtrack(remainOps, opOrders, A, result);
            opOrders.pop_back();
            ++remainOps[i];
        }
    }
}

// return: {min, max}
auto getAnswer(const vector<int>& A, array<int,4>& asmd) -> pair<int,int> 
{
    const int N = A.size();
    vector<Token> tA; tA.reserve(N);
    transform(A.begin(), A.end(), back_inserter(tA), [] (int a) { return Token(a); });
    pair<int,int> result = {INF, -INF};
    vector<Token> opOrders;
    opOrders.reserve(N-1);
    backtrack(asmd, opOrders, tA, result);
    return result;
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;  cin>>N;
    vector<int> A(N);
    array<int,4> ops;
    for (auto& a : A)
        cin >> a;
    for (auto& op : ops)
        cin >> op;
    
    auto [m, M] = getAnswer(A, ops);
    cout << M << '\n' << m;
}
