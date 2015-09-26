#include "nilibddc.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "DataStructure.h"

#define ddcChk(f) if (ddcError = (f), ddcError < 0) goto Error; else

typedef struct Timestamp Timestamp;