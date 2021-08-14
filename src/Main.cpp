#include <iostream>
#include "console.h"
#include "vector.h"
#include "random.h"
#include<iterator>
using namespace std;
void sort(vector<int> &vec);
void quicksort(vector<int> &vec, int start, int finish);
int partition (vector<int> &vec, int start, int finish);
void insertionsort(vector<int> &v);
int main() {
  vector<int> vec = {56,25,37,58,95,19,73,30};
  quicksort(vec,0,vec.size()-1);

  return 0;
}

void quicksort(vector<int> &vec, int start, int finish){
   if (start >=finish) return;
    if((finish-start)>3){
    int boundary = partition (vec,start, finish);
    quicksort(vec, start, boundary-1);
    quicksort(vec,boundary+1,finish);
    } else {
        insertionsort(vec);
    }
}

int partition(vector<int> & vec, int start, int finish){
   // int mid= (vec.size()%2==0)? vec.size()/2: (vec.size()-1)/2;
   // vector<int> vc = {vec[start],vec[finish],vec[mid]};
    int pivot = vec[start];
    int lh=start+1;
    int rh=finish;

    while (true){
        while (lh < rh && vec[rh] >= pivot) rh--;
        while (lh < rh && vec[lh] < pivot) lh++;
        if (lh==rh) break;
        int tmp=vec[lh];
        vec[lh]=vec[rh];
        vec[rh]=tmp;
    }
    if (vec[lh] >= pivot) return start;
    vec[start]=vec[lh];
    vec[lh]=pivot;
    return lh;
}

void insertionsort(vector<int> &v){
    vector<int>::iterator ptr=v.begin();
    advance(ptr,1);
    for (ptr;ptr<prev(v.end(),0);++ptr){
        vector<int>::iterator previous=prev(ptr,1);
        if(*previous>*ptr){
        while((*previous>*ptr)&&(ptr>v.begin())){
            int temp= *previous;
            v.erase(previous);
            v.insert(ptr,temp);
            ptr--;
            previous--;
            }
        }
    }
}





