//
//  BitMap.hpp
//  index12(hashset)
//
//  Created by 孟令凯 on 2021/5/13.
//

#ifndef BitMap_hpp
#define BitMap_hpp

#include <stdio.h>
#include <string>
class BitMap{

    int capacity_;
    char* bm_;
    int unit_bits_;

public:
    BitMap();
    BitMap(int size);
    ~BitMap();
    int set(int pos, int val);
    int get(int pos);

};
#endif /* BitMap_hpp */
