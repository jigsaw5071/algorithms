#include<iostream>
using namespace std;

typedef struct Node{
int data;
struct Node * next;
struct Node * prev;
}* NodePtr;

class _doubly_linked_list{
private:
NodePtr head;
NodePtr tail;

public:
_doubly_linked_list(){
head=NULL;
tail=NULL;
}

void _insert(int);
void _print_forward();
void _print_reverse();
NodePtr get_head();
NodePtr get_tail();

};

NodePtr get_new_node(int _key){
NodePtr P=new Node;
P->data=_key;
P->prev=NULL;
P->next=NULL;
return P;
}

void _doubly_linked_list::_insert(int key){
NodePtr P=get_new_node(key);
if(head==NULL && tail==NULL){
head=tail=P;
}
else if(head!=NULL){
tail->next=P;
P->prev=tail;
tail=P;
}
}

void _doubly_linked_list::_print_forward(){
if(head==NULL){
cout<<"Your List is Empty"<<endl;
}
else {
NodePtr current=head;
while(current!=NULL){
cout<<current->data<<" ";
current=current->next;
}
cout<<endl;
}
}

void _doubly_linked_list::_print_reverse(){
if(tail==NULL){
cout<<"Your list is empty"<<endl;
}
else{
NodePtr current=tail;
while(current!=NULL){
cout<<current->data<<" ";
current=current->prev;
}
cout<<endl;
}
}

NodePtr _doubly_linked_list::get_head(){
return head;
}
NodePtr _doubly_linked_list::get_tail(){
return tail;
}

void _swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}


NodePtr _partition(_doubly_linked_list &P,NodePtr &l, NodePtr &h){
int pivot=h->data;
NodePtr pivot_index=h;
NodePtr pIndex=l;
NodePtr i=l;
while(i!=h){
if(i->data <= pivot){
_swap(&(i->data),&(pIndex->data));
pIndex=pIndex->next;
}
i=i->next;
}
_swap(&(pIndex->data),&(pivot_index->data));

return pIndex;
}

void _quickSort_DLL(_doubly_linked_list &P,NodePtr &l, NodePtr &h){
if(l!=NULL && h!=NULL && l!=h && l!=h->next){
NodePtr pIndex=_partition(P,l,h);
_quickSort_DLL(P,l,pIndex->prev);
_quickSort_DLL(P,pIndex->next,h);

}



}

void __quicksort_wrapper(_doubly_linked_list &P){
NodePtr l=P.get_head();
NodePtr r=P.get_tail();
if(l==NULL || r==NULL){
cout<<"Your list is empty"<<endl;
}
else{
_quickSort_DLL(P,l,r);
}
}

int main(void){
_doubly_linked_list D;
int arr[]={10, 80, 30, 90, 40, 50, 70};
int N=sizeof(arr)/sizeof(arr[0]);
for(int i=0;i<N;++i){
D._insert(arr[i]);
}
__quicksort_wrapper(D);
D._print_forward();
return 0;
}
