#include "nilibddc.h"
#include "stdlib.h"
#include "DataStructure.h"

#define ddcChk(f) if (ddcError = (f), ddcError < 0) goto Error; else
#ifdef nullChk
#undef nullChk
#endif
#define nullChk(p) if (!(p)) { ddcError = DDC_OutOfMemory; goto Error; } else
