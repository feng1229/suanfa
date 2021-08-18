//гвзгЪїДѓгк
#include<stdio.h>
#include<malloc.h>
#define tree_cloor int
#define BLACK 1
#define RED 0

typedef struct Re_tree {
	struct Re_tree* left;
	struct Re_tree* right;
	struct Re_tree* p;
	int data;
	tree_cloor cloor;
}re_tree;
re_tree* NIL;
re_tree* root;
void qz_l(re_tree* z) {
	re_tree* r = z->right;
	z->right = r->left;
	z->right->p = z;
	r->p = z->p;
	r->left = z;
	z->p = r;
	if (z == r->p->left)
		r->p->left = r;
	else r->p->right = r;
	if (root == z)
		root = r;
}
void qz_r(re_tree* z) {
	re_tree* l = z->left;
	z->left = l->right;
	z->left->p = z;
	l->p = z->p;
	z->p = l;
	l->right = z;
	if (l->p->left == z)
		l->p->left = l;
	else l->p->right = l;
	if (root == z)
		root = l;
}
int add_genxin(re_tree* z) {
	while (z!=root&&z->cloor == RED) {
		re_tree* shu = z->p->left;
		int b = shu == z;
		if (b)shu = z->p->right;
		if (shu->cloor == RED) {
			z->cloor = BLACK;
			shu->cloor = BLACK;
			z = z->p;
			z->cloor = RED;
			z = z->p;
		}
		else {
			if (b && z->right == RED) {
				qz_l(z);
				z = z->p;
			}
			else if (!b && z->left == RED) {
				qz_r(z);
				z = z->p;
			}
			if (b) {
				qz_r(z->p);
			}
			else qz_l(z->p);
			z->cloor = BLACK;
			shu->p->cloor = RED;
			return 1;
		}
	}
	z->cloor = BLACK;
	return 1;
}
int add(re_tree* z, int x) {
	re_tree* q = (re_tree*)malloc(sizeof(re_tree));
	if (!q) return 0;
	q->left = NIL;
	q->right = NIL;
	q->data = x;
	q->cloor = RED;
	if (z != NIL) {
		re_tree* y=z;
		int b;
		while (z != NIL) {
			y = z;
			b = x > z->data;
			if (b)z = z->right;
			else z = z->left;
		}
		if (b)y->right = q;
		else y->left = q;
		q->p = y;
		return add_genxin(y);
	}
	else {
		root = q;
		root->p = NIL;
		root->cloor = BLACK;
		return 1;
	}
}
re_tree* chazhao(re_tree* z, int x) {
	while (z != NIL && z->data != x) {
		if (x > z->data)z = z->right;
		else z = z->left;
	}
	return z;
}
void dele_gengxin(re_tree* z) {
	while (z!=root&&z->cloor == BLACK) {
		re_tree* xd = z->p->left;
		int b = xd == z;
		if(b)xd = z->p->right;
		if (xd->cloor == BLACK) {
			if (xd->left->cloor == BLACK && xd->right->cloor == BLACK) {
				xd->cloor = RED;
				z = z->p;
			}
			else {
				if (b) {
					if (xd->right->cloor == BLACK) {
						qz_r(xd);
						xd->cloor = RED;
						xd = xd->p;
						xd->cloor = BLACK;
					}
					qz_l(xd->p);
					xd->right->cloor = BLACK;
					xd->cloor = xd->left->cloor;
					xd->left->cloor = BLACK;
				}
				else {
					if (xd->left->cloor == BLACK) {
						qz_l(xd);
						xd->cloor = RED;
						xd = xd->p;
						xd->cloor = BLACK;
					}
					qz_r(xd->p);
					xd->left->cloor = BLACK;
					xd->cloor = xd->right->cloor;
					xd->right->cloor = BLACK;
				}
				break;
			}
		}
		else {
			if (b) qz_l(z->p);
			else qz_r(z);
			z->p->cloor = RED;
			xd->cloor = BLACK;
		}
	}
	z->cloor = BLACK;
}
int dele(re_tree* z, int x) {
	re_tree* q1 = chazhao(z, x);
	if (q1 != NIL) {
		if (q1->left == NIL) {
			q1->right->p = q1->p;
			q1->right->cloor = BLACK;
			if (q1 == q1->p->left)
				q1->p->left = q1->right;
			else q1->p->right = q1->right;
			if (q1 == root)root = q1->right;
		}
		else if (q1->right == NIL) {
			q1->left->p = q1->p;
			q1->left->cloor = BLACK;
			if (q1 == q1->p->left)
				q1->p->left = q1->left;
			else q1->p->right = q1->left;
			if (q1 == root)root = q1->left;
		}
		else {
			re_tree* r=q1->right;
			if (r->left == NIL) {
				q1->right = r->right;
				q1->right->p = q1;
			}
			else {
				do {
					r = r->left;
				} while (r->left != NIL);
				r->p->left = r->right;
				r->right->p = r->p;
			}
			q1->data = r->data;
			if (r->cloor == BLACK) dele_gengxin(r->right);
			q1 = r;
		}
		
		free(q1);
		return 1;
	}
	else return 0;
}
re_tree* cuanjian() {
	NIL= (re_tree*)malloc(sizeof(re_tree));
	NIL->left = NIL;
	NIL->right = NIL;
	NIL->cloor = BLACK;
	return NIL;
}
void shu(re_tree* z) {
	if (z != NIL) {
		shu(z->left);
		printf("%d ", z->data);
		shu(z->right);
	}
}
int main() {
	root = cuanjian();
	for (int i = 1; i < 2080; ++i)add(root, i);
	for (int i = 30; i < 800; ++i)dele(root, i);
	shu(root);
}
