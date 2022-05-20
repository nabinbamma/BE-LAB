#include<stdio.h>
#include<conio.h>
main(){
	int buffer[10],bufsize,in,out,produce,consume,choice=0;
	in=0;
	out=0;
	bufsize=10;
	while(choice!=3){
		printf("\n 1.Produce\t 2.Consume\t 3.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				if((in+1)%bufsize==0){
					printf("Buffer is FUll");
				}
				else{
					printf("\n Enter the value:");
					scanf("%d",&produce);
					buffer[in]=produce;
					in=(in+1)%bufsize;
				}
				break;
				case 2:
					if(in==out){
						printf("\n Buffer is empty");
					}
					else{
						consume=buffer[out];
						printf("\n The consume value is %d.",consume);
						out=(out+1)%bufsize;
					}
					break;
		}
	}
	getch();
	return 0;
}
