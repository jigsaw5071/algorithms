#include<iostream>
using namespace std;

typedef struct Node{
int data;
struct Node* next;
}*NodePtr;

class _linked_list{
private:
NodePtr head;

public:
_linked_list(){
head=NULL;
}
void _insert(const int);
void _print_list();
NodePtr  &_get_head();

};

NodePtr _get_new_node(const int data){
NodePtr P=new Node;
P->data=data;
P->next=NULL;
return P;
}

void _linked_list::_insert(const int data){
if(head==NULL){
NodePtr P=_get_new_node(data);
head=P;
}
else{
NodePtr current=head;
while(current->next!=NULL){
current=current->next;
}
current->next=_get_new_node(data);
}
}

void _linked_list::_print_list(){
if(head==NULL){
cout<<"This list is already empty!"<<endl;
}
else{
NodePtr current=head;
while(current!=NULL){
cout<<current->data<<" " ;
current=current->next;
}
cout<<endl;
}
}

NodePtr & _linked_list::_get_head(){
return head;
}

void print(NodePtr &head){
if(head==NULL){
cout<<endl;
}
else{
NodePtr current=head;
while(current!=NULL){
cout<<current->data<<" ";
current=current->next;
}
cout<<endl;
}
}

void _merge(NodePtr &first_head,NodePtr &second_head,NodePtr &head){
NodePtr current1=first_head;
NodePtr current2=second_head;
if(current1==NULL && current2==NULL){
head=NULL;
}
else if(current2==NULL){
head=current1;
}
else if(current1==NULL)
{
head=current2;
}
else{
if(current1->data < current2->data){
head=current1;
current1=current1->next;
}
else{
head=current2;
current2=current2->next;
}
NodePtr current=head;
while(current1!=NULL && current2!=NULL){
if(current1->data<current2->data){
current->next=current1;
current1=current1->next;
current=current->next;
current->next=NULL;
}
else{
current->next=current2;
current2=current2->next;
current=current->next;
current->next=NULL;
}
}
while(current1!=NULL){
current->next=current1;
current1=current1->next;
current=current->next;
current->next=NULL;
}
while(current2!=NULL){
current->next=current2;
current2=current2->next;
current=current->next;
current->next=NULL;
}

}
}






void _mergeSort_LL(NodePtr &head){
if(head!=NULL && head->next!=NULL){
NodePtr _head_first=head;
NodePtr _head_second=NULL;
NodePtr _fast=head;
NodePtr _mid=head;
while(_fast!=NULL && _fast->next!=NULL){
_fast=_fast->next;
_fast=_fast->next;
_mid=_mid->next;
}
_head_second=_mid;
NodePtr current=_head_first;
while(current->next!=_mid){
current=current->next;
}
current->next=NULL;
_mergeSort_LL(_head_first);
_mergeSort_LL(_head_second);
_merge(_head_first,_head_second,head);
}
}




void _mergeSort_wrapper(_linked_list &L){
NodePtr &head=L._get_head();
if(head==NULL){
cout<<"The array is empty"<<endl;
}
else{
_mergeSort_LL(head);
}
}

int main(void){
_linked_list L;
L._insert(1);


_mergeSort_wrapper(L);
L._print_list();

return 0;
}
