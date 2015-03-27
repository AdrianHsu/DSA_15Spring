bool inner(CircleList L, CircleList M) 
{   //Generally speaking, L & M are passed by value, not reference
    CNode* mHead;
    mHead = &M.back();
    do{
        if(*mHead != *lHead)
            return false; //if one element isn't the same, return false
        M.advance(); //advance both to compare the next element
        L.advance();
    }while(mHead != &M.back()) // && lHead != &L.back() is redundent
    return true;
}
bool identical(CircleList L, CircleList M)
{
    //header files refer to P.130 in textbook
    if(L.length() != M.length()) return false;

    CNode* mHead;
    mHead = &M.back(); //.back() return element at cursor
    do{
        if(inner(L, M))  //inner loop to check the whole circleList 
            return true; //is identical
        M.advance(); //if not, advance M, remain L unchanged
    }while( mHead != &M.back()) //if finished checking the whole circle,
    return false; //return false
}
