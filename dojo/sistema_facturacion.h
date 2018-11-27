#include <iostream>
#include "m_string.h"
#include "factura.h"
#include "array_list.h"
#pragma once
using namespace std;

class sistema_facturacion
{
    public:
        void agregar_producto(const m_string &nombre, const m_string &marca, const m_string &codigo, size_t cantidad, double precio);
        factura& crear_factura(const m_string &nombre, const m_string &nit = "0");
        array_list obtener_facturas_de_hoy() const;
};