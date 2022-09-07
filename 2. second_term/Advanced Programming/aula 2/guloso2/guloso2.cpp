#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        vector<int> speed;
        stringstream fout(ios_base::app | ios_base::out);
        
        int min_time = 0;
        int val = n;
        
        // inserindo as velocidades no meu vetor de velocidade
        for(int i=0; i<n; i++) {
            int s;
            cin >> s;
            speed.push_back(s);
        }

        sort(speed.begin(), speed.end());
        
        // exitem duas maneiras de percorrer a ponte com o menor tempo:
        // 1. vai o + rápido com o + devagar, o rápido volta, pega o segundo mais devagar, volta, pega o terceiro mais devagar, e por ai vai
        // 2. vai o + rápido com o segundo mais rapido, o mais rapido volta, entrega a lanterna pros 2 mais devagar, chegando do outro lado da ponte, eles entregam pro segundo mais rapido que volta pro outro lado da ponte, e por ai vai
        // ou seja (1) = 2*A + a + b (A=mais rapido, a=mais lento, b=segundo mais lento)
        // (2) = 2*B + A + a (B=segundo mais rapido)
        while(val > 3) {
            int A = speed[0], B = speed[1], a = speed[val-1], b = speed[val-2];

            // se a maneira 1 for mais vantajosa
            if(A+b < 2*B) {
                min_time += 2*A + a + b;
                fout << A << " " << b << endl;
                fout << A << endl;
                fout << A << " " << a << endl;
                fout << A << endl;
            }

            else {
                min_time += 2*B + A + a;
                fout << A << " " << B << endl;
                fout << A << endl;
                fout << b << " " << a << endl;
                fout << B << endl;
            }

            val -= 2;
        }
        // se só faltar um para atravessar, então vai ser o tempo dele
        if(val == 1) {
            min_time += speed[0];
            fout << speed[0] << endl;
        }

        // se faltar dois, então vai ser o tempo do mais devagar
        else if(val == 2) {
            min_time += speed[1];
            fout << speed[0] << " " << speed[1] << endl;
        }
        
        // se faltar 3, entao vai o mais rápido com o mais lento, o rapido volta e vai com o segundo mais rapido
        else {
            min_time += speed[0] + speed[1] + speed[2];
            fout << speed[0] << " " << speed[1] << endl;
            fout << speed[0] << endl;
            fout << speed[0] << " " << speed[2] << endl;
        }

        cout << min_time << endl;
        cout << fout.str();

        if (t)
            cout << endl;
    }

    return 0;
}