/*
 *
 */

#ifndef BDD_SEQ_AMO_H
#define BDD_SEQ_AMO_H

#include <sstream>
#include <vector>

#include "../IncSimplePBConstraint.h"
#include "../PBConfig.h"
#include "../SimplePBConstraint.h"
#include "../auxvarmanager.h"
#include "../clausedatabase.h"
#include "../weightedlit.h"
#include "Encoder.h"

namespace PBLib {

class BDD_Seq_Amo : public Encoder {
 private:
  std::vector<Lit> _literals;
  std::vector<Lit> aux;

 public:
  void encode_intern(std::vector<Lit>& literals, ClauseDatabase& formula,
                     AuxVarManager& auxvars);
  void encode(const SimplePBConstraint& pbconstraint, ClauseDatabase& formula,
              AuxVarManager& auxvars) override;
  int64_t encodingValue(const SimplePBConstraint& pbconstraint) override;

  BDD_Seq_Amo(PBConfig& config);
  ~BDD_Seq_Amo() override = default;
};

}  // namespace PBLib

#endif  // BDD_SEQ_AMO_H
