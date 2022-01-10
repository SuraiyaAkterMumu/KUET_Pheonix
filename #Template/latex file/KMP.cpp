int lps[1000007];
 
 void computePrefixFunction(string P)
 {
     int n=SZ(P);
     int k=-1;
     lps[0]=-1;
     for(int i=1;i<n;i++)
     {
         while(k>-1 && P[i]!=P[k+1])
            k=lps[k];
         if(P[i]==P[k+1])
            k++;
         lps[i]=k;
     }
 }
 
 void KMP(string& T, string& P)
 {
     int m=SZ(P);
     int n=SZ(T);
     computePrefixFunction(P);
     int k=-1;
     for(int i=0;i<n;i++)
     {
         while(k>-1 && T[i]!=P[k+1])
            k=lps[k];
         if(T[i]==P[k+1])
            k++;
         if(k==m-1)
         {
             cout<<"Pattern found in position "<<i-k<<endl;
             k=lps[k];
         }
     }
 }
 
int main()
{
    KMP(text,pattarn);

    return 0;
}