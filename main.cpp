#include <iostream>
#include <stack>
using namespace std;
stack<int> S;

int main() {
    int n,k,v[100],ok,i;
    ok=1;
    cin>>n;
    k=1;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];

        while(S.empty()==0&&S.top()==k)
        {k++;
        S.pop();}
        if(v[i]==k)
            k++;
        else {if(S.empty()==0)
            {if(v[i]>S.top())
                    ok=0;
              else S.push(v[i]);

            }
            else S.push(v[i]);
        }


    }
    if(ok==1) cout<<"yes";
    else cout<<"no";
}