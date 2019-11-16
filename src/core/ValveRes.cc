#include "../../include/core/ValveRes.h"

void ValveRes::transfer(){
	*reservoirs[0] + *reservoirs[1];
}
