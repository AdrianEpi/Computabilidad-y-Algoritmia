#include <cstdio>
#include <vector>
#include <random>
#include <iostream>

#include "sorted_vector_t.hpp"

#define LIMIT 999
#define SIZE   80

using namespace std;

int main(void)
{	
    default_random_engine generator;
    uniform_int_distribution<int> distribution(-LIMIT, LIMIT);    
    
    CyA::sorted_vector_t v;
    
    for(int i = 0; i < SIZE; i++)
        v.push_back(distribution(generator));
        
    cout << v << endl;
    
    v.merge_sort();
    
    cout << v << endl;

    cout << "modificacion:" << endl << endl;
    for (int i = 0; i < SIZE-1; i++)
    {
    	if (v.modificacion(v[i], v[i+1]))
    		cout << v.mod[i] << " ";
    	else 
    	{
    		cout << "Error" << endl;
    		exit(0);
    	}

    }
    cout << endl << "Correcto" << endl;
    
	return 0;
}
