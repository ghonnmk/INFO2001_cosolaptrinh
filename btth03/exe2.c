#include<stdio.h>
int main()
{
	float a;
	printf("nhap so diem : ");
	scanf("%f",&a);
	if(a<=10&&a>=0)
		if(a>=9)
		printf("hoc sinh xuat sac");
			else if(a>=8)
			printf("hoc sinh gioi");
					else if(a>=6.5)
				printf("hoc sinh kha");
						else if(a>=5)
							printf("hoc sinh trung binh");
								else
								printf("hoc sinh yeu");
    return 0;	
}
