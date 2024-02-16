#include "Cjt_Bicis.hh"

void Cjt_Bicis::conjunto_bicis_anadir_viaje(const string &id_bici, const string &id1, const string &id2)
{
    conjunto_bicis[id_bici].anadir_viaje(id1, id2);
}

Cjt_Bicis::Cjt_Bicis()
{
}

string Cjt_Bicis::bicing_consultar_estacion_asignada(const string &id_bici)
{
    return conjunto_bicis[id_bici].consultar_estacion_asignada();
}

Bici Cjt_Bicis::consultar_bici(const string &id_bici)
{
    return conjunto_bicis[id_bici];
}

bool Cjt_Bicis::existe_bici(const string &id_bici) const
{
    if (conjunto_bicis.find(id_bici) != conjunto_bicis.end())
        return true;
    return false;
}

void Cjt_Bicis::conjunto_bicis_anadir(const string &identificador_bici, const string &identificador_estacion)
{
    conjunto_bicis[identificador_bici] = Bici(identificador_bici, identificador_estacion);
}

void Cjt_Bicis::conjunto_bicis_eliminar(const string &id_bici)
{
    conjunto_bicis.erase(id_bici);
}

void Cjt_Bicis::conjunto_bicis_modificar_estacion(const string &id_bici, const string &id_est)
{
    conjunto_bicis[id_bici].modificar_estacion_asignada(id_est);
}

void Cjt_Bicis::conjunto_bicis_mover(const string &id_bici, const string &id1, const string &id2)
{
    conjunto_bicis_anadir_viaje(id_bici, id1, id2);
    conjunto_bicis_modificar_estacion(id_bici, id1);
}

void Cjt_Bicis::conjunto_bicis_escribir_viajes(const string &id_bici)
{
    conjunto_bicis[id_bici].escribir_viajes();
}