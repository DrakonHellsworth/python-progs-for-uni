#include<iostream>
using namespace std;
void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
void print2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    } 
}
void print3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    } 
}
void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    } 
}
void print5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n+1-i); j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    } 
}
void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n+1-i); j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    } 
}
void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= (n-i-2); j++)
        {
            cout<<" ";
        }
        for (int j = 0; j < (2*i+1); j++)
        {
            cout<<"*";
        }
        for (int j = 0; j <= (n-i-2); j++)
        {
            cout<<" ";
        }
        cout<<endl;
    } 
}
void print8(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i-1; j++)
        {
            cout<<" ";
        }
        for (int j = 1; j <= (2*(n-i)+1); j++)
        {
            cout<<"*";
        }
        for (int j = 1; j <= i-1; j++)
        {
            cout<<" ";
        }
        cout<<endl;
    } 
}
void print9(int n)
{
    for (int i=1; i<=2*n-1; i++ )
    {
        int stars=i;
        if (i>n)
        stars=2*n-i;
        for (int j=1 ; j<=stars ; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
void print10(int n)
{
    int start=1;
    for (int i = 0; i < n; i++)
    {
       if (i%2==0)
       {
        start=1;
       }
       else
       start=0;
       for (int j = 0; j <= i; j++)
       {
        cout<<start<<" ";
        start=1-start;
       }
       cout<<endl;
    }
}
void print11(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<j;
        }
        for (int j = 1; j <= 2*(n-i); j++)
        {
            cout<<" ";
        }
        for (int j = i; j > 0; j--)
        {
            cout<<j;
        }
        cout<<endl;
    }
}
void print12(int n)
{
    int a=1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<a<<" ";
            a++;
        }
        cout<<endl;
    }
}
void print13(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch='A'; ch<='A'+i; ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
void print14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch='A'; ch<='A'+i; ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
void print15(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch='A'+i;
        for (int j=0; j<=i; j++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
void print16(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            cout<<" ";
        }
        char ch='A';
        int bp=(2*i+1)/2;
        for (int j = 1; j <=2*i+1 ; j++)
        {
            cout<<ch;
            if (j<=bp) ch++;
            else ch--;
        }
        for (int j = 0; j < n-i-1; j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}
void print17(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch='E'-i; ch<='E'; ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
void print18(int n)
{
    for (int i = 0; i < 2*n; i++)
    {
        if (i<n)
        {
            for (int j = 0; j < (n-i); j++)
            {
                cout<<"*";
            }
            for (int j = 0; j < 2*i; j++)
            {
                cout<<" ";
            }
            for (int j = 0; j < n-i; j++)
            {
                cout<<"*";
            } 
        }
        else
        {
            for (int j = 0; j < i-n+1; j++)
            {
                cout<<"*";
            }
            for (int j = 0; j < 2*(2*n-i-1); j++)
            {
                cout<<" ";
            }
            for (int j = 0; j < i-n+1; j++)
            {
                cout<<"*";
            }
        }
        cout<<endl;
    } 
}
void print19(int n)
{
    for (int i = 0; i < 2*n-1; i++)
    {
        if (i<n)
        {
            for (int j = 0; j <= i; j++)
            {
                cout<<"*";
            }
            for (int j = 0; j < 2*(n-i-1); j++)
            {
                cout<<" ";
            }
            for (int j = 0; j <= i; j++)
            {
                cout<<"*";
            }
        }
        else
        {
            for (int j = 0; j < 2*n-i-1; j++)
            {
                cout<<"*";
            }
            for (int j = 0; j < 2*(i-n+1); j++)
            {
                cout<<" ";
            }
            for (int j = 0; j < 2*n-i-1; j++)
            {
                cout<<"*";
            } 
        }
        cout<<endl;
    }
}
void print20(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i==0||i==n-1)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<"*";
            }
        }
        else
        {
            cout<<"*";
            for (int j = 0; j < n-2; j++)
            {
                cout<<" ";
            }
            cout<<"*";
        }
        cout<<endl;
    }
}
void print21(int n)
{
    for (int i = 0; i < 2*n-1; i++)
    {
        for (int j = 0; j < 2*n-1; j++)
        {
            int top=i;
            int left=j;
            int bottom=2*n-2-i;
            int right=2*n-2-j;
            cout<<n-min(min(top, bottom), min(left, right))<<" ";
        }
        cout<<endl;
    }
}
void print22(int n)
{
    int e=2, o=1;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i % 2 != 0)
            {
                cout << o << " ";
                o += 2;
            }
            else
            {
                cout << e << " ";
                e += 2;
            }
        }
        cout<<endl;  
    }
}
void print23(int m)
{
    int k=65, n=1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if(i%2!=0)
            {
                if(i>1)
                n=n+1;
                    if(n%2==0)
                    {
                    cout<<(char)(k+32);
                    }
                    else
                    {
                    cout<<(char)k;
                    }
                n=n+1;
                k=k+1;
            }
            else
            {
                if(n%2==0)
                {
                    cout<<(char)(k+32);
                }
                else
                {
                    cout<<(char)(k);
                }
                n=n+1;
                k=k+1;
            }
        }
        cout<<endl;
    } 
}
int main()
{
    int t;
    cout<< "enter number of times want to run loop: ";
    cin>>t;
    for ( int i=0; i<t; i++ )
    {
        int n;
        cout<<"\nenter the number of the rows and columns: ";
        cin>>n;
        print23(n);
    }
    return 0;
}