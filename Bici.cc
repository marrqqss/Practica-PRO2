#include "Bici.hh"

Bici::Bici()
{
    bici_id = "";
    estacion_asignada = "";
}

Bici::Bici(const string &identificador, const string &identificador_estacion)
{
    bici_id = identificador;
    estacion_asignada = identificador_estacion;
}

string Bici::consultar_bici_id() const
{
    return bici_id;
}

string Bici::consultar_estacion_asignada() const
{
    return estacion_asignada;
}

void Bici::modificar_estacion_asignada(const string &identificador_estacion)
{
    estacion_asignada = identificador_estacion;
}

void Bici::anadir_viaje(const string &id1, const string &id2)
{
    viajes.push_back(make_pair(id2, id1));
}

void Bici::escribir_viajes()
{
    for(list<pair<string,string>>::const_iterator it = viajes.begin(); it != viajes.end(); ++it)
        cout << it->first << " " << it->second << endl;
}