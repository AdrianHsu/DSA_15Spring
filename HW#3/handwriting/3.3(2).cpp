#include <vector>

void shuffle( vector<Card> v, int n )
{
	//Fisher and Yates' original method
	for(int i = n; i > 0; i--)
	{
		//pick a random number j between 1 and the number i, unstruck numbers remaining (inclusive)
		j = randomInteger(i);
		//Counting from the low end, strike out the kth number not yet struck out
		//, and write it down elsewhere.(v.push_back())
		Card temp = v[j];
		v.push_back(temp);
		v.erase(j);
		//Repeat from step 2 until all the numbers have been struck out.(i == 0)
	}
	//The sequence of numbers written down in step 3,(vector v)
	//is now a random permutation of the original numbers.
}

