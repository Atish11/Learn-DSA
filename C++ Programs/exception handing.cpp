#include <iostream>
using namespace std;
try{
//code for try
throw "exception";
}
catch(exception){
//code for catch
}
int main()
{
int x = 1;
try{
cout << "Try Block: "<<endl;
if(x < 10)
{
throw x;
}
}
catch (int x ) {
cout << "Catch Block: "<<endl;
}
cout<<"end of code:(after catch block) "<<endl;
return 0;
}

catch (...) {
cout << "Default Exceptionn"<<endl;
}






