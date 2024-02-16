/** @file Cjt_Bicis.hh
 * @brief Especificación de la clase Cjt_Bicis
 */

#ifndef CJT_BICIS_HH
#define CJT_BICIS_HH

#include "Bici.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include "BinTree.hh"
using namespace std;
#endif

/**
 * @class Cjt_Bicis
 * @brief Representa el conjunto de todas las bicis del sistema de Bicing bifurcado.
 */

class Cjt_Bicis
{
    
private:
    map<string, Bici> conjunto_bicis; // mapa con el id de las bicis (clave) y su  Bici correspondiente

    /**
     * @brief Función para anadir un viaje a una bici del conjunto de bicis.
     * \pre La bici existe en el conjunto y las estaciones son distintas.
     * \post Se añade el viaje a la bici del conjunto.
     */

    void conjunto_bicis_anadir_viaje(const string &id_bici, const string &id1, const string &id2);

public:
    /** @name Constructoras
     *  Documentación de las funciones constructoras de la clase Cjt_Bicis.
     */
    ///@{

    /**
     * @brief Constructora de la clase Cjt_Bicis.
     * \pre <em>Cierto.</em>
     * \post Se crea un conjunto de bicis con ninguna bici.
     */

    Cjt_Bicis();

    ///@}

    /** @name Consultoras
     *  Documentación de las funciones consultoras de la clase Cjt_Bicis.
     */
    ///@{

    /**
     * @brief Consultora del id de la estación a la cual está asignada una bici del conjunto.
     * \pre La bici existe en el conjunto.
     * \post El id de la estación a la cual está asignada la bici del conjunto.
     */

    string bicing_consultar_estacion_asignada(const string &id_bici);

    /**
     * @brief Consultora de bicis del conjunto.
     * \pre La bici existe en el conjunto.
     * \post Devuelve la bici del conjunto que corresponde al id.
     */

    Bici consultar_bici(const string &id_bici);

    /**
     * @brief Consultora de la existencia de una bici en el conjunto de bicis.
     * \pre <em>Cierto.</em>
     * \post Devuelve true si la bici existe en el conjunto, false en caso contrario.
     */

    bool existe_bici(const string &id_bici) const;

    ///@}

    /** @name Modificadoras
     *  Documentación de las funciones modificadoras de la clase Cjt_Bicis.
     */
    ///@{

    /**
     * @brief Modificadora para añadir una bici al conjunto de bicis.
     * \pre La bici no está vacía y no existe en el conjunto.
     * \post Se añade la bici al conjunto.
     */

    void conjunto_bicis_anadir(const string &identificador_bici, const string &identificador_estacion);

    /**
     * @brief Modificadora para eliminar una bici del conjunto de bicis.
     * \pre La bici existe en el conjunto.
     * \post Se elimina la bici del conjunto.
     */

    void conjunto_bicis_eliminar(const string &id_bici);

    /**
     * @brief Modificadora de la estacion asignada de una bici del conjunto de bicis.
     * \pre La bici existe en el conjunto.
     * \post La estación asignada de la bici del conjunto pasa a ser la recibida como parámetro.
     */

    void conjunto_bicis_modificar_estacion(const string &id_bici, const string &id_est);

    /**
     * @brief Modificadora para mover una bici del conjunto de bicis de una estación a otra.
     * \pre La bici existe en el conjunto, las estaciones son distintas y la estación destino no está llena.
     * \post La estación asignada de la bici del conjunto pasa a ser la recibida como parámetro y se le añade 
     * el viaje de la estación origen a la estación destino.
     */

    void conjunto_bicis_mover(const string &id_bici, const string &id1, const string &id2);

    ///@}

    /** @name Escritoras
     *  Documentación de las funciones escritoras de la clase Cjt_Bicis.
     */
    ///@{

    /**
     * @brief Escritora de los viajes de una bici del conjunto de bicis.
     * \pre La bici existe en el conjunto.
     * \post Se escriben los viajes de la bici por el canal estándar de salida.
     */

    void conjunto_bicis_escribir_viajes(const string &id_bici);

    ///@}
};

#endif