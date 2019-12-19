#pragma once

#include <stdint.h>

#include <LibRet.h>
#include <LibModuleTypes.h>

#include <LibModuleCfg.h>

#define LIBMODULE_EXPAND_MOD_ENUM(name, ...) LIBMOD_MOD_ ## name,
typedef enum E_LibModule_ModuleId_t {
    LIBMODULE_MODULE_TABLE(LIBMODULE_EXPAND_MOD_ENUM)
    LIBMODULE_N_MODULES
} E_LibModule_ModuleId_t;

S_LibModule_ModuleHndl_t *LibModule_Construct(const E_LibModule_ModuleId_t id, void *pData);

Ret_t LibModule_Destruct(S_LibModule_ModuleHndl_t *pHndl);

Ret_t LibModule_Run(S_LibModule_ModuleHndl_t *pHndl);

Ret_t LibModule_Ctrl(S_LibModule_ModuleHndl_t *pHndl, const uint32_t command, void *pData);

