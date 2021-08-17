#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;
  struct ListNode {
      int val;
      struct ListNode *next;
  };



struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode *right=head,*z=head->next,*n,*p=head,*ro=right,*right2;
	int i=k-1;
    int a=0;
	while(1) {
		while(i>0) {
			n=z->next;
			z->next=p;
			p=z;
            z=n;
			--i;
            if(n==NULL)break;
		}
		if(i>0){
			i=k-i-1;
            a=k;
			z=p->next;
            p->next=NULL;
		    continue;
		}
		if(right==head){
            ro=p;
            head=NULL;
            right2=z;
        }else{
            right->next=p;
            right=right2;
            right2=z;    
        }		
        if(a==k){
            break;
        }
        if(z==NULL){
		   right->next=NULL;
            break;
        }
		i=k;
	}
	return ro;
}
int main(){
	struct ListNode *h=(struct ListNode *)malloc(sizeof(struct ListNode ));
	struct ListNode *h1=(struct ListNode *)malloc(sizeof(struct ListNode ));
	struct ListNode *h2=(struct ListNode *)malloc(sizeof(struct ListNode ));
	struct ListNode *h3=(struct ListNode *)malloc(sizeof(struct ListNode ));
	struct ListNode *h4=(struct ListNode *)malloc(sizeof(struct ListNode ));
	h->next=h1;
	h1->next=h2;
	h2->next=h3;
	h3->next=h4;
	h->val=1;
	h1->val=2;
	h2->val=3;
	h3->val=4;
	h4->val=5;
	h4->next=NULL;
	h= reverseKGroup(h, 2);
	 while(h->next!=NULL){
	 	h=h->next;
		cout<<h->val; }
}
