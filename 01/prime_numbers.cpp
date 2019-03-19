#include "numbers.dat"
#include<iostream>
#include<vector>

const size_t ArraySize=100000;
using namespace std;
vector <bool> primeNumbers(size_t n);
int simpleSearchForward (const int* Data, int start, int finish, int key);
int simpleSearchBackward (const int* Data, int start, int finish, int key);
int main(int argc, char* argv[])
{
    if(argc % 2 == 0 || argc == 1)
        return -1;
    vector <bool> prime = primeNumbers(ArraySize);
    int count = 0;
    for(int j = 1; j < argc; j += 2)
    {
        int start = atoi(argv[j]);
        int finish = atoi(argv[j + 1]);
        int from = simpleSearchForward(Data,0,Size,start);
        int to = simpleSearchBackward(Data,Size,0,finish);
        if(to == -1 || from == -1)
        {
            cout<< "0";
            return 0;
        }
        for(int i = from; i <= to; ++i)
        {
            if(prime[Data[i]])
                count ++;
        }
        cout << count << endl;
        count = 0;
    }
    return 0;
}
vector <bool> primeNumbers(size_t n)
{
    vector <bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= n; ++i)
    {
        if(prime[i])
        {
            for(int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    return prime;
}
int simpleSearchForward (const int* Data, int start, int finish, int key)
{
    for(int i = start; i < finish; ++i)
    {
        if(key == Data[i])
        {
            return i;
        }
    }
    return -1;
}
int simpleSearchBackward (const int* Data, int start, int finish, int key)
{
    for(int i = start-1; i >= finish; --i)
    {
        if(key == Data[i])
        {
            return i;
        }
    }
    return -1;
}
