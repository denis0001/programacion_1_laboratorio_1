/** \brief valida un entero entre dos limites
 *
 * \param entero a validar
 * \param limite superior
 * \param limite inferior
 * \return si el numero a validar esta entre los limites retorna 1, si no 0
 *
 */

int validarRango(int valor, int limS, int limI){
int validacion=1;

if (valor>limS || valor<limI){
    validacion=0;
}
return validacion;
}
