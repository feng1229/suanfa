#include<iostream>
using namespace std;
class Tree;
Tree *root;
class Tree {
	public :
		int key;
		Tree *left;
		Tree *right;
		Tree *p;
	public :
		Tree(int key) {
			this->key=key;
			left=NULL;
			right=NULL;
			p=NULL;
		}

		Tree* search(int key) {
			Tree *x=root;
			while(x!=NULL) {
				if(key=x->key)return x;
				if(key<x->key)x=x->left;
				else x=x->right;
			}
			return x;
		}
		Tree* minimun() {
			Tree *x=root;
			while(x->left!=NULL) x=x->left;
			return x;
		}
		Tree* maxinum() {
			Tree *x=root;
			while(x->right!=NULL) x=x->right;
			return x;
		}
		Tree* predecessor(Tree *z) { //前驱
			Tree *x=z->left;
			if(x!=NULL)
				while (x->right!=NULL) x=x->right;
			else {
				x=z;
				while(x->p!=NULL&&x==x->p->left)x=x->p;
				x=x->p;
			}
			return x;
		}
		Tree* successor(Tree *z) {
			Tree *x=z->right;
			if(x!=NULL)
				while(x->left!=NULL)x=x->left;
			else {
				x=z;
				while(x->p!=NULL&&x==x->p->right)x=x->p;
				x=x->p;
			}
			return x;
		}
		void insert(Tree *z) {
			Tree *x=root,*y;
			if(root->key==0)
				root=z;
			else {
				while(x!=NULL) {
					y=x;
					if(z->key<x->key)
						x=x->left;
					else
						x=x->right;
				}
				if(z->key<y->key)
					y->left=z;
				else
					y->right=z;
				z->p=y;
			}
		}
		void Delete(Tree *z) {
			Tree *l=z->left;
			Tree *r=z->right;
			Tree *x=r;
			if(l!=NULL&&r!=NULL) {
				if(x->left!=NULL) {
					while(x->left!=NULL)x=x->left;
					if(x->right!=NULL)
						x->right->p=x->p;
					x->p->left=x->right;
					x->right=r;
					r->p=x;
				}
				l->p=x;
				x->left=l;

			} else if(l!=NULL)
				x=l;
			x->p=z->p;
			if(z!=root)
				if(z==z->p->left)
					z->p->left=x;
				else
					z->p->right=x;
			else
				root=x;
//				free(z);
		}
};
void xianbianli_digui(Tree *z) {
	if(z!=NULL) {
		cout<<z->key<<" ";
		xianbianli_digui(z->left);
		xianbianli_digui(z->right);
	}
}
void zhongbianli_digui(Tree *z) {
	if(z!=NULL) {
		zhongbianli_digui(z->left);
		cout<<z->key<<" ";
		zhongbianli_digui(z->right);
	}
}
void houbianli_digui(Tree *z) {
	if(z!=NULL) {
		houbianli_digui(z->left);
		houbianli_digui(z->right);
		cout<<z->key<<" ";
	}
}

Tree **a=new Tree *[1000];
int top=-1;
void push(Tree *z) {
	top++;
	a[top]=z;
}
Tree* pop() {
	if(top<0)return NULL;
	top--;
	return a[top+1];
}
void xianbianli_stack(Tree *x) {
	while(1) {
		while(x!=NULL) {
			cout<<x->key<<" ";
			push(x);
			x=x->left;
		}
		x=pop();
		if(x==NULL)return;
		x=x->right;
	}
}
void  zhongbianli_stack(Tree *x) {
	while(1) {
		while(x!=NULL) {
			push(x);
			x=x->left;
		}
		x=pop();
		if(x==NULL)return;
		cout<<x->key<<" ";
		x=x->right;
	}
}
void  houbianli_stack(Tree *x) {
	Tree *y;
	while(1) {
		while(x!=NULL) {
			push(x);
			x=x->left;
		}
		x=pop();
		if(x==NULL)return;
		y=x;
		x=x->right;
		if(y->right==NULL) {
			cout<<y->key<<" ";
			while(y->p!=NULL&&y->p->right==y) {
				y=y->p;
				if(y==NULL)break;
				cout<<y->key<<" ";
			}
		}
	}
}
void add(int key) {
	Tree *z=new Tree(key);
	root->insert(z);
}
int main() {
	root=new Tree(0);
	int q,w,j;
	cout<<"1：添加（数量 数据 数据。。。） 2：删除 3：遍历 "<<endl;
	while(1) {
		cin>>q;
		switch(q) {
			case 1:
				cin>>j;
				for(int i=0; i<j; i++) {
					cin>>w;
					add(w);
				}
				break;
			case 3:
				cout<<"先序遍历（递归）： ";
				xianbianli_digui(root);
				cout<<endl<<"先序遍历（用栈）： ";
				xianbianli_stack(root);
				cout<<endl<<"中序遍历（递归）： ";
				zhongbianli_digui(root);
				cout<<endl<<"中序遍历（用栈）： ";
				zhongbianli_stack(root);
				cout<<endl<<"后序遍历（递归）： ";
				houbianli_digui(root);
				cout<<endl<<"后序遍历（用栈）： ";
				houbianli_stack(root);
		}
	}
}
