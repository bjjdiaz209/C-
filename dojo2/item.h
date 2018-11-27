#include <iostream>
#include "object.h"
#include "m_string.h"

using namespace std;

class item : public object
{
    size_t cant;
    m_string codigo;
    
    public:
        item(size_t , const m_string&);

};