#include "sorted_vector_t.hpp"

#include <climits>
#include <iomanip>

namespace CyA
{

void sorted_vector_t::merge_sort(void)
{
    merge_sort(0, size() - 1);
}

void sorted_vector_t::write(ostream& os) const
{
    const int sz = size();

    os << "< ";
    for(int i = 0; i < sz; i++)
        os << setw(5) << at(i);
    os << "> ";
}


void sorted_vector_t::merge_sort(int l, int r)//indices del vector de elementos
{
    if (l < r) { //mientras la longitud del vector sea mayor que 1 (l es el primer indice por lo tanto uno)
        int c = (l + r) / 2;
        merge_sort(l, c); //llamada recursiva para partir entre 1 y la mitad
        merge_sort(c + 1, r);
        merge(l, c, r);  //fusionamos los dos vectores l= vector izquierdo, 
    }//dividimos, dividimos y luego fusionamos
}


////////////////////////////////////////////////////////////////////////////
// FUSIÓN CON CENTINELA
////////////////////////////////////////////////////////////////////////////

void sorted_vector_t::create_vector_sentinel(int l, int r, vector<int>& v)
{
    v.clear();
    for(int i = l; i <= r; i ++)
        v.push_back(at(i));
    v.push_back(INT_MAX);
}

void sorted_vector_t::merge(int l, int c, int d)
{
    vector<int> vector1;
    vector<int> vector2;
    create_vector_sentinel(l, c, vector1);
    create_vector_sentinel(c + 1, d, vector2);
    merge(vector1, vector2, l);
}

void sorted_vector_t::merge(const vector<int>& v1, const vector<int>& v2, int l)
{
    const int size_ = v1.size() + v2.size() - 2;   
    int index_1 = 0;   
    int index_2 = 0;   
    for(int i = 0; i < size_; i++) 
    {
        if (v1[index_1] < v2[index_2]) 
        {  
            at(l + i) = v1[index_1];   
            index_1 ++;    
        } else 
        {    
            at(l + i) = v2[index_2];   
            index_2 ++;    
        }  
    } 
}

bool sorted_vector_t::modificacion( int num1, int num2 )
{
    int aux;
    aux = num2 - num1;
    if (aux >= 0)
    {
        mod.push_back(aux);
        return true;
    }
    else
        return false;
}

////////////////////////////////////////////////////////////////////////////

}


ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v)
{
    v.write(os);
    return os;
}
