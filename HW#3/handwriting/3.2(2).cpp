#include <Deque>
#include <Stack>

void function(Stack s, Stack t, Deque d)
{
	while(!s.empty())
	{
		insertFront(s.top());
		s.pop();
	}
	while(!t.empty())
	{
		insertFront(t.top());
		t.pop();		
	}
	while(!d.empty())
	{
		s.push(d.back());
		d.eraseBack();
	}
}