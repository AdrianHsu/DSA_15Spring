#include <Stack>

void function(Stack a, Stack b, Stack c)
{
	while(!a.empty())
	{
		c.push(a.top());
		a.pop();
	}
	while(!b.empty())
	{
		c.push(b.top());
		b.pop();
	}
	while(!c.empty())
	{
		a.push(c.pop());
		c.pop();
	}
}