#include <stdio.h>
#include <stdlib.h>
 struct node{
             int CO,PO;
             struct node*addr;
             };
typedef struct node *NODE;

NODE insert(NODE start,int CO, int PO){
NODE temp,cur;
temp = (NODE)malloc(sizeof(struct node));
temp -> CO = CO;
temp -> PO = PO;
temp -> addr = NULL;
if(start == NULL){
    return temp;
}
cur = start;
while(cur -> addr!= NULL){
    cur = cur -> addr;
}
cur -> addr = temp;
return start;
}

void display(NODE start){
NODE temp;
if(start== NULL){
    printf("\n Polynomial empty");
    }
else{
    temp= start;
    while(temp -> addr != NULL){
    printf("%d*x^%d",temp -> CO,temp -> PO);
    temp = temp -> addr;
        }
    printf("%d*x^%d",temp -> CO,temp -> PO);
}
}
NODE addterm(NODE res,int CO,int PO){
    NODE temp,cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp -> CO = CO;
    temp -> PO = PO;
    temp -> addr = NULL;
    if(res== NULL){
    return temp;}
cur = res;
while(cur!= NULL){
if(cur -> PO==PO){
        cur -> CO = (cur -> CO)+CO;
        return res;}
    cur = cur-> addr;
}
    res=insert(res,CO,PO);
    return res;
}
 NODE multiply(NODE poly1, NODE poly2){
    NODE p1, p2, res = NULL;
    for(p1 = poly1; p1 != NULL; p1 = p1 -> addr){
    for(p2 = poly2; p2 != NULL; p2 = p2 -> addr){
    res = addterm(res, p1 -> CO * p2 -> CO, p1 -> PO + p2 -> PO);
        }
    }
    return res;
}

int main(){
    NODE poly1 = NULL, poly2 = NULL,poly;
    int n1, CO, PO;
    int i,n;
    printf("Enter number of terms of 1st polynomial");
    scanf("%d", &n1);
    for(i = 0; i < n1; i++){
        printf("Read co & po of %d term:", i + 1);
        scanf("%d%d", &CO, &PO);
        poly1 = insert(poly1, CO, PO);
    }
    printf("1st polynomial is\n");
    display(poly1);


printf("\n Enter number of terms of 2nd poly");
scanf("%d", &n);


for(i = 0; i < n; i++){
    printf("Read co & po of %d term:", i + 1);
    scanf("%d%d", &CO, &PO);
    poly2 = insert(poly2, CO, PO);
}
printf("2nd polynomial is\n");
display(poly2);

poly = multiply(poly1, poly2);
printf("Resultant polynomial is\n");
display(poly);

return 0;
}


