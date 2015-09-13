/**
01-复杂度1 最大子列和问题
给定K个整数组成的序列{N1,N2,...,Nk}，“连续子列”被定义为{Ni, Ni+1,...,Nj}，
其中 1≤i≤j≤K。“最大子列和”则被定义为所有连续子列元素的和中最大者。
例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。
现要求你编写程序，计算给定整数序列的最大子列和。

输入格式:

输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。

输出格式:
在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

输入样例:

6
-2 11 -4 13 -5 -2
输出样例:
20
**/

#include<iostream>
#include<vector>

using namespace std;

/**
最大子序列求和，在线算法
**/
int maxSubSum(const vector<int> &A)
{
    int thisSum = 0, maxSum = 0;
    for(int i = 0; i != A.size(); ++i)
    {
        thisSum += A[i];
        if(thisSum > maxSum)
            maxSum = thisSum;
        else if(thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}

int main_01()
{
    int k ;
    vector<int> A;
    bool flag = true;

    cin >> k;
    for (int i = 0; i != k; ++i)
    {
        int number;
        cin >> number;
        if(flag && number > 0)
            flag = false;
        A.push_back(number);
    }
    if(flag)
        cout << 0 << endl;  //如果所有的数都为负数
    else
        cout << maxSubSum(A) << endl;
    return 0;
}
