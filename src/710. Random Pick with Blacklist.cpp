#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <random>
using namespace std;

class Solution {
private:
    unordered_map<int, int> mapping; // Mapeia números bloqueados para números válidos
    int m; // Quantidade de números disponíveis
    mt19937 gen{random_device{}()}; // Gerador de números aleatórios
    uniform_int_distribution<int> dist; // Distribuição uniforme

public:
    // Construtor: inicializa o conjunto de números válidos e o mapeamento
    Solution(int n, vector<int>& blacklist) {
        m = n - (int)blacklist.size();
        unordered_set<int> blackSet(blacklist.begin(), blacklist.end());

        int last = n - 1;
        for (int b : blacklist) {
            if (b < m) {
                // Substitui os números bloqueados por números válidos do final
                while (blackSet.count(last)) last--;
                mapping[b] = last;
                last--;
            }
        }

        dist = uniform_int_distribution<int>(0, m - 1);
    }
    
    // Escolhe um número aleatório que não está na blacklist
    int pick() {
        int x = dist(gen); 
        if (mapping.count(x)) return mapping[x];
        return x;
    }
};

// Função principal para teste
int main() {
    vector<int> blacklist = {2, 3, 5};
    Solution obj(10, blacklist);

    cout << "Valores aleatórios (sem blacklist):" << endl;
    for (int i = 0; i < 10; i++) {
        cout << obj.pick() << " ";
    }
    cout << endl;

    return 0;
}
