#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

char word[1001];
int L,best,found[1000];
vector<int> poss;


class Node{
private:
    int cont;
    Node *children[4];
public:
    Node(){
        cont = 0;
        children[0] = NULL;
        children[1] = NULL;
        children[2] = NULL;
        children[3] = NULL;
    }

friend class Trie;
};

class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();  
    }
    
    void insert(int pos){
        Node *p = root;
        string aux;
        int nxt;
        for(int i = pos;i < L;++i){
            aux += word[i];
            
            if(word[i] == 'A'){
                 nxt = 0;
            }else if(word[i] == 'C'){
                nxt = 1;
            }
            else if(word[i] == 'G'){
                nxt = 2;
            }else if(word[i] == 'T'){
                nxt = 3;
            }
            

            if(p->children[nxt] == NULL)
                p->children[nxt] = new Node();
                p = p->children[nxt];
                ++p->cont;
            
            if(p->cont > 1){
                if(i-pos+1 > best){
                    poss.clear();
                    best = i-pos+1;
                }
                
                if(i-pos+1 == best){
                    poss.push_back(pos);
                    found[pos] = p->cont;
                }
            }
        }
    }
};

int main(){
    int casos;
    Trie *T;
    T = new Trie();
    cin>>casos;
    
    while(casos--){
        cin>>word;
        L = strlen(word);

        best = -1;
        
        
        poss.clear();
        
        for(int i = 0;i < L;++i){
            T->insert(i);
        }
        
        delete(T);
        
        if(best == -1){
            cout<<"No repetitions found!"<<endl;

        }else{
            string ans = "Z";
            int ind,sz = poss.size();
            
            for(int i = 0;i < sz;++i){
                int x = poss[i];
                string aux = string(word + x,word + (x+best));
                
                if(aux <= ans){
                    ans = aux;
                    ind = x;
                }
            }
            
            printf("%s %d\n",ans.c_str(),found[ind]);
        }
    }
    
    return 0;
}