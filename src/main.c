#include <stddef.h>

#include <LibModule.h>

int main()
{
    S_LibModule_ModuleHndl_t *HndlTbl[] =
            {
                    LibModule_Construct(LIBMOD_MOD_FIR, NULL),
                    LibModule_Construct(LIBMOD_MOD_FIR, NULL),
                    LibModule_Construct(LIBMOD_MOD_FIR, NULL),
                    LibModule_Construct(LIBMOD_MOD_FIR, NULL),
                    LibModule_Construct(LIBMOD_MOD_FIR, NULL),
                    LibModule_Construct(LIBMOD_MOD_FIR, NULL),
                    LibModule_Construct(LIBMOD_MOD_FIR, NULL),
                    LibModule_Construct(LIBMOD_MOD_FIR, NULL),
                    LibModule_Construct(LIBMOD_MOD_FIR, NULL),
                    LibModule_Construct(LIBMOD_MOD_FIR, NULL),
            };

    const size_t n_hndls = sizeof(HndlTbl) / sizeof(HndlTbl[0]);
    size_t run_idx = 0;
    size_t hndl_idx = 0;
    for (run_idx = 0; run_idx < 200; run_idx++) {
        for (hndl_idx = 0; hndl_idx < n_hndls; hndl_idx++) {
            LibModule_Run(HndlTbl[hndl_idx]);
        }
    }

    for (hndl_idx = 0; hndl_idx < n_hndls; hndl_idx++) {
        LibModule_Destruct(HndlTbl[hndl_idx]);
    }

    return 0;
}
