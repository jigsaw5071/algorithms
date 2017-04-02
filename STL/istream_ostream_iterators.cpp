#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;


int main(void){
  vector<int> arr1(4);
  vector<int> arr2(5);
  copy_n(istream_iterator<int>(cin),4,arr1.begin());
  copy_n(istream_iterator<int>(cin),5,arr2.begin());
  
  copy(arr1.begin(),arr1.end(),ostream_iterator<int>(cout," "));
  cout<<endl;
  copy(arr2.begin(),arr2.end(),ostream_iterator<int>(cout," "));
  return 0;
}
