#ifndef BIMANDER_AMO_ENCODING_H
#define BIMANDER_AMO_ENCODING_H

#include <sstream>
#include <vector>

#include "../IncSimplePBConstraint.h"
#include "../PBConfig.h"
#include "../SimplePBConstraint.h"
#include "../auxvarmanager.h"
#include "../clausedatabase.h"
#include "../weightedlit.h"
#include "Encoder.h"
#include "naive_amo_encoder.h"

namespace PBLib {

class Bimander_amo_encoding : public Encoder {
 private:
  std::vector<Lit> _literals;
  std::vector<std::vector<Lit> > groups;
  std::vector<Lit> bits;
  int nBits;
  int two_pow_nbits;
  int k;
  int m;
  Naive_amo_encoder naive_amo_encoder;

  void encode_intern(std::vector<Lit>& literals, ClauseDatabase& formula,
                     AuxVarManager& auxvars);

 public:
  void encode(const SimplePBConstraint& pbconstraint, ClauseDatabase& formula,
              AuxVarManager& auxvars) override;
  int64_t encodingValue(const SimplePBConstraint& pbconstraint) override;

  Bimander_amo_encoding(PBConfig& config);
  ~Bimander_amo_encoding() override = default;
};

}  // namespace PBLib

#endif  // BINARY_AMO_H
