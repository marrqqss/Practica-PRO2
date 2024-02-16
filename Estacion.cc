#include "Estacion.hh"

Estacion::Estacion()
{
    estacion_id = "";
    capacidad = 0;
    nbicis = 0;
}

Estacion::Estacion(const string &identificador, const int capacidad)
{
    estacion_id = identificador;
    this->capacidad = capacidad;
    nbicis = 0;
}

int Estacion::consultar_capacidad() const
{
    return capacidad;
}

int Estacion::consultar_numero_bicis() const
{
    return nbicis;
}

string Estacion::consultar_primera_bici() const
{
    return *(bicis_estacion.begin());
}

void Estacion::estacion_anadir_bici(const string &id_bici)
{
    bicis_estacion.insert(id_bici);
    ++nbicis;
}

void Estacion::estacion_eliminar_bici(const string &id_bici)
{
    bicis_estacion.erase(id_bici);
    --nbicis;
}

void Estacion::modificar_capacidad(const int capacidad)
{
    this->capacidad = capacidad;
}

void Estacion::escribir_bicis()
{
    for (set<string>::const_iterator it = bicis_estacion.begin(); it != bicis_estacion.end(); ++it)
        cout << *it << endl;
}