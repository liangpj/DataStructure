/**
01-复杂度2 Maximum Subsequence Sum
Given a sequence of K integers {N1,N2, ...,Nk}. A continuous subsequence is defined to be
{Ni, Ni+1, ..., Nj} where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence
which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 },
its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a
positive integer K (≤10000).second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the
maximum subsequence. The numbers must be separated by one space, but there must be no extra space
at the end of a line. In case that the maximum subsequence is not unique, output the one with
the smallest indices i and j (as shown by the sample case). If all the K numbers are negative,
then its maximum sum is defined to be 0, and you are supposed to output the first and the last
numbers of the whole sequence.

Sample Input:

10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:

10 1 4
**/

#include<iostream>
#include<vector>
using namespace std;

/***
* 使用分治法求解最大子序列
**/
vector<int> findCrossMaxSubseqSum(vector<int> A, int low, int mid, int high)
{
    int leftIndex = mid, righIndex = mid + 1;
    int sum = 0;
    int leftMaxSum = A[mid], rightMaxSum = A[mid+1];

    for(int i = mid; i >= low; --i){
        sum += A[i];
        if(sum > leftMaxSum) {
            leftIndex = i;
            leftMaxSum = sum;
        }
    }

    sum = 0;
    for(int i = mid + 1; i <= high; ++i){
        sum += A[i];
        if(sum > rightMaxSum) {
            righIndex = i;
            rightMaxSum = sum;
        }
    }

    return {leftIndex, righIndex, leftMaxSum + rightMaxSum};
}

vector<int> maxSubseqSum(vector<int> A, int low, int high)
{
    if(low == high)
        return {low, high, A[low]};
    else {
        int mid = (low + high) / 2;
        auto leftRes = maxSubseqSum(A, low, mid);
        auto rightRes = maxSubseqSum(A, mid+1, high);
        auto crossRes = findCrossMaxSubseqSum(A, low, mid, high);

        if(leftRes[2] >= rightRes[2] && leftRes[2] >= crossRes[2])
            return leftRes;
        else if(rightRes[2] >= leftRes[2] && rightRes[2] >= crossRes[2])
            return rightRes;
        else
            return crossRes;
    }
}

vector<int> maxSubseqSum(vector<int> A)
{
    return maxSubseqSum(A, 0, A.size()-1);
}

int main_02()
{
    //vector<int> A{-10,1, 2 ,3 ,4 ,-5, -23, 3 ,7 ,-21};
    int k;
    vector<int> A;
    bool flag = true;

    cin >> k;
    if(k > 10000) {
        cout << 0 << " " << 0 << " " << 0 << endl;
        return 0;
    }
    for(int i = 0; i != k; ++i) {
        int number;
        cin >> number;
        if(flag && number >= 0)
            flag = false;
        A.push_back(number);
    }


    if(flag) { //全部都是负数
        cout << 0 << " " << A[0] << " " << A[A.size()-1] << endl;
    }
    else {
        auto res = maxSubseqSum(A);
        cout << res[2] << " " << A[res[0]] << " " << A[res[1]] << endl;;
    }

    return 0;
}
