#ifndef SATSOLVERCLAUSEDATABASE_H
#define SATSOLVERCLAUSEDATABASE_H

#include <vector>

#include "BasicSATSolver.h"
#include "pblib/clausedatabase.h"

namespace PBLib {

class SATSolverClauseDatabase : public ClauseDatabase {
 protected:
  BasicSATSolver* satsolver;
  virtual void addClauseIntern(const std::vector<int32_t>& clause);

 public:
  SATSolverClauseDatabase(PBConfig config, BasicSATSolver* satsolver);
};

}  // namespace PBLib

#endif  // SATSOLVERCLAUSEDATABASE_H
