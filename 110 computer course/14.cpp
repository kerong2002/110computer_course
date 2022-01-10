#include <iostream>

using namespace std;

int main()
{
    while(1){
        string s;
        cin>>s;
        if(stoi(s)>0){
            while(stoi(s)>=10){
                string s1,s2;
                for(int i=0;i<=s.size();i++)
                {
                     if(s.size()%2==0){
                         if(i%2==0)
                            s2=s2+s[i];
                        else
                            s1=s1+s[i];
                    }
                    else{
                        if(i%2==0 )
                            s1=s1+s[i];
                        else
                            s2=s2+s[i];
                    }
                }
                s=to_string(stoi(s1)-stoi(s2));
                printf("%d-%d=%d\n",stoi(s1),stoi(s2),stoi(s));
                }
        }
        else{
            break;
        }
    }

    return 0;
}
