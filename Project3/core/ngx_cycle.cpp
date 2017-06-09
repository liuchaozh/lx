#include <ngx_config.h>
#include <ngx_core.h>
#include "ngx_cycle.h"

namespace ngx {

std::unique_ptr<Cycle> Cycle::CreateCycle()
{
	return std::unique_ptr<Cycle>(new Cycle);
}

std::unique_ptr<Cycle> Cycle::CreateCycle(std::unique_ptr<Cycle> old_cycle)
{
	std::unique_ptr<Cycle> cycle = Cycle::CreateCycle();



	return cycle;
}

}
