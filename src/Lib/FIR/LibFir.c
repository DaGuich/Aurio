#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include <LibFir.h>

typedef struct S_LibFir_Data_t
{
    uint32_t Idx;
} S_LibFir_Data_t;

Ret_t LibFir_Construct(S_LibModule_ModuleHndl_t* pHndl, void* pData);
Ret_t LibFir_Destruct(S_LibModule_ModuleHndl_t* pHndl);
Ret_t LibFir_Run(S_LibModule_ModuleHndl_t* pHndl);
Ret_t LibFir_Ctrl(S_LibModule_ModuleHndl_t* pHndl, uint32_t command, void* pData);

const S_LibModule_EntryPoints_t LibFir_EntryPoints = {
    .Construct = LibFir_Construct,
    .Destruct = LibFir_Destruct,
    .Run = LibFir_Run,
    .Ctrl = LibFir_Ctrl
};

static uint32_t global_counter = 0U;

Ret_t LibFir_Construct(S_LibModule_ModuleHndl_t* pHndl, void* pData)
{
    assert(NULL == pData);
    // prepare data
    S_LibFir_Data_t* pFirData = malloc(sizeof(S_LibFir_Data_t));
    pFirData->Idx = global_counter++;

    pHndl->pData = pFirData;
    pHndl->EntryPoints = &LibFir_EntryPoints;

    printf("Construct LibFir#%d...", pFirData->Idx);
    if (NULL == pHndl->EntryPoints)
    {
        printf("...failed!\n");
    }
    else {
        printf("...successful!\n");
    }
    return RET_OK;
}

Ret_t LibFir_Destruct(S_LibModule_ModuleHndl_t* pHndl)
{
    printf(" Destruct LibFir#%d\n", ((S_LibFir_Data_t*)(pHndl->pData))->Idx);
    global_counter--;
    free(pHndl->pData);
    return RET_OK;
}

Ret_t LibFir_Run(S_LibModule_ModuleHndl_t* pHndl)
{
    // TODO: implement
    // printf("Run LibFir#%d\n", ((S_LibFir_Data_t*)pHndl->pData)->Idx);
    return RET_OK;
}

Ret_t LibFir_Ctrl(S_LibModule_ModuleHndl_t* pHndl, const uint32_t command, void* pData)
{
    // TODO: implement
    switch (command)
    {
        case 1:
        {
            uint32_t* pIdx = (uint32_t*)pData;
            *pIdx = ((S_LibFir_Data_t*)pHndl->pData)->Idx;
        }
        break;
    }
    return RET_OK;
}

