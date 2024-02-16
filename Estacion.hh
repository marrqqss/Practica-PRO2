/** @file Estacion.hh
 * @brief Especificación de la clase Estacion
 */

#ifndef ESTACION_HH
#define ESTACION_HH

#include "Bici.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <set>
using namespace std;
#endif

/**
 * @class Estacion
 * @brief Representa una estación que contiene bicicletas.
 */

class Estacion
{

private:
    string estacion_id;
    int capacidad;              // numero max de bicis
    int nbicis;                 // numero de bicis asignadas a la estacion
    set<string> bicis_estacion; // bicis de la estacion ordenadas por su id

public:
    /** @name Constructoras
     *  Documentación de las funciones constructoras de la clase Estacion.
     */
    ///@{

    /**
     * @brief Constructora vacía de la clase Estacion.
     * \pre <em>Cierto.</em>
     * \post Crea una estación vacía.
     */

    Estacion();

    /**
     * @brief Constructora de la clase Estacion.
     * \pre <em>Cierto.</em>
     * \post Crea una estación con identificador y capacidad, sin bicicletas asignadas.
     */

    Estacion(const string &identificador, const int capacidad);

    ///@}

    /** @name Consultoras
     *  Documentación de las funciones consultoras de la clase Estacion.
     */
    ///@{

    /**
     * @brief Consultora de la capacidad máxima de la estación.
     * \pre La estación no está vacía.
     * \post Devuelve la capacidad máxima de la estación.
     */

    int consultar_capacidad() const;

    /**
     * @brief Consultora del número de bicicletas asignadas a la estación.
     * \pre La estación no está vacía.
     * \post Devuelve la cantidad de bicicletas que están asignadas la estación.
     */

    int consultar_numero_bicis() const;

    /**
     * @brief Consultora de la primera bici de la estacion, es decir, la del id más pequeño.
     * \pre La estación no está vacía y tiene n > 0 bicis.
     * \post Devuelve el id de la primera bici de la estación, la de id más pequeño.
     */

    string consultar_primera_bici() const;

    ///@}

    /** @name Modificadoras
     *  Documentación de las funciones modificadoras de la clase Estacion.
     */
    ///@{

    /**
     * @brief Modificadora que añade una bicicleta a la estación.
     * \pre La bicicleta existe, no está en la estación y cabe en ella.
     * \post Se añade la bicicleta a la estación.
     */

    void estacion_anadir_bici(const string &id_bici);

    /**
     * @brief Modificadora que elimina una bicicleta de la estación.
     * \pre La bicicleta existe y está en la estación.
     * \post La bicicleta desaparece de la estación.
     */

    void estacion_eliminar_bici(const string &id_bici);

    /**
     * @brief Modificadora de la capacidad de la estación.
     * \pre La nueva capacidad es mayor que el número de bicis asignadas a la estación.
     * \post La capacidad de la estación pasa a ser la recibida como parámetro.
     */

    void modificar_capacidad(const int capacidad);

    ///@}

    /** @name Escritoras
     *  Documentación de las funciones escritoras de la clase Estacion.
     */
    ///@{

    /**
     * @brief Escritora de las bicicletas asignadas a la estación.
     * \pre La estación no está vacía.
     * \post Se escriben los ids de las bicicletas asignadas a la estación por el canal estándar de salida.
     */

    void escribir_bicis();

    ///@}
};

#endif