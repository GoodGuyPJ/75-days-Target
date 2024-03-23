#include<bits/stdc++.h>
#include<map>
#include<unordered_map>
using namespace std;
 
 
int main(){
    
    //creation
    unordered_map<string, int> m;

    //insertion
    //1
    pair<string, int> pair1 = make_pair("goodguypj", 3);
    m.insert(pair1);
    //2
    pair<string, int> pair2("goodguyPJ", 2);
    m.insert(pair2);

    //3
    m["mera"] = 1;

    //here it will do updation from (mera = 1) it will become (mera = 2)
    m["mera"] = 2;

    //searach
    cout<<m["mera"]<<endl;
    cout<<m.at("goodguyPJ")<<endl;

    cout<<m["unknownKey"]<<endl;  
    cout<<m.at("unknownKey")<<endl;

    //size
    cout<<m.size()<<endl;

    //to check presence
    cout<<m.count("mera")<<endl;

    //erase
    m.erase("goodguyPJ");
    cout<<m.size()<<endl;

    //iterator
    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<< it->first << " "<< it->second<<endl;
        it++;
    }
    
 
  return 0;
}