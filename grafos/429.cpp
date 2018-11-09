#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;
vector<string> words;
map<string, int> visitado;


void bfs(string u){
	queue<string> q;
    visitado[u] = 0;
    q.push(u);
    while (!q.empty()){
        u = q.front();
        q.pop();
        for (int i = 0; i < words.size(); ++i){
                    if (! (visitado.count(words[i]) )){
                        int cont = 0;
                        for (int j = 0; j < u.length(); ++j)
                            if (u[j] != words[i][j]){
                                ++cont;
                            }
                        if (cont == 1){
                            visitado[words[i]] = visitado[u] + 1;
                            q.push(words[i]);
                        }
                        
                    }
                    
                }
            }
                
}










int main()
{  
    int n;
    cin >> n;
    while ( n-- ){
        string word;
        while(word != "*"){
            cin >> word,
            words.push_back(word);
        }
        cin.ignore();
        string line;
        while (getline(cin, line) and line != "")
        {
            stringstream ss(line);
            string x, y;
            ss >> x >> y;
            queue<string> q;
            visitado[x] = 0;
            q.push(x);
            while (!q.empty()){
                x = q.front();
                q.pop();
            for (int i = 0; i < words.size(); ++i){
                    if (! (visitado.count(words[i]) )){
                        int cont = 0;
                        for (int j = 0; j < x.length(); ++j)
                            if (x[j] != words[i][j]){
                                ++cont;
                            }
                        if (cont == 1){
                            visitado[words[i]] = visitado[x] + 1;
                            q.push(words[i]);
                        }
                        
                    }
                    
                }
            }    
            cout<<x<<" "<<y<<" "<<visitado[y]<<endl;
        }
        
    }
    if (n){
    
    cout << endl;
    
    }
    return 0;
}