#include <iostream>
#include <string>

using namespace std;

template<class T>
int sequential_search(T array[], int size, T value);

template<class T>
int binary_searchR(T array[], int first, int last, T value);

template<class T>
int binary_searchNR(T array[], int first, int last, T value);

template<class T>
int fibonacci_search(T array[], int size, T key);

int _fib[] = {
	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144,
	233, 377, 610, 987, 1597, 2584, 4181, 6765,
	10946, 17711, 28657, 46368, 75025, 121393,
	196418, 317811, 514229, 832040, 1346269, 2178309,
	3524578, 5702887, 9227465, 14930352, 24157817,
	39088169, 63245986, 102334155, 165580141,
	267914296, 433494437, 701408733, 1134903170,
	1836311903 };

int main() {

	int list[10];

	for (int k = 0; k < 10; k++)
		list[k] = 2 * k + 1;

	for (int k = 0; k < 10; k++)
	{
		int key = 2 * k + 7;

		cout << "Search for " << key << endl;

		cout << "Sequential search results: " << sequential_search<int>(list, 10, key) << endl;
		cout << "Binary search results (non-recursive): " << binary_searchNR<int>(list, 0, 9, key) << endl;
		cout << "Binary search results (recursive): " << binary_searchR<int>(list, 0, 9, key) << endl;
		cout << "Fibonacci search results: " << fibonacci_search<int>(list, 10, key) << endl;
		cout << endl;
	}

	string names[] = { "abc", "bcd", "cde", "def", "efg", "fgh", "ghi", "hij", "ijk", "jkl" };

	for (int i = 0; i < 5; i++)
	{
		string key = names[i];

		cout << "Search for " << key << endl;

		cout << "Sequential search results: " << sequential_search<string>(names, 10, key) << endl;
		cout << "Binary search results (non-recursive): " << binary_searchNR<string>(names, 0, 9, key) << endl;
		cout << "Binary search results (recursive): " << binary_searchR<string>(names, 0, 9, key) << endl;
		cout << "Fibonacci search results: " << fibonacci_search<string>(names, 10, key) << endl;
		cout << endl;
	}

	system("pause");
	return 0;
}


// time complexity = O(n)
template<class T>
int sequential_search(T array[], int size, T value)
{
    for (int i = 0; i < size; ++i) {
        if (array[i]==value) return i;
// searching through every element.
    }

	return -1;
}


// when key > array[index] and offset+=F(n-2), 1/3 of the array is discarded since F(n-2) ≈ (1/3)*F(n). When n--, F[n] is will be the smallest number in Fibonacci series that is greater than the length of the new array.
// when key < array[index] 1/3 of the array is discarded since F[n] decreases to one third.
// Time complexity is O(log(n))
template<class T>
int fibonacci_search(T array[], int size, T key)
{   int i = 0;
    for (; _fib[i]<size; ++i) {}

    int offset=-1;
    while(_fib[i]>0){
        int index= _fib[i-2]+offset;
        if(index>size) index=size;

        if (array[index]==key) return index;
        else if(array[index]<key) {
//            cout<<array[index]<<" smaller " <<index<<"  "<<key<<"  "<<_fib[i-2]<<endl;
            offset+=_fib[i-2];
            i--;

        }else if(array[index]>key) {
//            cout<<array[index]<<" bigger " <<index<<"  "<<key<<"  "<<_fib[i-2]<<endl;
            i-=2;
        }

    }

	// *** Place your code here ***

	return -1;
}


//When array[i] is greater or smaller than the key, half of the remaining array is discarded.
//time complexity = O(log(n))
template<class T>
int binary_searchR(T array[], int first, int last, T key)

{
    if(first>last) return -1;
    int middle = (last+first)/2;
    if (array[middle]==key) return middle;
	else if(key>array[middle]) return binary_searchR(array,middle+1,last,key);
    else if(key<array[middle]) return binary_searchR(array,first,middle-1,key);




}

template<class T>
int binary_searchNR(T array[], int first, int last, T key)
{
    while(last>=first){
        int middle = (last+first)/2;
        if (array[middle]==key) return middle;
        else if(key>array[middle]) {
            first=middle+1;
//            cout<<first<<"  "<<last<<endl;
        }
        else if(key<array[middle]) {
            last=middle-1;
//            cout<<first<<"  "<<last<<endl;
        }
    }


	return -1;
}