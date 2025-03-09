/*
 *
 */

#ifndef NAIVE_AMO_ENCODER_H
#define NAIVE_AMO_ENCODER_H

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

class Naive_amo_encoder : public Encoder {
 private:
  std::vector<Lit> _literals;

 public:
  void encode_intern(std::vector<Lit>& literals, ClauseDatabase& formula);
  void encode(const SimplePBConstraint& pbconstraint, ClauseDatabase& formula,
              AuxVarManager& auxvars) override;
  int64_t encodingValue(const SimplePBConstraint& pbconstraint) override;

  Naive_amo_encoder(PBConfig& config);
  ~Naive_amo_encoder() override = default;
};

} /* namespace PBLib */

#endif  // COMMANDER_ENCODING_H
