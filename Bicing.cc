#include "Bicing.hh"

void Bicing::leer_arbol(BinTree<string> &a)
{
    string estacion;
    cin >> estacion;
    if (estacion != "#")
    {
        int capacidad;
        cin >> capacidad;
        plazas_libres += capacidad;
        Estacion e(estacion, capacidad);
        estaciones_bicing[estacion] = e;
        BinTree<string> izq;
        leer_arbol(izq);
        BinTree<string> der;
        leer_arbol(der);
        a = BinTree<string>(estacion, izq, der);
    }
}

void Bicing::aux_subir_bicis(const BinTree<string> &a, Cjt_Bicis &conjunto_bicis)
{
    if (not a.empty())
    {
        if (not estacion_llena(a.value()))
        {
            if (not a.left().empty()) //el arbol tiene 0 o 2 hijos, con comprobar uno es suficiente
            {
                string est_padre = a.value();
                string est_left = a.left().value();
                string est_right = a.right().value();
                while (not estacion_llena(est_padre) and (estaciones_bicing[est_left].consultar_numero_bicis() > 0 or estaciones_bicing[est_right].consultar_numero_bicis() > 0))
                {
                    int num_bicis_left = estaciones_bicing[est_left].consultar_numero_bicis();
                    int num_bicis_right = estaciones_bicing[est_right].consultar_numero_bicis();
                    if (num_bicis_left > num_bicis_right or num_bicis_right <= 0) // caso izq > der, se mueve desde izq
                    {
                        int num_bicis_mover = num_bicis_left - num_bicis_right;
                        int i = 0;
                        while (i < num_bicis_mover and not estacion_llena(est_padre))
                        {
                            string bici_id = estaciones_bicing[est_left].consultar_primera_bici();
                            estaciones_bicing[est_padre].estacion_anadir_bici(bici_id);
                            estaciones_bicing[est_left].estacion_eliminar_bici(bici_id);
                            conjunto_bicis.conjunto_bicis_modificar_estacion(bici_id, est_padre);
                            ++i;
                        }
                    }
                    else if (num_bicis_left < num_bicis_right or num_bicis_left <= 0) // caso izq < der, se mueve desde der
                    {
                        int num_bicis_mover = num_bicis_right - num_bicis_left;
                        int i = 0;
                        while (i < num_bicis_mover and not estacion_llena(est_padre))
                        {
                            string bici_id = estaciones_bicing[est_right].consultar_primera_bici();
                            estaciones_bicing[est_padre].estacion_anadir_bici(bici_id);
                            estaciones_bicing[est_right].estacion_eliminar_bici(bici_id);
                            conjunto_bicis.conjunto_bicis_modificar_estacion(bici_id, est_padre);
                            ++i;
                        }
                    }
                    else if (estaciones_bicing[est_left].consultar_numero_bicis() == estaciones_bicing[est_right].consultar_numero_bicis()) // caso izq == der, se mueve bici con menor id
                    {
                        if (estaciones_bicing[est_left].consultar_primera_bici() < estaciones_bicing[est_right].consultar_primera_bici()) // caso vaciar izq
                        {
                            string bici_id = estaciones_bicing[est_left].consultar_primera_bici();
                            estaciones_bicing[est_padre].estacion_anadir_bici(bici_id);
                            estaciones_bicing[est_left].estacion_eliminar_bici(bici_id);
                            conjunto_bicis.conjunto_bicis_modificar_estacion(bici_id, est_padre);
                        }
                        else
                        {
                            string bici_id = estaciones_bicing[est_right].consultar_primera_bici();
                            estaciones_bicing[est_padre].estacion_anadir_bici(bici_id);
                            estaciones_bicing[est_right].estacion_eliminar_bici(bici_id);
                            conjunto_bicis.conjunto_bicis_modificar_estacion(bici_id, est_padre);
                        }
                    }
                }
            }
        }
        aux_subir_bicis(a.left(), conjunto_bicis);
        aux_subir_bicis(a.right(), conjunto_bicis);
    }
}

pair<int, int> Bicing::calcular_coeficientes(const BinTree<string> &a) // first = plazas libres, second = numero de estaciones
{
    if (a.empty())
    {
        return make_pair(0, 0);
    }
    else
    {
        string estacion = a.value();
        pair<int, int> izq = calcular_coeficientes(a.left());
        pair<int, int> der = calcular_coeficientes(a.right());
        int pl = izq.first + der.first + (estaciones_bicing[estacion].consultar_capacidad() - estaciones_bicing[estacion].consultar_numero_bicis());
        int estaciones = izq.second + der.second + 1;
        if (not estacion_llena(estacion))
        {
            double coeficiente = double(double(pl) / double(estaciones));
            if ((id_max_coeficiente == "NULL" and max_coeficiente == -1) or (coeficiente > max_coeficiente) or (coeficiente == max_coeficiente and estacion < id_max_coeficiente))
            {
                id_max_coeficiente = estacion;
                max_coeficiente = coeficiente;
            }
        }
        return make_pair(pl, estaciones);
    }
}

Bicing::Bicing()
{
    plazas_libres = 0;
    id_max_coeficiente = "NULL";
    max_coeficiente = -1;
    leer_arbol(bicing);
}

int Bicing::consultar_plazas_libres() const
{
    return plazas_libres;
}

bool Bicing::existe_estacion(const string &id_estacion) const
{
    if (estaciones_bicing.find(id_estacion) == estaciones_bicing.end())
        return false;
    return true;
}

bool Bicing::estacion_llena(const string &id_estacion)
{
    if (estaciones_bicing[id_estacion].consultar_numero_bicis() < estaciones_bicing[id_estacion].consultar_capacidad())
        return false;
    return true;
}

int Bicing::bicing_consultar_numero_bicis_estacion(const string &id_estacion)
{
    return estaciones_bicing[id_estacion].consultar_numero_bicis();
}

void Bicing::alta_bici(const string &identificador_bici, const string &identificador_estacion)
{
    estaciones_bicing[identificador_estacion].estacion_anadir_bici(identificador_bici);
    --plazas_libres;
}

void Bicing::baja_bici(const string &identificador_bici, const string &identificador_estacion)
{
    estaciones_bicing[identificador_estacion].estacion_eliminar_bici(identificador_bici);
    ++plazas_libres;
}

void Bicing::mover_bici(const string &identificador_bici, const string &identificador_estacion, const string &identificador_estacion_og)
{
    estaciones_bicing[identificador_estacion_og].estacion_eliminar_bici(identificador_bici); // borramos bici de la estacion original
    estaciones_bicing[identificador_estacion].estacion_anadir_bici(identificador_bici);      // añadimos bici a la nueva estacion
}

void Bicing::modificar_capacidad(const string &identificador_estacion, const int capacidad)
{
    int capacidad_og = estaciones_bicing[identificador_estacion].consultar_capacidad();
    estaciones_bicing[identificador_estacion].modificar_capacidad(capacidad);
    plazas_libres += capacidad - capacidad_og;
}

void Bicing::subir_bicis(Cjt_Bicis &conjunto_bicis)
{
    aux_subir_bicis(bicing, conjunto_bicis);
}

string Bicing::asignar_estacion(const string &identificador_bici, Cjt_Bicis &conjunto_bicis)
{
    id_max_coeficiente = "NULL";
    max_coeficiente = -1;
    calcular_coeficientes(bicing);
    alta_bici(identificador_bici, id_max_coeficiente);
    conjunto_bicis.conjunto_bicis_anadir(identificador_bici, id_max_coeficiente);
    return id_max_coeficiente;
}

void Bicing::bicis_estacion(const string &identificador_estacion)
{
    estaciones_bicing[identificador_estacion].escribir_bicis();
}