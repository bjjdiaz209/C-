#include "factura.h"

factura::factura(const m_string &nombre, const m_string &nit)
: nombre{nombre},nit{nit}{
}

void factura::agregar_item(size_t , const m_string &)
{
}
void factura::agregar_descuento(size_t desc)
{
}
void factura::mostrar() const
{
}

