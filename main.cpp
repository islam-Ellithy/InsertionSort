#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


void print(vector<int>&v)
{
    for(auto i : v)
    {
        cout << i << ' ' ;
    }
    cout << '\n';
}

int Binary_Search(vector<int>&v,int start, int last,int target)
{
    int mid = (start+last)/2 ;

    if(start>=last)
    {
        return ((v[start]>target)?start:(start+1));// 2 4(low) 5(start) (7)
    }
    if(v[mid]==target)
    {
        return mid ;
    }
    else if(v[mid]>target)
    {
        return Binary_Search(v,start,mid-1,target);
    }
    else
    {
        return Binary_Search(v,mid+1,last,target);
    }
}

void Insertion_Sort(vector<int> &arr) // complixity
{
    int i , high , mid , target , index  ;
    for(i = 1 ; i<arr.size(); ++i) // O(n)
    {
        target = arr[i];
        index = Binary_Search(arr,0,i-1,target);// O(log(n))
        for(int j = i ; j>index ; j--) // O(index-i) discarded
        {
            arr[j]=arr[j-1];
        }
        swap(target,arr[index]);
        // O(log(n))*O(n) = O(n*log(n))
    }
}


void setvector(vector<int>&v,int sz)
{
    int x ;
    for(int i = 0 ; i<sz; i++)
    {
        x = rand()%sz + 1;
        v.push_back(x);
    }
}



int x = 0;
void doit(int n )
{
    if (n <= 1) return;
    for (int i = 0; i < n; i++)
        x = x + 1;
    doit(n/2);
    doit(n/2);
}

//16+2*(8 + 4 + 2)
//n + 2*log(n)

int main()
{
    vector<int> v;

    setvector(v,10);
    vector<int> v2(v);


    print(v);

    clock_t t1 = clock();

    Insertion_Sort(v);


    clock_t t2 = clock();
    
    cout << t1 << '\t' << t2 << '\t' << double(t2-t1)/CLOCKS_PER_SEC << '\n' ;
    
    print(v);

    Insertion_Sort2(v2);
    print(v2) ;

    return 0;
}
