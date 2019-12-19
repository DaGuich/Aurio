#pragma once

struct S_LibModule_ModuleHndl_t;
struct S_LibModule_EntryPoints_t;

/**
 * @brief Handle/Instance of a module
 */
typedef struct S_LibModule_ModuleHndl_t {
    void *pData;
    float **pInputs;
    size_t nInputs;
    float **pOutputs;
    size_t nOutputs;
    const struct S_LibModule_EntryPoints_t *EntryPoints;
} S_LibModule_ModuleHndl_t;

/**
 * @brief Entry Points for the application to call a modules methods
 */
typedef struct S_LibModule_EntryPoints_t {
    /**
     * @brief Construct a module
     *
     * If this function is called the Destruct function has to be called
     * after usage, otherwise there will be memory leaks.
     *
     * @param hndl <br>
     * @param pData
     * @return
     */
    Ret_t (*Construct)(S_LibModule_ModuleHndl_t *pHndl, void *pData);

    Ret_t (*Destruct)(S_LibModule_ModuleHndl_t *pHndl);

    Ret_t (*Run)(S_LibModule_ModuleHndl_t *pHndl);

    Ret_t (*Ctrl)(S_LibModule_ModuleHndl_t *pHndl, uint32_t command, void *pData);
} S_LibModule_EntryPoints_t;

