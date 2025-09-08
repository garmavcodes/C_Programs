#include <stdio.h>

int main()
{
	int n,is_sym=1;
	printf("enter the  size of  matrix:\n");
	scanf("%d",&n); // read matrix size
	
	
	int arr1[n][n];
	printf("enter the values of  matrix\n");
	for(int i=0; i<n; i++) {
	    for(int j=0;j<n;j++){
	        scanf("%d",&arr1[i][j]); // read matrix elements
	        
	    }

		

	}
	
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        if(arr1[j][i]!=arr1[i][j]){
	            is_sym=0; // set flag if not symmetric
	            break;
	            
	        }
	        
	    }if(is_sym==0){
	        break;
	    }
	}
	

	
	
	if (is_sym==1){
	    printf("matrix is symmetric"); // symmetric
	}
	else{
	    printf("it is not symmetric"); // not symmetric
	}
	
}