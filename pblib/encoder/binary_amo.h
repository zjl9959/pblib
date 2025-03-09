#ifndef BINARY_AMO_H
#define BINARY_AMO_H
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

// Frisch, A. M. and Peugniez, T. J. (2001) Solving non-Boolean satisfiability
// problems with stochastic local search, in Proc. of the Seventeenth Int. Joint
// Conf. on Artificial Intelligence, Seattle, Washington, pp. 282-288. enhanced
// binary encoding
class Binary_AMO_Encoder : public Encoder {
 private:
  std::vector<Lit> _literals;
  std::vector<Lit> bits;
  int nBits;
  int two_pow_nbits;
  int k;

  void encode_intern(std::vector<Lit>& literals, ClauseDatabase& formula,
                     AuxVarManager& auxvars);

 public:
  void encode(const SimplePBConstraint& pbconstraint, ClauseDatabase& formula,
              AuxVarManager& auxvars) override;
  int64_t encodingValue(const SimplePBConstraint& pbconstraint) override;

  Binary_AMO_Encoder(PBConfig& config);
  ~Binary_AMO_Encoder() override = default;
};

}  // namespace PBLib

#endif  // BINARY_AMO_H
