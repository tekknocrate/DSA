#include <iostream>


using namespace std;

void MaxSumPrefixMethod(int a[], int n){
    int prefix[100]={};
    prefix[0] = a[0];
    for( int i=1 ;i<n;i++)
   { prefix[i]=prefix[i-1] + a[i];}
    
    for ( int i=0;i<n;i++)
        cout<<"i="<<i<<" & "<<prefix[i]<<"-----";
    
    
    int largestsum=0;
    for(int i=0;i <n ;i++){
       for (int j=i;j<n;j++){ // j=i+1 for no repeat pairs
           int subasum= i>0? prefix[j]-prefix[i-1] : prefix[j];
           
           largestsum = max(subasum,largestsum);
        }
        
    }
    cout<<"Largest Sum:"<<largestsum<<endl;
}
void PrintAllPairs(int a[], int n){
    int largestsum=0;
    for(int i=0;i <n ;i++){
       for (int j=i;j<n;j++){ // j=i+1 for no repeat pairs
           int subasum=0;
           for ( int k=i;k<=j;k++){
               subasum+= a[k];
           }
           largestsum = max(subasum,largestsum);
        }
        
    }
        cout<<"Largest Sum:"<<largestsum<<endl;
}

int main(){

int arr[]= {-2,3,4,-1,5,-12,6,1,3};
int sz= sizeof(arr)/sizeof(arr[0]);
for(int x: arr ){
    cout<<x<<endl;
}
cout<<"Print all possible pairs:"<<endl;
PrintAllPairs(arr,sz);
MaxSumPrefixMethod(arr,sz);

    return 0;
}
