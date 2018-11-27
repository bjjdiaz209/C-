#include <iostream>
#include "object.h"
#include "m_string.h"
#pragma once// es valido, de momento

using namespace std;

class factura: public object
{
    public:
        void agregar_item(size_t, const m_string&);

};