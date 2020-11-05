#include <iostream>

using namespace std;

string getLCS(string str1,string str2)
{
    int maxlen = 0,maxend = 0;
    int **arr = new int *[str1.length()];
    for(size_t i=0;i<str1.length();++i)
    {
        arr[i] = new int[str2.length()];
        for(size_t j=0;j<str2.length();++j)
        {
            if(str1[i]==str2[j])
            {
                if(i==0 || j==0)
                {
                    arr[i][j] = 1;
                }
                else
                {
                    arr[i][j] = arr[i-1][j-1]+1;
                }
            }
            else
                arr[i][j] = 0;

            if(arr[i][j]>maxlen)
            {
                maxlen = arr[i][j];
                maxend = i;
            }
        }
    }

    for(size_t i=0;i<str1.length();++i)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return str1.substr(maxend-maxlen+1,maxlen);
}


int main()
{
    string str1("how are you!");
    string str2("hi,nice to meet you!");

    cout<<getLCS(str1,str2)<<endl;
    str1.insert(str1.length()/2,getLCS(str1,str2));
    cout<<str1<<endl;

    return 0;
}
