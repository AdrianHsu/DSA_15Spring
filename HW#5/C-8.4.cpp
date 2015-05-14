class Stack {

    class Node {

        Node(int p, DATATYPE e)
            :priority(p), element(e){};
        int priority; //key
        DATATYPE element; //value
    };

    priority_queue< Node > Q; // operator'<' is defined by node's priority
    int top_priority = 0; //one additional member variable

    void push(DATATYPE input)
    {
        Q.push( Node(top_priority++, input) ); 
    }
    DATATYPE pop()
    { 
        top_priority--;
        return q.pop().element;
    }
};


Q.index = 0; $
void stack_push(priority_queue Q, DATATYPE input)
{
    Q.push(input);
    Q.index += 1;
}
void stack_pop(priority_queue Q)
{
    
}
DATATYPE stack_top(priority_queue Q)
{
    
}

class Stack {

    class Element { int prio, Key elem; };
    MaxPriorityQueue<Element> q;
    int top_priority = 0;

    void push(Key x) { q.push(Element(top_priority++, x)); }
    Key pop() { top_priority--; return q.pop().elem; }
};

