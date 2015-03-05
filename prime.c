#include <stdio.h>

int main(int argc, char const *argv[])
{	int arr[100];
	int number, isPrime=1;
	int prime=1;
	int i,end;
	int prime_state;
	scanf("%d",&end);
	arr[0]=2;
	for(number=3; number<end; ++number){
		for(i=0;i<prime;++i){
			if(number%arr[i]==0){
				isPrime=0;
			}
			printf("%d %d %d\n",number, i,arr[i]);
		}
		if(isPrime==1){
			arr[prime] = number;
			prime++;
		}
	}
	printf("\n\nprime %d", prime);		// 2 is also a prime number
	return 0;
}





// int main(){int i=0,divider,b=0;for(; i++<1e6; b++ && printf("%d\n",i)) for(j=2;j<i;) b=i%j++ && b;}	//this also works
		// if((number%2==1) && (number%3!=0) && (number%5!=0)	){
			// prime_state=0;
			// half = number/2;
			// for(divider=7; divider<half; divider++){
			// 	if(number%divider == 0){
			// 		prime_state=1;
			// 	}
			
			// }
		// }	