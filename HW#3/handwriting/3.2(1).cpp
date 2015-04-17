#include <Stack>
#include <Queue>

bool function(Stack s, Queue q)
{
	bool flag = true;
	int size;
	while( s.top() != x)
	{
		q.enque(s.top());
		s.pop();
		if(s.empty())
			flag = false;
	}
	size = s.size();
	while(!q.empty())
	{
		s.push(q.front());
		q.dequeue();
	}
	while(s.size() > size)
	{
		q.enque(s.top());
		s.pop();
	}
	while(!q.empty())
	{
		s.push(q.front());
		q.dequeue();
	}
	return flag;
}
