#include <bits/stdc++.h>
using namespace std;

const int N=1000010;
struct node{
	int num;
	struct node *next;
};
int a[N];

struct pii{
	node* st;
	node* ed;
};

void init(node* &link){
	link=new node;
	link->next=NULL;
}

node* istt(node *&tl,int x){
	node *p=new node;
	p->next=tl->next;
	tl->next=p;
	p->num=x;
	return p;
}

void istk(node* &link,int x){
	node *p=new node;
	p->next=link->next;
	link->next=p;
	p->num=x;
}

void tv(node* &link){
	int flag=0;
	for(node *p=link->next;p!=NULL;p=p->next){
		if(flag) cout<<" ";
		flag=1;
		cout << p->num;
	}
}

pii getp(node* &link,int len){
	node* ed=link;
	for(node* p=link;p->next!=NULL;p=p->next){
		int flag=1;
		node* pp=p;
		for(int i=1;i<=len;i++){
			if(pp->next==NULL||pp->next->num!=a[i]){
				flag=0;
				break;
			}
			ed=pp->next;
			pp=pp->next;
		}
		if(flag){
			return (pii){p,ed};
		}
	}
	return (pii){NULL,NULL};
}

void op2(node* &link){
	for(node* p=link->next;p->next!=NULL;p=p->next){
		int na=p->num,nb=p->next->num;
		if(((na+nb)>>0&1)==0){
			istk(p,(na+nb)>>1);
			p=p->next;
		}
		if(p->next==NULL) break;
	}
}

void op3(node* &link,int s,int e){
	node* st=link->next;
	node* ed=link->next;
	node* bfst=link;
	for(int i=1;i<=s-1;i++){
		bfst=bfst->next;
	}
	for(int i=1;i<=s-1;i++){
		st=st->next;
	}
	for(int i=1;i<=e-1;i++){
		ed=ed->next;
	}
	node* last=bfst;
	node* nt=last->next;
	node* ntnt=nt->next;
	for(int i=1;i<=e-s+1;i++){
		nt->next=last;
		last=nt;
		nt=ntnt;
		if(nt!=NULL) ntnt=nt->next;
	}
	bfst->next=ed;
	st->next=nt;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	node *link;
	init(link);
	
	int n,m;
	cin>>n>>m;
	
	node *tl=link;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		tl=istt(tl,tmp);
	}
	
//	tv(link);
	
	while(m--){
		int op;
		cin>>op;
		if(op==1){
			int L1,L2;
			cin>>L1;
			for(int i=1;i<=L1;i++){
				cin>>a[i];
			}
			pii ppp=getp(link,L1);
			node *st=ppp.st;
			node *ed=ppp.ed;
			st->next=ed->next;
			cin>>L2;
			for(int i=1;i<=L2;i++){
				int t;
				cin>>t;
				istk(st,t);
				st=st->next;
			}
			fill(a,a+N,0);
		}else if(op==2){
			op2(link);
		}else if(op==3){
			int sstt,eedd;
			cin>>sstt>>eedd;
			op3(link,sstt,eedd);
		}
	}
	
	tv(link);
	
	return 0;
}
