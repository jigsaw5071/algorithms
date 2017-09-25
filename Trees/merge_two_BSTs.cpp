 /*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The structure of Node is
struct Node {
int data;
Node * right, * left;
};*/
/*You are required to complete below method */


void merge(Node *root1, Node *root2)
{
   //Your code here
   Node* p1 = root1;
   Node* p2 = root2;
   stack<Node*> st1 , st2;
   
   while(!st1.empty() || p1 != NULL || !st2.empty() || p2 != NULL){
       if(p1 || p2){
           if(p1){st1.push(p1); p1 = p1->left;}
           if(p2){st2.push(p2); p2 = p2->left;}
       }
       else{
           if(!st1.empty() && !st2.empty()){
               Node* t1 = st1.top();
               Node* t2 = st2.top();
               if(t1->data <= t2->data){
                   cout << t1->data << " ";
                   st1.pop();
                   p1 = t1->right;
               }
               else{
                   cout << t2->data << " ";
                   st2.pop();
                   p2 = t2->right;
               }
           }
           else if(!st1.empty()){
               Node* t1 = st1.top();
               cout << t1->data << " ";
               st1.pop();
               p1 = t1->right;
           }
           else if(!st2.empty()){
               Node* t2 = st2.top();
               cout << t2->data << " ";
               st2.pop();
               p2 = t2->right;
           }
       }
   }
   
}
