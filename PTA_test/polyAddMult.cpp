/**
02-线性结构1 一元多项式的乘法与加法运算

设计函数分别求两个一元多项式的乘积与和。

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数
（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:

输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。
数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:

4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:

15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
**/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Poly {
    int coeff;  //系数
    int exp;    //指数

    Poly(int c, int e) :
        coeff(c), exp(e) {}
};

bool compare(const Poly &x, const Poly &y)
{
    return x.exp > y.exp;
}

vector<Poly> polyMult(const vector<Poly> &A, const vector<Poly> &B)
{

}

vector<Poly> polyAdd(const vector<Poly> &A, const vector<Poly> &B)
{
    vector<Poly> addRes;
    int i = 0, j = 0;

    while(i < A.size() && j < B.size()) {
        int coeff, exp;
        if(A[i].exp == B[j].exp) {
            coeff = A[i].coeff + B[j].coeff;
            exp = A[i].exp;
            ++i; ++j;
        } else if(A[i].exp > B[j].exp) {
            coeff = A[i].coeff;
            exp = A[i++].exp;
        } else {
            coeff = B[j].coeff;
            exp = B[j++].exp;
        }
        addRes.push_back(Poly(coeff, exp));
    }

    while(i != A.size())
        addRes.push_back(A[i++]);
    while(j != B.size())
        addRes.push_back(B[j++]);

    return addRes;
}

void readPoly(vector<Poly> &A, int number)
{
    int coeff, exp;
    for(int i = 0; i != number; ++i) {
        cin >> coeff >> exp;
        A.push_back(Poly(coeff, exp));
    }
}

int main()
{
    int number;
    int coeff, exp;
    vector<Poly> A, B;

    cin >> number;
    readPoly(A, number);
    cin >> number;
    readPoly(B, number);

    auto addRes = polyAdd(A, B);

    return 0;
}
