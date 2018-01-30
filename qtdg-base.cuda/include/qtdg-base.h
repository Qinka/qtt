/**
 * The Quad tree generation base function
 * Generation the training data for quad-tree-based network
 * *QuadTreeDataGeneratingBasic library, (qtdg-base)
 */

#ifndef _QTDG_BASE_H_
#define _QTDG_BASE_H_ (100)

#include <stdint.h>

#include <qtdg-base-config.h>


// Status codes
#define SUCC 0u // success
#define UNIM 1u // unimplented


/**
 * qtVariance compute the variance in a quad tree.
 * @param pData the point of data, the whole matrix
 * @param rowI the value of beginning of row
 * @param colI the value of beginning of col
 * @param sizeRow the size of row
 * @param sizeCol the size of col
 * @param out the result
 *
 * All the points should be allocated with space befor calling.
 */
QTDB_BASE_EXPORT_C_API
uint32_t qtVariance(uint8_t* pData, uint32_t rowI, uint32_t colI, uint8_t sizeRow, uint8_t sizeCol, float *out);


/**
 * Shared library test
 * this function will output the infos
 */
QTDB_BASE_EXPORT_C_API
void qtdgSharedLinkTest();

/**
 * Get whether use the GPU
 * @return
 */
QTDB_BASE_EXPORT_C_API
const int qtdgIsGPU ();

#endif // ! _QTDG_BASE_H_
