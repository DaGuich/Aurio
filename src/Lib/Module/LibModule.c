#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include <LibModule.h>
#include <LibModuleCfg.h>

#define LIBMODULE_EXPAND_MOD_TABLE(name, entrypoints) [LIBMOD_MOD_ ## name] = &entrypoints,

static const S_LibModule_EntryPoints_t *LibModule_EntryTable[LIBMODULE_N_MODULES] = {
        LIBMODULE_MODULE_TABLE(LIBMODULE_EXPAND_MOD_TABLE)
};

S_LibModule_ModuleHndl_t* LibModule_Construct(
        const E_LibModule_ModuleId_t id,
        void *pData) {
    const S_LibModule_EntryPoints_t *pEntryPoints = LibModule_EntryTable[id];
    S_LibModule_ModuleHndl_t *pHndl = NULL;

    if (NULL != pEntryPoints->Construct) {
        pHndl = malloc(sizeof(pHndl));
        (void) pEntryPoints->Construct(pHndl, pData);
    }

    return pHndl;
}

Ret_t LibModule_Destruct(S_LibModule_ModuleHndl_t *hndl) {
    if (NULL == hndl) {
        return RET_NOK;
    }

    const S_LibModule_EntryPoints_t *pEntryPoints = hndl->EntryPoints;
    if (NULL == pEntryPoints) {
        return RET_NOK;
    }
    if (NULL == pEntryPoints->Destruct) {
        return RET_NOK;
    }

    return pEntryPoints->Destruct(hndl);
}

Ret_t LibModule_Run(S_LibModule_ModuleHndl_t *hndl) {
    Ret_t ret = RET_OK;
    const S_LibModule_EntryPoints_t *pEntryPoints = hndl->EntryPoints;

    if (NULL == pEntryPoints) {
        ret = RET_NOK;
    } else if (NULL == pEntryPoints->Run) {
        ret = RET_NOK;
    } else {
        ret = pEntryPoints->Run(hndl);
    }

    return ret;
}

Ret_t LibModule_Ctrl(S_LibModule_ModuleHndl_t *hndl, const uint32_t command, void *pData) {
    Ret_t ret = RET_OK;
    const S_LibModule_EntryPoints_t *pEntryPoints = hndl->EntryPoints;

    if (NULL == pEntryPoints->Ctrl) {
        ret = RET_NOK;
    } else {
        ret = pEntryPoints->Ctrl(hndl, command, pData);
    }

    return ret;
}
