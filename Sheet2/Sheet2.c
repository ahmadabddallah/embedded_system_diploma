#include <stdio.h>
#include <stdlib.h>

int main()
{
    //1- Write a program that reads the radius of a circle and calculates the area and circumference.
   /*float rad;
   printf("Please enter the radius of the circle \n");
   scanf(" %f",&rad);
   printf("The area of the circle is %f\n",rad*3.14);
    */

    //2-Write a C program to take a number and a character from user if the number is even print the same character, if the number is odd print the other case of the character (a->A, B->b).

    /*int num;
    char alph;
    printf("Please enter the number \n");
    scanf("%d",&num);
    printf("Please enter the character \n",alph);
    scanf(" %c",&alph);
    if(num&1){
            alph-='a';
            alph+='A';
        printf("%c",alph);
    }
    else{
        printf("%c",alph);
    }

    */
    //3-Write a program to reverse a number in decimal representation (1205->5021).

   /* int num;
    scanf("%d",&num);
    while(num>0){
        printf("%d",num%10);
        num/=10;
    }
    */
    //4-Write a program to count the number of 1’s in an unsigned 32-bit integer.
    /*
    int num;
    scanf("%d",&num);
    int ctr=0;
    while(num>0){
            num&=num-1;
            ctr++;

    }
    printf("%d",ctr);
    */

	//5- write a program to print the binary representation of a  number, try not to print zeros on the left (5->print 101).
	/*int x;
    scanf("%d",&x);
    int ctr=0;
     for(int i=8*sizeof(x)-1;i>=0;i--){
        int y;
        y=(x>>i)&1;
        if(y){
                ctr=i;
        break;

        }

     }
	 	
    for(int i=ctr;i>=0;i--){
        int y;
        y=(x>>i)&1;
        if(y){
            printf("1");
        }
        else
            printf("0");

	*/
	
	 //6-Write c code to reverse bits in an 8-bit number 149->10010101 return 169->10101001), 5->00000101 return 160->10100000).
	
	
	/*int x;
    scanf("%d",&x);

    for(int i=0;i<=7;i++){
        int y;
        y=(x>>i&1);
        if(y){
            printf("1");
        }
        else
            printf("0");
    }
    printf("\n");
	*/

    //7- Write c code to sum numbers from 1 to 100 (without loop).
    /*int num;
    printf("Please enter the number \n");
    scanf("%d",&num);
    printf("%d",(num*(num+1))/2);
    */
	
	
	//8-Write a full C program to take 4 choose from user:
	
	//1-Set bit. 
	//2-Clear bit 
	//3-Toggle bit.
	//4-Read bit.
	
		int num;
        int no_bit;
		printf("The set operation now \n");
        printf("Please enter the number you want to do operations on it\n");
        scanf("%d",&num);
        printf("Please enter the bit You wanna set \n");
        scanf("%d",&no_bit);
        num=(1<<no_bit)|num;
        printf("the value after set is %d \n",num);
        printf("\n The clear operation now \n");

		printf("the Clear operation now \n");
        printf("Please enter the number you want to do operations on it\n");
        scanf("%d",&num);
        printf("Please enter the bit You wanna clear \n");
        scanf("%d",&no_bit);
        num=num&~(1<<no_bit);
        printf("the value after clear is %d \n",num);



        printf("\n The Toggle operation now \n");
        printf("Please enter the number you want to do operations on it\n");
        scanf("%d",&num);
        printf("Please enter the bit You wanna Toggle \n");
        scanf("%d",&no_bit);
        num=num^(1<<no_bit);
        printf("the value after toggle is %d \n",num);


        printf("\n The Read operation now \n");
        printf("Please enter the number you want to do operations on it\n");
        scanf("%d",&num);
        printf("Please enter the bit You wanna Read \n");
        scanf("%d",&no_bit);
        int tmp=num;
        tmp=tmp&(1<<no_bit);
        printf("the value is %d \n",tmp);



    //9-Write c function to take number of lines and draw pattern with '*' like:
    //9-1
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            printf("*");
        }
        printf("\n");
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }

    int p=1,q=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==p){
                printf("*");
            }
            else if(j==q){
                printf("*");
            }
            else
            printf(" ");
        }
        p++;
        q--;
        printf("\n");
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=(i*2)-1;j++){
            printf("*");
        }
        printf("\n");
    }
	
	//10-Write c function to count the max number of zeros between two ones in the binary representation of a  number (296384-> {1001000010111000000} return 4)
	
	int num;
    scanf("%d",&num);
    int ctr=0;
    int flag=0;
    int mx=-1;

    int to_stop=0;
    for(int i=0;i<8*sizeof(num);i++){
        int tmp;
        tmp=num&(i<<i);
        if(tmp>=1){
            to_stop=i;
        }


    }


    for(int i=0;i<=to_stop;i++){

        int y;
        y=num&(1<<i);
        if(y>=1){
            ctr=0;
            flag++;
        }
        else if(flag >0 && y==0){
            ctr++;
            if(ctr>mx){
                mx=ctr;
            }
        }


    }
    printf("%d",mx);





	// 11- take a and b and brute force between them to get the maximum value x ored 
	 int a,b;
        scanf("%d%d",&a,&b);
        int mx=-1;
        int tmp=0;
        for(int i=a;i<=b;i++){
            for(int j=i;j<=b;j++){
                tmp=i^j;
                if(tmp>mx){
                    mx=tmp;
                }
            }
        }

        printf("The maximum value is %d",mx);
    }
    return 0;
}
