#include <iostream>
#include "m_string.h"
#include "object.h"

using namespace std;

class producto : public object
{
    m_string nombre;
    m_string proveedor;
    m_string codigo;
    size_t stock;
    double precio;

    public:
    producto(const m_string&, const m_string&, const m_string&, size_t, double);
    
};