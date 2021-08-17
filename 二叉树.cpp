/*二叉树 
*/ 
#include <iostream>
using namespace std;
class yuansu;
yuansu* gen;
class yuansu{
	private :
		yuansu* p;
		yuansu* left;
		yuansu* right;
		int key;
	public :
		yuanshu(){
			p=NULL;
			left=NULL;
			right=NULL;
			key=NULL;
		}
		void setKey(int k){
			key=k;
		} 
		void setLeft(yuansu* l){
			left=l;
		}
		void setRight(yuansu* r){
			right=r;
		}
		void setP(yuansu* pe){
			p=pe;
		}
		yuansu* getP(){
			return p;
		}
		yuansu* getLeft(){
			return left;
		}
		yuansu* getRight(){
			return right;
		}
		int getKey(){
			return key;
		}
		static yuansu* hou(yuansu* a){
			yuansu* l=a->getLeft();
			yuansu* r=a->getRight();
			yuansu* pp=a->getP();
			yuansu* y; 
			if(r!=NULL){//有右儿子 
				while(r->getLeft()!=NULL){
					r=r->getLeft();
				}
				return r;
			}
			if(pp!=NULL){
				if(pp->getRight()==a){
					do{
						y=pp;
						pp=y->getP();
					    if(pp==NULL)return NULL;
				    }while(pp->getLeft()!=y);
				    return pp;
				}
				return pp;				
			}
			return NULL;
		}	
		static yuansu* qian(yuansu *a){
			yuansu* l=a->getLeft();
			yuansu* r=a->getRight();
			yuansu* pp=a->getP();
			yuansu* y;
			if(l!=NULL){
				while(l->getRight()!=NULL){
					l=l->getRight();
				}
				return l;
			}
			if(pp!=NULL){
				if(pp->getLeft()==a){
					do{
						y=pp;
						pp=y->getP();
					    if(pp==NULL)return NULL;
				    }while(pp->getRight()!=y);
				}
				return pp;
			}
			return NULL;
		}
		static void zhongdigui(yuansu *a){
			if(a!=NULL){
				zhongdigui(a->getLeft());
				cout<<a->getKey()<<" ";
				zhongdigui(a->getRight());
			}
		}
		static void shanchu(yuansu *a){
			yuansu *l=a->getLeft();
			yuansu *r=a->getRight();
			yuansu *pp=a->getP();
			if(r!=NULL){//有右儿子 
			    yuansu *hou=yuansu::hou(a);
				yuansu *hou_r=hou->getRight();
				yuansu *hou_p=hou->getP();
				if(hou!=r){
					hou->setP(pp);
					hou->setLeft(l);
					hou->setRight(r);
					if(pp!=NULL){
						 if(pp->getLeft()==a) pp->setLeft(hou);
					     	else pp->setRight(hou);
					}
					if(l!=NULL) l->setP(hou);
					r->setP(hou);
					
					hou_p->setLeft(hou_r);
					if(hou_r!=NULL)hou_r->setP(hou_p);
					if(a==gen)gen=hou;
					delete a;
					return;
				}
				hou->setLeft(l);
				if(pp!=NULL)
					if(pp->getLeft()==a) pp->setLeft(hou);
					    else pp->setRight(hou);
				if(l!=NULL) l->setP(hou);
				hou->setP(pp);
				if(a==gen)gen=hou;
				delete a;
				return;
			}
			if(l!=NULL){
				if(pp!=NULL){
					if(pp->getLeft()==a) pp->setLeft(l);
				         else pp->setRight(l);
				    l->setP(pp);
			    }
			    if(a==gen)gen=l;
			    delete a;
			    return;
			}
			if(pp!=NULL){
					if(pp->getLeft()==a) pp->setLeft(NULL);
				         else pp->setRight(NULL);
			    }
		    delete a;
		    return;		
		}
		static yuansu* chazhao(int k){
			yuansu *a=gen;
			while(true){
				if(a->getKey()==k||a==NULL)return a;
				if(k<a->getKey()){
					a=a->getLeft();
				}else
				  a=a->getRight();
			}	
		}	
};
void addYuansu(int key){
	if((gen->getKey())==NULL){
		gen->setKey(key);
		return;
	}
	yuansu* a=new yuansu();
	yuansu* x=gen;
	yuansu* y=NULL;
	a->setKey(key);
	do{
		if(key<(x->getKey())) {
			y=x->getLeft();
			if(y==NULL){
				x->setLeft(a);
				a->setP(x);
				return;
			}
		}else{
			y=x->getRight();
			if(y==NULL){
				x->setRight(a);
				a->setP(x);
				return;
			}
		}
		x=y;
	}while(true);
}
int main(){
	gen=new yuansu();
	gen->setKey(NULL);
	int a[]={31321,231,3131,26711,213,21,1222,545,152,4,6464,541,48555,155551,14,2155,5146,45552,12155};
	int a_lenght=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<a_lenght;i++)	
	addYuansu(a[i]);
	yuansu::zhongdigui(gen);
	cout<<endl;
	for(int w=0;w<a_lenght;w++){	
		cout<<"删除"<<a[w]<<endl;
		yuansu::shanchu(yuansu::chazhao(a[w]));
		yuansu::zhongdigui(gen);	 
		cout<<endl;
	}
}

