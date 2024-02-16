/** @file Bicing.hh
 * @brief Especificación de la clase Bicing
 */

#ifndef BICING_HH
#define BICING_HH

#include "Estacion.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include "Cjt_Bicis.hh"
#include "Bici.hh"
#include "BinTree.hh"
using namespace std;
#endif

/**
 * @class Bicing
 * @brief Representa el conjunto de todas las estaciones del sistema de Bicing bifurcado.
 */

class Bicing
{

private:
    map<string, Estacion> estaciones_bicing; // mapa de todas las estaciones que existen ordenadas por su identificador
    BinTree<string> bicing;                  // BinTree formado por los identificadores de las estaciones
    int plazas_libres;                       // plazas libres entre todas las estaciones del sistema
    string id_max_coeficiente;               // id de la estación con el máximo coeficiente de desocupación general
    double max_coeficiente;                  // coeficiente maximo de desocupación general

    /**
     * @brief Función auxiliar para leer el BinTree de strings formado por los ids de las estaciones del Bicing.
     * \pre <em>Cierto.</em>
     * \post Se registran las estaciones en el sistema de Bicing.
     */

    void leer_arbol(BinTree<string> &a);

    /**
     * @brief Función auxiliar para subir bicis.
     * \pre <em>Cierto.</em>
     * \post Se reestructura la ubicación de las bicis en el sistema de Bicing, moviéndolas en dirección a la primera estación y 
     * llenando las estaciones (si es posible) a partir de sus dos subestaciones siguientes.Las dos subestaciones de cada estación
     * quedan con un número de bicis lo más equilibrado posible.
     */

    void aux_subir_bicis(const BinTree<string> &a, Cjt_Bicis &conjunto_bicis);

    /**
     * @brief Función auxiliar para asignar estación.
     * \pre <em>Cierto.</em>
     * \post Devuelve en el first las plazas libres a partir de la estación de la raíz del arbol y el número de estaciones que 
     * hay a partir de la estación de la raíz del arbol. Además, el id_max_coeficiente de Bicing pasa a ser el id de la estación 
     * con el máximo coeficiente de desocupación general y max_coeficiente pasa a ser el máximo coeficiente de desocupación general.
     */

    pair<int, int> calcular_coeficientes(const BinTree<string> &a);

public:
    /** @name Constructoras
     *  Documentación de las funciones constructoras de la clase Bicing.
     */
    ///@{

    /**
     * @brief Constructora de la clase Bicing.
     * \pre <em>Cierto.</em>
     * \post Crea un Bicing/conjunto de estaciones a partir de las estaciones leidas por el canal estándar de entrada.
     */

    Bicing();

    ///@}

    /** @name Consultoras
     *  Documentación de las funciones consultoras de la clase Bicing.
     */
    ///@{

    /**
     * @brief Consultora de las plazas libres en el sistema de Bicing.
     * \pre <em>Cierto.</em>
     * \post Devuelve las plazas libres del sistema de Bicing.
     */

    int consultar_plazas_libres() const;

    /**
     * @brief Consultora de la existencia de una estacion en el sistema de Bicing.
     * \pre <em>Cierto.</em>
     * \post Devuelve true si la estación existe en el sistema de Bicing, false en caso contrario.
     */

    bool existe_estacion(const string &id_estacion) const;

    /**
     * @brief Consultora para ver si una estacion del sistema de Bicing está llena.
     * \pre La estación existe en el Bicing.
     * \post Devuelve true si la estacion está llena, false en caso contrario.
     */

    bool estacion_llena(const string &id_estacion);

    /**
     * @brief Consultora del numero de bicis dentro de una estación del sistema de Bicing.
     * \pre La estación existe en el Bicing.
     * \post Devuelve el numero de bicis en la estacion del sistema de Bicing.
     */

    int bicing_consultar_numero_bicis_estacion(const string &id_estacion);

    ///@}

    /** @name Modificadoras
     *  Documentación de las funciones modificadoras de la clase Bicing.
     */
    ///@{

    /**
     * @brief Modificadora que añade una bicicleta a una estación del sistema de Bicing.
     * \pre La bicicleta no existe, la estación existe y la bicicleta cabe en la estación
     * \post Crea una bicicleta y se añade a la estación.
     */

    void alta_bici(const string &identificador_bici, const string &identificador_estacion);

    /**
     * @brief Modificadora que elimina una bicicleta de una estación del sistema de Bicing.
     * \pre La estación existe y la bicicleta existe en la estación.
     * \post Elimina la bicicleta de la estación del sistema de Bicing.
     */

    void baja_bici(const string &identificador_bici, const string &identificador_estacion);

    /**
     * @brief Modificadora que mueve una bicicleta de una estación a otra, ambas del sistema de Bicing.
     * \pre La bicicleta existe, la estación existe, la estación destino es distinta de la origen y la bicicleta 
     * cabe en la estación destino.
     * \post La bicicleta pasa a estar en la estación de destino.
     */

    void mover_bici(const string &identificador_bici, const string &identificador_estacion, const string &identificador_estacion_og);

    /**
     * @brief Modificadora de la capacidad de una estación del sistema de Bicing.
     * \pre La nueva capacidad es mayor que el número de bicicletas que contiene la estación.
     * \post La capacidad de la estación pasa a ser la recibida como parámetro.
     */

    void modificar_capacidad(const string &identificador_estacion, const int capacidad);

    /**
     * @brief Modificadora que sube bicicletas en dirección a la primera estación.
     * \pre <em>Cierto</em>.
     * \post Se reestructura la ubicación de las bicis en el sistema de Bicing, moviéndolas en dirección a la 
     * primera estación y llenando las estaciones (si es posible) a partir de sus dos subestaciones siguientes. 
     * Las dos subestaciones de cada estación quedan con un número de bicis lo más equilibrado posible.
     */

    void subir_bicis(Cjt_Bicis &conjunto_bicis);

    /**
     * @brief Modificadora que asigna una estación a una bicicleta en el sistema de Bicing.
     * \pre La bicicleta no existe en el sistema y el sistema Bicing no está lleno.
     * \post Se asigna la bicicleta a la estación del sistema de Bicing que tenga el mayor coeficiente de desocupación 
     * general y se escribe el identificador de la estación escogida.
     */

    string asignar_estacion(const string &identificador_bici, Cjt_Bicis &conjunto_bicis);

    ///@}

    /** @name Escritoras
     *  Documentación de las funciones escritoras de la clase Bicing.
     */
    ///@{

    /**
     * @brief Escritora de las bicicletas contenidas en una estación del sistema de Bicing.
     * \pre La estación existe en el sistema de Bicing.
     * \post Se escriben las bicicletas que contiene la estación por orden de identificador.
     */

    void bicis_estacion(const string &identificador_estacion);

    ///@}
};

#endif