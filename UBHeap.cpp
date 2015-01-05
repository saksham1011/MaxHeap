// ============================================================================
// UBHeap.cpp
// ~~~~~~~~~~
// Saksham Arora
// ============================================================================

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "UBHeap.h"

using namespace std; // BAD PRACTICE

UBHeap::UBHeap(const std::vector<int>& a) :heap_(a){
    
    heapify();
}

UBHeap& UBHeap::operator=(const UBHeap& theOther){
    
    heap_ = theOther.heap_;
    return *this;
}

bool UBHeap::empty(){
    
    return heap_.size() == 0;
}

void UBHeap::push(int x){
    
    heap_.push_back(x);
    floatUp(heap_.size()-1);
}

void UBHeap::pop(){
    
    swap(heap_[0],heap_[heap_.size()-1]);
    heap_.pop_back();
    sink(0);
}

int UBHeap::top(){
    
    return heap_[0];
}

string UBHeap::toString(){
    
    ostringstream oss;
    
    for(size_t i = 0; i<heap_.size(); i++){
        oss<<heap_[i]<<" ";
    }
    return oss.str();
}

void UBHeap::sink(size_t i){
    
    if (heap_.size() > heap_.size())
        return;
    
    size_t left, right, my_pick;
    
    while ((left = 2*i+1) < heap_.size()) {
        right = left + 1;
        my_pick = right >= heap_.size() 
        ? left : heap_[right] > heap_[left] ? right : left;
        
        if (heap_[i] >= heap_[my_pick]) break;
        
        swap(heap_[i], heap_[my_pick]);
        i = my_pick;
    }
}

void UBHeap::floatUp(size_t i){
    
    size_t n;
    
    if (i == 0) {
        return;
    }
    n = (i-1)/2;
    if (heap_[i] > heap_[n]) {
        int temp = heap_[n];
        heap_[n] = heap_[i];
        heap_[i] = temp;
        floatUp(n);
    }
}
void UBHeap::heapify(){
    
    for (int i=heap_.size()/2; i>=0; i--)
        sink(i);
}
