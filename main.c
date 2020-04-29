#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void railFence(char *msg, char *cipherText, int length, int rails);

int main(){

int rails;
int length;
char msg[1000];
char cipherText[1000];

printf("Enter Message: ");
scanf("%[^\n]%*c", msg);



printf("Enter Rails: ");
scanf("%d", &rails);
length = strlen(msg);



railFence(msg, cipherText, length, rails);
}

void railFence(char *msg, char *cipherText, int length, int rails)
{

    int i, j, count;
    int matrixarray[100][1000];
    printf("%d\n", length);

for(i=0; i<rails; i++)
{
    for(j=0; j<length;j++)
    {
        matrixarray[i][j]=0;
    }
}
count = 0;
j = 0;
while(j<length)
{
    if(count%2==0)
    {
        for(i=0; i<rails;i++)
        {
            matrixarray[i][j] = (int)msg[j];
            j++;
        }
    }
    else
    {
        for(i=rails-2; i>0; i--)
        {
            matrixarray[i][j] = (int)msg[j];
            j++;
        }
    }
count ++;
}
for(i=0; i<rails;i++)
{
    for(j=0;j<length;j++)
    {
        if(matrixarray[i][j] != 0) {
            *cipherText = matrixarray[i][j];
            printf("%c", *cipherText); }
    }
}
printf("\n");

}
