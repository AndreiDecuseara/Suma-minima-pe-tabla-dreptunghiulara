#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

ifstream f("date1.in");

int main()
{
   int n,m,x;
   f>>n;
   f>>m;
   cout<<n<<' '<<m<<endl;
   vector< vector<int> > v;
   vector< int > aux1;

   int aux[n][m];

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      aux[i][j]=0;

   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           f>>x;
           aux1.push_back(x);

           if(i==n-1)
           aux[i][j]=x;



       }
       v.push_back(aux1);
       aux1.erase(aux1.begin(),aux1.end());
   }


    for(int i=n-2;i>=0;i--)
        for(int j=0;j<m;j++)
            aux[i][j]+=v[i+1][j]+v[i][j];

    int sumaMinima=v[0][0];
    int indI=0,indJ=0;
    cout<<"(1,1) ";
    while(indI!=n-1 && indJ!=m-1)
        {
        int mini=10000;
        int a=0;
        for(int j=0;j<m;j++)
        {
            if(mini>aux[indI][j]  && j!=indJ) {mini=aux[indI][j];a=j;}
        }
        indJ=a;
        if(indI!=n-1)
            sumaMinima+=v[indI][indJ]+v[indI+1][indJ];
        else sumaMinima+=v[indI][indJ];
        cout<<'('<<indI+1<<','<<indJ+1<<')'<<' ';
        cout<<'('<<indI+2<<','<<indJ+1<<')'<<' ';
        if(indI!=n-1)
            indI++;
        }
    if(indI==n-1 && indJ!=m-1)
    {
       sumaMinima+=v[n-1][m-1];
       cout<<'('<<indI+1<<','<<m<<')'<<' ';
    }

        cout<<endl<<"Suma minima este: "<<sumaMinima;











return 0;
}
