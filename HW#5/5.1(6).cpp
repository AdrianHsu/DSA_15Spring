typedef unsigned long long int longint;

longint hash(string s) //BONUS
{
    longint out = 0;
    for(int i = 0; i < s.size(); i++)
    {
        out *= 27;
        out += s[i] - 'a' + 1; //hash("a") == 1
    }
    return out;
}
// consider hash("register"):
// 190329075127, still in the range of longint
// consider hash("volatile"):
// 236112196676, still in the range of longint


