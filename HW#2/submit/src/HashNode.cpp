#include <iostream>
#include "HashNode.h"
using namespace std;

int& HashNode::pFlag(const int i) { //an easier way to access class members
    
    switch(i){ //protected members
    default:
    case  0:    return Click;
    case  1:    return Impression;
    case  3:    return AdID;
    case  4:    return AdvertiserID;
    case  5:    return Depth;
    case  6:    return Position;
    case  7:    return QueryID;
    case  8:    return KeywordID;
    case  9:    return TitleID;
    case 10:    return DescriptionID;
    }
}