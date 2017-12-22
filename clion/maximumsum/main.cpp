#include <iostream>
#include <cmath>
using namespace std;

//** Brute Force Solution : O(n3)
int maxSequenceSum_N3(int A[], int n);

//** Brute Force Solution : O(n2)
int maxSequenceSum_N2(int A[], int n);

//** Optimal Solution : O(n)
int maxSequenceSum_N1(int A[], int n);

int main()
{
    srand(946);	// Initialize random seed
    int n=100;
    int A[n];

    for (int i = 0; i < n; i++)
    {
        int sign = pow(-1, (rand() % 2 + 1));
        A[i] = (rand() % 100 + 1) * sign;
    }

    cout << "Brute Force Solution: O(n3) " << maxSequenceSum_N3(A, n) << endl;
    cout << "Better Solution: O(n2) " << maxSequenceSum_N2(A, n) << endl;
    cout << "Optimal Solution: O(n1) " << maxSequenceSum_N1(A, n) << endl << endl;

    system("pause");
    return 0;
}

int maxSequenceSum_N3(int A[], int n)
{
    int currentSum = 0, maxSum = A[0];
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            currentSum = 0;

            for (k = i; k <= j; k++)
                currentSum += A[k];

            if (currentSum > maxSum)
                maxSum = currentSum;
        }
    }
    return maxSum;
}

int maxSequenceSum_N2(int A[], int n)
{
    int currentSum = 0, maxSum = A[0];
    int i, j;

    for (i = 0; i < n; i++)
    {
        currentSum = 0;

        for (j = i; j < n; j++)
        {
            currentSum+=A[j];
            if(currentSum>maxSum){
                maxSum=currentSum;
            }


        }
    }
    return maxSum;
}

int maxSequenceSum_N1(int A[], int n)
{
    int currentSum = 0, maxSum = A[0], positiveTerm=0, negativeTerm=0;

    for (int i = 0; i < n; ++i) {
//        int current=A[i];
        if(A[i]<=0){
            if(negativeTerm+positiveTerm+A[i]<=0){
                positiveTerm=0;
                negativeTerm=0;
                currentSum=0;
                if(A[i]>maxSum) maxSum=A[i];
//                cout<<"test1"<<endl;
                continue;
            }else{
                negativeTerm+=A[i];
                currentSum+=A[i];
                if (currentSum>maxSum){
                    maxSum=currentSum;
                }
//                cout<<"test"<<endl;
            }


            }
        else{
            positiveTerm+=A[i];
            currentSum+=A[i];
            if(currentSum>maxSum){
                maxSum=currentSum;
            }
//            cout<<"test2"<<endl;

        }
    }

    return maxSum;
}