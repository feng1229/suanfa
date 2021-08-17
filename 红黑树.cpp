#include<iostream>
using namespace std;

class Tree;
Tree *NIL;
Tree *head;
string BLACK="BLACK";
string RED="RED";
class Tree{
	public :
		Tree *p;
		Tree *left;
		Tree *right;
		int key;
	    string cloor;

		Tree(){
			p=NULL;
			left=NULL;
			right=NULL;
			key=0;
			cloor=BLACK;
		}
		Tree(int k){
			p=NULL;
			left=NIL;
			right=NIL;
			key=k;
			cloor=RED;
		}

	
		void adjust(Tree *a){//添加节点时维护红黑树 
			while(a->p->cloor!=BLACK){
				Tree *shu=NULL;
			    bool shu_right=false;
			    if(a->p->p->left==a->p){
			    	shu=a->p->p->right;
				    shu_right=true;
				} else 
			        shu=a->p->p->left;
			    if(shu->cloor==RED){//叔为红 
				    a->p->p->cloor=RED;
				    a->p->cloor=BLACK;
				    shu->cloor=BLACK;
				    a=a->p->p;
			   }else {			   	
				    if(!shu_right){
					    if(a->p->left==a){
						    rightRevolve(a->p);
						    leftRevolve(a->p);
					    	a->cloor=BLACK;
					    	a->left->cloor=RED;
					    } else{
					    	leftRevolve(a->p->p);
					    	a->p->cloor=BLACK;
					    	a->p->left->cloor=RED;
					    	a=a->p;
					    }
			    	}else{
					    if(a->p->right==a){
					    	leftRevolve(a->p);
					    	rightRevolve(a->p);
					    	a->cloor=BLACK;
					    	a->right->cloor=RED;
					    }else{
					    	rightRevolve(a->p->p);
					    	a->p->cloor=BLACK;
					    	a->p->right->cloor=RED;
					    	a=a->p;
				    	}
			    	}	
		    	}
		    	if(a->p==NIL){
		    		head=a;
		    		head->cloor=BLACK;
		    	}
		    	if(a->cloor==BLACK)return;
		   	}
		}
		
		void delete_tree(Tree *z) {
			Tree *x=NULL;
			Tree *y=z;
			string c=y->cloor;
			if(z->left==NIL){
				x=z->right;
				dingti(z,x);
			} else if(z->right==NIL){
					x=z->left;
					dingti(z,x);
				} else{
					y=hou(z);
					c=y->cloor;
					x=y->right;
					if(y==z->right){
						y->left=z->left;
						z->left->p=y; 
						y->cloor=z->cloor;
						dingti(z,y);
					} else {
						dingti(y,y->right);
						
						y->left=z->left;
						y->right=z->right;
						y->cloor=z->cloor;
						z->right->p=y;
						z->left->p=y;
						dingti(z,y);
					}
				}
			if(c==BLACK) deleteAdjust(x);	
		}
		
		void deleteAdjust(Tree *x){
			Tree *w=NULL;
			while(x!=head&&x->cloor==BLACK){
				if(x->p->left==x){//兄在右 
					w=x->p->right;
					if(w->cloor==RED){
						x->p->cloor=RED;
						w->cloor=BLACK;
						leftRevolve(x->p);
						w=x->p->right; 
					}
					if(w->right->cloor==BLACK&&w->left->cloor==BLACK){
						w->cloor=RED;
						x=x->p;
					} else {
						if(w->right->cloor==BLACK){
							rightRevolve(w);
							w->cloor=RED;
							w->p->cloor=BLACK;
							w=w->p;
						}
						leftRevolve(x->p);
						w->cloor=x->p->cloor;
						x->p->cloor=BLACK;
						w->right->cloor=BLACK;
						x=head;
					}
				} else {//兄在左 
					w=x->p->left;
					if(w->cloor==RED){
						rightRevolve(x->p);
						x->p->cloor=RED;
						w->cloor=BLACK;
						w=x->p->left; 
					}
					if(w->left->cloor==BLACK&&w->right->cloor==BLACK){
						w->cloor=RED;
						x=x->p;
					}else {
						if(w->left->cloor==BLACK){
							leftRevolve(w);
							w->cloor=RED;
							w->p->cloor=BLACK;
							w=w->p;
						}
						rightRevolve(x->p);
						w->cloor=x->p->cloor;
						x->p->cloor=BLACK;
						w->left->cloor=BLACK;
						x=head;
					}
				}
			}
			x->cloor=BLACK;
		}
		
		void dingti(Tree *a,Tree *b){
			if(a->p==NIL)head=b;
			 else if(a->p->left==a) a->p->left=b;
			    else  a->p->right=b;
		    b->p=a->p;
		} 
		void leftRevolve(Tree *a){
			if(a->p->left==a)
				a->p->left=a->right;
			else
			    a->p->right=a->right;
			a->right->p=a->p;
			if(a->right->p==NIL)head=a->right;
			
			Tree *x=a->right->left;
			a->right->left=a;
			a->p=a->right;
			
			x->p=a;
			a->right=x;
		}
		void rightRevolve(Tree *a){
			if(a->p->left==a)
				a->p->left=a->left;
			else 
			    a->p->right=a->left;
			a->left->p=a->p;
			if(a->left->p==NIL)head=a->left;
			
			Tree *x=a->left->right;
			a->left->right=a;
			a->p=a->left;
			
			a->left=x;
			x->p=a;
		}
		Tree* hou(Tree *a){
			Tree *x=a->right;
			Tree *y=NULL;
			if(x==NIL){
				while(a->p->right!=a){
					if(a==head)return NIL;
					a=a->p;
				}
				return a;
			}
			while(x!=NIL){
				y=x;
				x=x->left;
			}
			return y;
		}	
} ;

    Tree* chazhao(int k){
			Tree *a=head;
			while(k!=a->key){
				if(k<a->key) a=a->left;
				else a=a->right;
			}
			return a;
		} 
	void add(int k){
			if(head->key==0){
				head->key=k;
				head->p=NIL;
				head->left=NIL;
				head->right=NIL;
				NIL->left=head;
				NIL->right=head; 
				return ; 
			}
			Tree *t=new Tree(k);
			Tree *x=head;
			Tree *y=NULL;
			while(x!=NIL){
				y=x;
				if(k<x->key)
					x=x->left;
				else 
				    x=x->right;
			}
			t->p=y;
			if(k<y->key)
			    y->left=t;
			else 
			    y->right=t;
			t->adjust(t);			
		}
	void zhongdigui(Tree *a){
		if(a==NIL)return;
		zhongdigui(a->left);
		cout<<a->key<<" ";
		zhongdigui(a->right);
	} 
		
int main(){
	NIL=new Tree();
	head=new Tree();
	for(int i=0;i<40000000;i++){
		add(i);
	} 
//	for(int j=10;j<10000000;j++) head->delete_tree(chazhao(j));
//	zhongdigui(head);
	int l=0,r=0;
	Tree *x=NULL; 
	x=head;
	while(x!=NIL){
		l++;
		x=x->left;
	}
	x=head;
	while(x!=NIL){
		r++;
		x=x->right;
	}
	cout<<l<<"  "<<r<<endl;	 
//	cout<<chazhao(100)->key<<" "<<chazhao(100)->cloor<<endl;
//	cout<<chazhao(100)->hou(chazhao(100))->key;
}
