#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
vector<string> words;

int main()
{  
    int n;
    cin >> n;
    while (n--){
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
            string u, t;
            ss >> u >> t;
            queue<string> q;
            map<string, int> visitado;
            visitado[u] = 0;
            q.push(u);
            while (!q.empty() and  visitado.count(t) == 0){
                string x;
                x = q.front();
                q.pop();
                for (int i = 0; i < words.size(); ++i){
                    if (! (visitado.count(words[i]) and u.length() == words[i].length())){
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
             

            cout << u << " " << t << " " << visitado[t] << endl;
        }
        
    
        if (n){
        
        cout << endl;
        
        }
    }


    return 0;
}
































