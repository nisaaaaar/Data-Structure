#include<stdio.h>

int main(){
int a[] = {9,5,3,8,2};int key,i=0,j;

for (i = 0; i < 5; ++i)
{
	printf("%d\t",a[i]);
}

printf("\n");
for (i = 1; i < 5; i++)
{
	key = a[i];
	j=i-1;
	while(j>=0 && a[j]>key){
		a[j+1] = a[j];
		j--;
	}
	a[j+1] = key;
}
for (i = 0; i < 5; i++)
{
	printf("%d\t",a[i]);
}


return 0;

}