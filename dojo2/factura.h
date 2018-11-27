#include <iostream>
#include "object.h"
#include "m_string.h"
#pragma once// es valido, de momento

using namespace std;

class factura: public object
{
    m_string nombre;
    m_string nit;
    public:
        factura(const m_string &nombre, const m_string &nit);
        void agregar_item(size_t, const m_string&);
        void agregar_descuento(size_t desc);
        void mostrar() const;

};