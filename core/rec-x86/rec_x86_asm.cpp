#include "types.h"

#if FEAT_SHREC == DYNAREC_JIT && HOST_CPU == CPU_X86

#include "rec_x86_ngen.h"

extern const u32 cpurun_offset;

unsigned int ngen_required = true;

u32 gas_offs=offsetof(Sh4RCB,cntx.jdyn);

const u32 cpurun_offset=offsetof(Sh4RCB,cntx.CpuRunning);

void (*ngen_FailedToFindBlock)()=&ngen_FailedToFindBlock_;

u32* GetRegPtr(u32 reg)
{
    return Sh4_int_GetRegisterPtr((Sh4RegType)reg);
}

void ngen_terminate(void)
{
   ngen_required = false;
}

#endif

