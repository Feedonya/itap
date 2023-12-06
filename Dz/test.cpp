#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    string s="information security";
    
    size_t pos=s.find(' ');
    
    s=s.substr(pos+1)+ ' ' + s.substr(0,pos);
    
    cout << s << "\n";
    
    return 0;
}