#include <bits/stdc++.h>

using namespace std;

const int prime = 101;

vector<int> hihi;

int rabin_carp(string pattern, string text, vector<int>& hihi)
{
    int pattern_hash = 0;
    int text_hash = 0;
    int h =1;
    for (int i=0;i<pattern.size();i++)
    {
        pattern_hash += pattern[i]* pow(prime,i);
        text_hash+= text[i]* pow(prime,i);
    }
    for (int i=0;i<pattern.size()-1;i++)
    {
        h=(h*prime);
    }
    for (int i =0;i<=text.size()-pattern.size();i++)
    {
        if (pattern_hash == text_hash)
        {
            bool match = true;

            for (int j =0;j<pattern.size();j++)
            {
                if (text[i+j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                return i;
            }
        }
        if (i<text.size()-pattern.size())
        {
            text_hash = (prime*(text_hash-text[i]*h)+text[i+pattern.size()]);
        }
    }
    return -1;
}

int main()
{
    string fla, min;
    cin>>fla>>min;
    int index = rabin_carp(min,fla,hihi);
    if (index != -1)
    {
        cout<<index<<endl;
    }
    else
    {
        cout<<"not found"<<endl;
    }
    for (auto r:hihi)
        cout<<r<<endl;
    return 0;
}