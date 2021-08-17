#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class AVLTree;
AVLTree *nil;
void weihushu_add(AVLTree*);
void huh(AVLTree *,AVLTree *);
void de_weihu(AVLTree *);
class AVLTree {
	public:
		int key;
		int h;//-1代表左子树高 0代表同高 1代表右子树高
		int q;
		AVLTree *left;
		AVLTree *right;
		AVLTree *p;

		AVLTree(int key) {
			this->key=key;
			h=0;
			left=nil;
			right=nil;
			p=nil;
			q=0;
		}
};
AVLTree *root=NULL;

void left_qz(AVLTree *z) {
	AVLTree *r=z->right;
	r->p=z->p;
	if(z==root)
		root=z->right;
	else if(z->p->left==z)
		z->p->left=r;
	else
		z->p->right=r;
	z->right=r->left;
	r->left->p=z;
	z->p=r;
	r->left=z;
}

void right_qz(AVLTree *z) {
	AVLTree *l=z->left;
	l->p=z->p;
	if(z==root)
		root=l;
	else if(z->p->left==z)
		z->p->left=l;
	else
		z->p->right=l;
	z->left=l->right;
	l->right->p=z;
	z->p=l;
	l->right=z;
}

void add(AVLTree *z) {
	if(root==NULL) {
		root=z;
		return;
	}
	AVLTree *x=root;
	AVLTree *y;
	while(x!=nil) {
		y=x;
		if(z->key>x->key)
			x=x->right;
		else
			x=x->left;
	}
	z->p=y;
	if(z->key<y->key)
		y->left=z;
	else
		y->right=z;
	weihushu_add(z);
}

void weihushu_add(AVLTree *z) {
	while(z!=root) {
		if(z->p->left==z)
			z->p->h--;
		else
			z->p->h++;
		z=z->p;
		if(z->h==-2) {
			if(z->left->h==1) {
				left_qz(z->left);
				if(z->left->h==-1) {
					z->left->left->h=0;
					z->h=1;
				}
				if(z->left->h==1) {
					z->left->left->h=-1;
					z->h=0;
				}
				if(z->left->h==0) {
					z->left->left->h=0;
					z->h=0;
				}
			} else
				z->h=0;
			right_qz(z);
			z->p->h=0;
			return;
		}
		if(z->h==2) {
			if(z->right->h==-1) {
				right_qz(z);
				if(z->right->h==1) {
					z->right->right->h=0;
					z->h=-1;
				}
				if(z->right->h==-1) {
					z->right->right->h=1;
					z->h=0;
				}
				if(z->right->h==-1) {
					z->right->right->h=0;
					z->h=0;
				}
			} else
				z->h=0;
			left_qz(z);
			z->p->h=0;
			return;
		}
		if(z->h==0)return;
	}
}

void de(AVLTree *z) {
	AVLTree *r=z->right;
	if(z->left==nil||z->right==nil) {
		AVLTree *x=z->left;
		if(z->left==nil)
			x=z->right;
		if(z->p->left==z) {
			z->p->left=x;
			z->p->h++;
		} else {
			z->p->right=x;
			z->p->h--;
		}
		x->p=z->p;
		r=z->p;
	} else {
		AVLTree *y;
		while(r->left!=nil)
			r=r->left;
		if(r==z->right)
			r->h=z->h-1;
		else {
			r->h=z->h;
			r->p->h++;
			r->p->left=r->right;
			r->right->p=r->p;
			y=r->p;
		}
		huh(z,r);
		if(r!=z->right)
			r=y;
	}
	de_weihu(r);
}

void de_weihu(AVLTree *z) {
	while(z!=nil) {
		if(z->h==-1||z->h==1)
			z=nil;
		else {
			if(z->h==-2) {
				if(z->left->h==1) {
					left_qz(z->left);
					right_qz(z);
					if(z->p->h==-1) {
						z->p->left->h=0;
						z->h=1;
					}
					if(z->p->h==0) {
						z->p->left->h=0;
						z->h=0;
					}
					if(z->p->h==1) {
						z->p->left->h=-1;
						z->h=0;
					}
				} else {
					right_qz(z);
					if(z->p->h==0) {
						z->h=-1;
						z->p->h=1;
						return;
					} 
					z->h=0;
				}
				z->p->h=0;
				z=z->p;
			} else if(z->h==2) {
				if(z->right->h==-1) {
					right_qz(z->right);
					left_qz(z);
					if(z->p->h==-1) {
						z->p->right->h=1;
						z->h=0;
					}
					if(z->p->h==0) {
						z->p->right->h=0;
						z->h=0;
					}
					if(z->p->h==1) {
						z->p->right->h=0;
						z->h=-1;
					}
				} else {
					left_qz(z);
					if(z->p->h==0) {
						z->h=1;
						z->p->h=-1;
						return;
					}
					z->h=0;
				}
				z->p->h=0;
				z=z->p;
			}
			if(z->p->left==z)
				z->p->h++;
			else
				z->p->h--;
			z=z->p;
		}
	}
	nil->h=0;
}
void huh(AVLTree *z,AVLTree *x) {
	x->p=z->p;
	if(z==root)
		root=x;
	else {
		if(z->p->left==z)
			z->p->left=x;
		else
			z->p->right=x;
	}
	if(x!=z->right) {
		z->right->p=x;
		x->right=z->right;
	}
	if(x!=z->left) {
		x->left=z->left;
		z->left->p=x;
	}
}
AVLTree* chazhao(AVLTree *z,int key) {
	while(z!=nil) {
		if(key==z->key) return z;
		if(key<z->key)
			z=z->left;
		else
			z=z->right;
	}
	return NULL;
}
void dig(AVLTree *z) {
	if(z!=nil) {
		dig(z->left);
	//	cout<<z->key<<" ";
if(z->left->key>z->key||(z->right!=nil&&z->right->key<z->key))cout<<"aaa";
		if(z->h!=z->right->q-z->left->q)
			cout<<"cw"<<" ";
		dig(z->right);
	}
}

int yanzheng(AVLTree *z) {
	if(z!=nil) {
		int l=yanzheng(z->left)+1;
		int r=yanzheng(z->right)+1;
		if(l-r>1||l-r<-1)cout<<"all";
		if(l<r)
			l=r;
		z->q=l;
		return l;
	} else return 0;
}
int main() {
	nil=new AVLTree(0);

//	for(int i=1000000; i>100; i--)
//		add(new AVLTree(i));
	for(int i=1;i<150000;i++)
	add(new AVLTree(i));
	for(int i=1000; i<50000; i++)
		de(chazhao(root, i));
	yanzheng(root);
	dig(root);
	cout<<endl;
//	dig2(root);
//	cout<<endl;
//	dig3(root);
//cout<<chazhao(root, 3)->right->key;
}
