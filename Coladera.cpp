#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void mostrar_coladera(vector<int> coladera)
{
    cout << endl;

    for (int i = 0; i < coladera.size(); i++)
        cout << coladera[i] << "\t";

    cout << endl;

}

vector<int> coladera_eratostenes(int n)
{
    vector<int> coladera;
    int primo;  


    for (int i = 2; i <= n; i++)
        coladera.push_back(i);
        
    if (n == 2 || n == 3) 
        return coladera;


    vector<int>::iterator it = coladera.begin();

    primo = *it;  
    do
    {
        vector<int>::iterator it2 = it + 1;

        for(; it2 <= coladera.end(); it2++)
            if(*it2 % primo == 0)
                coladera.erase(it2);

        it++;
        primo = *it;

    } while (pow(primo, 2) < n);

    return coladera;
}

int main()
{
    int n;      
    vector<int> num_primos;
    
    cout << "Numero limite de numeros: ";
    cin >> n;

    num_primos = coladera_eratostenes(n);

    mostrar_coladera(num_primos);

    return 0;
}
