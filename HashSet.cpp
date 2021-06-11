//
//  HashSet.cpp
//  index12(hashset)
//
//  Created by 孟令凯 on 2021/5/11.
//

#include "HashSet.hpp"

HashSet::HashSet(int size, int flag) {
    
    head_ = val_ = next_ = NULL;
    head_2 = val_2= next_2 = NULL;
//    if(size == 0) return;
    
    
    buckets_ = size * HASH_SCALE;
    cur_ = 0;
    capacity_ = size;

    
    if(flag == 1){
        head_ = new out_vertex[buckets_];
        val_ = new out_vertex[size];
        next_ = new out_vertex[size];

        for(unsigned int i = 0;i < buckets_;i ++) head_[i].vertex = -1;
    }
    else if (flag == 2){
        head_2 = new int[buckets_];
        val_2 = new int[size];
        next_2 = new int[size];
        for(int i = 0;i < buckets_;i ++) head_2[i] = -1;
    }
    
    

}

HashSet::~HashSet() {
    if(head_ != NULL) delete[] head_;
    if(val_ != NULL) delete[] val_;
    if(next_ != NULL) delete[] next_;
    
    if(head_2 != NULL) delete[] head_;
    if(val_2 != NULL) delete[] val_;
    if(next_2 != NULL) delete[] next_;
}

void HashSet::insert(out_vertex v) {
#ifdef _DEBUG_
    if(cur_ == capacity_) {
        printf("HashSet is already full.\n");
        return;
    }
#endif

    int target_bucket = v.vertex % buckets_;
    val_[cur_] = v;
    next_[cur_] = head_[target_bucket];
    head_[target_bucket].vertex = cur_ ++;
}

out_vertex HashSet::find(int v) {
    int target_bucket = v % buckets_;
    for(unsigned int i = head_[target_bucket].vertex; i != -1; i = next_[i].vertex) {
        if(val_[i].vertex == v) {
            out_vertex a;
            a.value =val_[i].value;
            a.vertex = 1;
            return a;
        }
    }
    out_vertex a;
    a.vertex = 0;
    return a;
}

void HashSet::insert_query(unsigned int v){
#ifdef _DEBUG_
    if(cur_ == capacity_) {
        printf("HashSet is already full.\n");
        return;
    }
#endif
//    if(find_query(v)) return 0;

    int target_bucket = v% buckets_;
    val_2[cur_] = v;
    next_2[cur_] = head_2[target_bucket];
    head_2[target_bucket] = cur_ ++;
//    return 1;
}

int HashSet::find_query(int v){
    int target_bucket = v % buckets_;
    for(unsigned int i = head_2[target_bucket]; i != -1; i = next_2[i]) {
        if(val_2[i] == v) {
            return 1;
        }
    }
    return 0;
}

