/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode **dui;
int lenght;
void add(struct ListNode *);
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	struct ListNode *root=NULL;
	dui=(struct ListNode **)malloc(sizeof(struct ListNode*)*(listsSize+1));
    lenght=0;
	for(int i=0; i<listsSize; i++)
		if(lists[i]!=NULL) add(lists[i]);
    if(lenght==0)return root;
	root=dui[1];
	struct ListNode *x=root;
	struct ListNode *w;
	int i=1,min=0;
	while(lenght>1) {
		i=1;
		if(dui[1]->next!=NULL) {
			dui[1]=dui[1]->next;
		} else {
			dui[1]=dui[lenght--];
		}
		while(i*2<=lenght) {
			if(dui[i*2]->val<dui[i]->val)
				min=i*2;
			else min=i;
			if(i*2<lenght&&dui[min]->val>dui[i*2+1]->val)
				min=i*2+1;
			if(min!=i) {
				w=dui[i];
				dui[i]=dui[min];
				dui[min]=w;
				i=min;
			} else i=lenght;
		}
		x->next=dui[1];
		x=x->next;
	}
	return root;
}
void add(struct ListNode *l) {
	struct ListNode *w;
	dui[++lenght]=l;
	int q=lenght;
	while(q!=1) {
		if(dui[q]->val<dui[q/2]->val) {
			w=dui[q/2];
			dui[q/2]=dui[q];
			dui[q]=w;
			q=q/2;
		} else q=1;
	}
}
