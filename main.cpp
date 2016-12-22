#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char convert(int num){
    if(num<10)return '0'+num;
    else return 'A'+(num-10);
}

int convert(char character){
    if(character<='9') return character-'0';
    else return character-'A'+10;
}

void encode(int diamonds){
    int q;
    string str="";
    char ctemp;
    while(diamonds>=34){
        q=diamonds%34;
        ctemp=convert(q);
        str=str+ctemp;
        diamonds=diamonds/34;
    }
    str=str+convert(diamonds);
    reverse(str.begin(),str.end());
    cout<<str<<endl;
}

void decode(string code){
    int i;
    int num=0;
    int len=code.length();
    char ctemp;
    int base=1;
    for(i=len-1;i>=0;i--){
        ctemp=code.at(i);
        num=num+convert(ctemp)*base;
        base=base*34;
    }
    cout<<num<<endl;
}



int main() {
    int diamonds;
    char order;
    string code;
    cout<<"please enter the code: E for encode, D for decode"<<endl;
    cin >>order;
    if(order=='E'){
        cout<<"please enter the diamond number"<<endl;
        cin >> diamonds;
        cout<<"the code for the number of diamond is:  ";
        encode(diamonds);
    }else if(order=='D'){
        cout<<"please enter the code"<<endl;
        cin>>code;
        cout<<"the number of the code of diamond is:  ";
        decode(code);
    }


    return 0;
}