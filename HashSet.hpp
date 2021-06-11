//
//  HashSet.hpp
//  index12(hashset)
//
//  Created by 孟令凯 on 2021/5/11.
//

#ifndef HashSet_hpp
#define HashSet_hpp

#include <stdio.h>



const int MAX_ID = 1000000000;
const int HASH_SCALE = 2;
struct out_vertex{
    int vertex;
    unsigned int value;
};
class HashSet {
private:
    int *head_2;
    int *val_2;
    int *next_2;
    
    out_vertex *head_;
    out_vertex *val_;
    out_vertex *next_;
    
    int cur_, capacity_, buckets_;

public:
    HashSet(int size,int flag);
    ~HashSet() ;

    void insert(out_vertex v) ;
    out_vertex find(int v) ;
    
    void insert_query(unsigned int v) ;
    int find_query(int v) ;
};

#endif /* HashSet_hpp */
