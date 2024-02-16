/**
 * @mainpage Práctica de PRO2: Gestión de un sistema de bicing bifurcado.

En este archivo se construye un programa modular que ofrece un menú de opciones para gestionar un sistema de bicing bifurcado. Se introducen las clases <em>Bici</em>, <em>Cjt_Bicis</em>, <em>Estacion</em> y <em>Bicing</em>.

Para ver la implementación del programa principal, haga @ref program.cc "clic".
*/

/** @file program.cc
    @brief Programa principal para la práctica de PRO2 sobre la <em>gestión de un sistema de bicing bifurcado</em>.
*/

#include "Cjt_Bicis.hh"
#include "Bicing.hh"

/** @brief Programa principal para el la práctica de PRO2 sobre la <em>gestión de un sistema de bicing</em>.
 */

int main()
{
    Bicing bicing;
    Cjt_Bicis conjunto_bicis;
    string op;
    while (cin >> op and op != "fin")
    {
        if (op == "alta_bici" or op == "ab")
        {
            string identificador_bici;
            string identificador_estacion;
            cin >> identificador_bici >> identificador_estacion;
            cout << "#ab " << identificador_bici << " " << identificador_estacion << endl;
            if (conjunto_bicis.existe_bici(identificador_bici))
                cout << "error: la bici ya existe" << endl;
            else if (not bicing.existe_estacion(identificador_estacion))
                cout << "error: la estacion no existe" << endl;
            else if (bicing.estacion_llena(identificador_estacion))
                cout << "error: la bici no cabe" << endl;
            else
            {
                bicing.alta_bici(identificador_bici, identificador_estacion);
                conjunto_bicis.conjunto_bicis_anadir(identificador_bici, identificador_estacion);
            }
        }
        else if (op == "baja_bici" or op == "bb")
        {
            string identificador_bici;
            cin >> identificador_bici;
            cout << "#bb " << identificador_bici << endl;
            if (not conjunto_bicis.existe_bici(identificador_bici))
                cout << "error: la bici no existe" << endl;
            else
            {
                string id_est = conjunto_bicis.bicing_consultar_estacion_asignada(identificador_bici);
                bicing.baja_bici(identificador_bici, id_est);
                conjunto_bicis.conjunto_bicis_eliminar(identificador_bici);
            }
        }
        else if (op == "estacion_bici" or op == "eb")
        {
            string identificador_bici;
            cin >> identificador_bici;
            cout << "#eb " << identificador_bici << endl;
            if (not conjunto_bicis.existe_bici(identificador_bici))
                cout << "error: la bici no existe" << endl;
            else
            {
                cout << conjunto_bicis.bicing_consultar_estacion_asignada(identificador_bici) << endl;
            }
        }
        else if (op == "viajes_bici" or op == "vb")
        {
            string identificador_bici;
            cin >> identificador_bici;
            cout << "#vb " << identificador_bici << endl;
            if (not conjunto_bicis.existe_bici(identificador_bici))
                cout << "error: la bici no existe" << endl;
            else
            {
                conjunto_bicis.conjunto_bicis_escribir_viajes(identificador_bici);
            }
        }
        else if (op == "mover_bici" or op == "mb")
        {
            string identificador_bici;
            string identificador_estacion;
            cin >> identificador_bici >> identificador_estacion;
            cout << "#mb " << identificador_bici << " " << identificador_estacion << endl;
            if (not conjunto_bicis.existe_bici(identificador_bici))
                cout << "error: la bici no existe" << endl;
            else if (not bicing.existe_estacion(identificador_estacion))
                cout << "error: la estacion no existe" << endl;
            else if (conjunto_bicis.bicing_consultar_estacion_asignada(identificador_bici) == identificador_estacion)
                cout << "error: la bici ya esta en el sitio" << endl;
            else if (bicing.estacion_llena(identificador_estacion))
                cout << "error: la bici no cabe" << endl;
            else
            {
                string est_og = conjunto_bicis.bicing_consultar_estacion_asignada(identificador_bici);
                bicing.mover_bici(identificador_bici, identificador_estacion, est_og);
                conjunto_bicis.conjunto_bicis_mover(identificador_bici, identificador_estacion, est_og);
            }
        }
        else if (op == "bicis_estacion" or op == "be")
        {
            string identificador_estacion;
            cin >> identificador_estacion;
            cout << "#be " << identificador_estacion << endl;
            if (not bicing.existe_estacion(identificador_estacion))
                cout << "error: la estacion no existe" << endl;

            else
            {
                bicing.bicis_estacion(identificador_estacion);
            }
        }
        else if (op == "modificar_capacidad" or op == "mc")
        {
            string identificador_estacion;
            int capacidad;
            cin >> identificador_estacion >> capacidad;
            cout << "#mc " << identificador_estacion << " " << capacidad << endl;
            if (not bicing.existe_estacion(identificador_estacion))
                cout << "error: la estacion no existe" << endl;
            else if (capacidad < bicing.bicing_consultar_numero_bicis_estacion(identificador_estacion))
                cout << "error: capacidad insuficiente" << endl;
            else
            {
                bicing.modificar_capacidad(identificador_estacion, capacidad);
            }
        }
        else if (op == "plazas_libres" or op == "pl")
        {
            cout << "#pl" << endl;
            cout << bicing.consultar_plazas_libres() << endl;
        }
        else if (op == "subir_bicis" or op == "sb")
        {
            cout << "#sb" << endl;
            bicing.subir_bicis(conjunto_bicis);
        }
        else if (op == "asignar_estacion" or op == "ae")
        {
            string identificador_bici;
            cin >> identificador_bici;
            cout << "#ae " << identificador_bici << endl;
            if (conjunto_bicis.existe_bici(identificador_bici))
                cout << "error: la bici ya existe" << endl;
            else if (bicing.consultar_plazas_libres() <= 0)
                cout << "error: no hay plazas libres" << endl;
            else
            {
                cout << bicing.asignar_estacion(identificador_bici, conjunto_bicis) << endl;
            }
        }
    }
}