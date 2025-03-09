#ifndef K_PRODUCT_AMO_H
#define K_PRODUCT_AMO_H
#include <sstream>
#include <vector>

#include "../IncSimplePBConstraint.h"
#include "../PBConfig.h"
#include "../SimplePBConstraint.h"
#include "../auxvarmanager.h"
#include "../clausedatabase.h"
#include "../weightedlit.h"
#include "Encoder.h"
#include "amo.h"
#include "naive_amo_encoder.h"

namespace PBLib {

// A New SAT Encoding of the At-Most-One Constraint
// Jingchao Chen 2010

class k_Product : public Encoder {
 private:
  AMO_Encoder basic_amo_encoder;
  Naive_amo_encoder naive_amo_encoder;
  int minimum_lit_count;
  int k;
  std::vector<Lit> _literals;

  void encode_intern(std::vector<Lit>& literals, ClauseDatabase& formula,
                     AuxVarManager& auxvars);
  void encode_non_recursive(std::vector<Lit>& literals, ClauseDatabase& formula,
                            AuxVarManager& auxvars);

 public:
  void encode(const SimplePBConstraint& pbconstraint, ClauseDatabase& formula,
              AuxVarManager& auxvars) override;
  int64_t encodingValue(const SimplePBConstraint& pbconstraint) override;

  k_Product(PBConfig& config);
  ~k_Product() override = default;
};

} /* namespace PBLib */

#endif  // K_PRODUCT_AMO_H
