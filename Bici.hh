/** @file Bici.hh
 * @brief Especificación de la clase Bici
 */

#ifndef BICI_HH
#define BICI_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
using namespace std;
#endif

/**
 * @class Bici
 * @brief Representa una bicicleta asignada a una estación.
 *
 */

class Bici
{

private:
    string bici_id;
    list<pair<string, string>> viajes; // vector de los viajes hechos (identificador estacion origen y estacion destino)
    string estacion_asignada;            // identificador de la estacion a la que está asignada la bici

public:
    /** @name Constructoras
     *  Documentación de las funciones constructoras de la clase Bici.
     */
    ///@{

    /**
     * @brief Constructora vacía de la clase Bici.
     * \pre <em>Cierto.</em>
     * \post Crea una bicicleta vacía.
     */

    Bici();

    /**
     * @brief Constructora de la clase Bici.
     * \pre <em>Cierto.</em>
     * \post Crea una bicicleta con identificador y con una estación asignada.
     */

    Bici(const string &identificador, const string &identificador_estacion);

    ///@}

    /** @name Consultoras
     *  Documentación de las funciones consultoras de la clase Bici.
     */
    ///@{

    /**
     * @brief Consultora del identificador de la bicicleta.
     * \pre La bicicleta no está vacía.
     * \post Devuelve el identificador de la bicicleta.
     */

    string consultar_bici_id() const;

    /**
     * @brief Consultora de la estación asignada de la bicicleta.
     * \pre La bici no está vacía.
     * \post Devuelve el identificador de la estación a la que está asignada la bicicleta.
     */

    string consultar_estacion_asignada() const;

    ///@}

    /** @name Modificadoras
     *  Documentación de las funciones modificadoras de la clase Bici.
     */
    ///@{

    /**
     * @brief Modificadora de la estación asignada de la bicicleta.
     * \pre La bicicleta no está vacía y la estación representada por su identificador existe,
     * no está llena y no es en la que la bicicleta ya está asignada.
     * \post La estación a la que la bicicleta está asignada pasa a ser la representada por el 
     * parámetro y se añade el viaje de la estación antigua a la nueva.
     */

    void modificar_estacion_asignada(const string &identificador_estacion);

    /**
     * @brief Modificadora que añade un viaje a la Bici.
     * \pre Los identificadores id1 e id2 son identificadores válidos de estaciones que existen y 
     * son distintas.
     * \post Se añaden id1 e id2 como viaje a la bici.
     */

    void anadir_viaje(const string &id1, const string &id2);

    ///@}

    /** @name Escritoras
     *  Documentación de las funciones escritoras de la clase Bici.
     */
    ///@{

    /**
     * @brief Escritora de los viajes que ha hecho la bicicleta de estación a estación.
     * \pre <em>Cierto.</em>
     * \post Se escriben los viajes que ha hecho la bicicleta por el canal estándar de salida.
     */

    void escribir_viajes();

    ///@}
};

#endif