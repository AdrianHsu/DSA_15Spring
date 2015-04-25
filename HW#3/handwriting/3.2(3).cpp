#include <Stack>

void pushFront(Stack s, Stack q, Element e)
{
	while(!s.isempty())
	{
		q.push(s.pop());
	}
	q.push(e);
	while(!q.isempty())
	{
		s.push(q.pop());
	}
}
void popFront(Stack s, Stack q)
{
	while(!s.isempty())
	{
		q.push(s.pop());
	}
	q.pop();
	while(!q.isempty())
	{
		s.push(q.pop());
	}
}
void pushBack(Stack s, Stack q, Element e)
{
	s.push(e);
}
void popBack(Stack s, Stack q)
{
	s.pop();
}
