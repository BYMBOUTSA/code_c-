#include<cstdlib>
#include<cassert>
#include<sstream>
#include<stack>
#include <iostream>
#include <ctime>

using namespace std;

const int M = 4; // taille de la matrice
const int N = 4;

const int MAX_VAL = 100; // valeur maximale pour les éléments de la matrice
const int MAX_ADD = 20; // valeur maximale pour l'ajout de valeur

class Matrice
{
private:
    int M, N;
    const int size;
    int *mat;
    stack<int*> undoStack;
    stack<int*> redoStack;
public:
    // constructeur
    Matrice(int m, int n, int v=0):M(m), N(n), size(m*n), mat(new int [size])
    {
        for(int i=0; i<size; i++)
        {
            this->mat[i]=v;
        }
    }
    // constructeur de copie
    Matrice(const Matrice& m):M(m.M), N(m.N), size(m.size), mat(new int [size])
    {
        for(int i=0; i<size; i++)
        {
            this->mat[i]=m.mat[i];
        }
    }
    // destructeur
    ~Matrice()
    {
        delete[] this->mat;
    }
    // methodes d'accès et de modification des éléments de la matrice
    int& get(int i, int j) const
    {
        int index = N * i + j;
        assert(index >= 0 && index < this->size);
        return mat[index];
    }
    int& operator()(int i, int j)const
    {
        return this->get(i, j);
    }
    // setter pour modifier la valeur d'un élément spécifique de la matrice
    void SetValue(int i, int j, int v)
    {
        int* prevState = new int[size];
        for (int k=0; k<size; k++)
        {
            prevState[k] = mat[k];
        }
        undoStack.push(prevState);
        redoStack = stack<int*>();

        this->get(i,j) = v;
    }
    // méthode pour ajouter une valeur à tous les éléments de la matrice
    void AddValue(int v)
    {
        int* prevState = new int[size];
        for (int k=0; k<size; k++)
        {
            prevState[k] = mat[k];
        }
        undoStack.push(prevState);
        redoStack = stack<int*>();

        for(int i=0; i<size; i++)
        {
            this->mat[i]+=v;
        }
    }
    // méthode pour annuler la dernière modification
    void Undo()
    {
        if(!undoStack.empty())
        {
            redoStack.push(mat);
            mat = undoStack.top();
            undoStack.pop();
        }
    }
    // méthode pour rétablir la dernière modification annulée
    void Redo()
    {
        if(!redoStack.empty())
        {
            undoStack.push(mat);
            mat = redoStack.top();
            redoStack.pop();
        }
    }

    string toString() const 
    {
        ostringstream s;
        // on parcourt les lignes et colonnes de notre élément mat
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
           
                s << mat[N * i + j] << " ";
                s << "\n";  
        }
        return s.str();
    }

    friend ostream & operator<<(ostream & f, const Matrice& m)
    {
        return f << m.toString();
    }
};


int main() {
    srand(time(NULL)); // initialisation du générateur de nombres aléatoires

    Matrice m(M, N);
    char code;

    cout << m << " ------------------" << std::endl;
    cout << " cmd > ";
    while (std::cin >> code) {
        switch (code) {
            case 's': {
                int l = rand() % M;
                int c = rand() % N;
                int v = rand() % MAX_VAL;
                m.SetValue(l, c, v);
                std::cout << "SetValue(" << l << ", " << c << ", " << v << ")" << std::endl;
                break;
            }
            case 'a': {
                int v = rand() % MAX_ADD + 1;
                m.AddValue(v);
                std::cout << "AddValue(" << v << ")" << std::endl;
                break;
            }
            case 'q': {
                std::cout << "Quit" << std::endl;
                return 0;
            }
            default:
                std::cout << "Unknown command" << std::endl;
                break;
        }
        std::cout << m << " ------------------" << std::endl;
        std::cout << " cmd > ";
    }
    return 0;
}

