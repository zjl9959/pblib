#ifndef CARDENCODING_H
#define CARDENCODING_H

#include "../IncSimplePBConstraint.h"
#include "../IncrementalData.h"
#include "../PBConfig.h"
#include "../SimplePBConstraint.h"
#include "../auxvarmanager.h"
#include "../clausedatabase.h"
#include "../weightedlit.h"
#include "Encoder.h"

namespace PBLib {

// Cardinality Networks and their Applications (SAT 2009)
// Roberto As ́ın, Robert Nieuwenhuis, Albert Oliveras, Enric Rodr
// ́ıguez-Carbonell
class CardEncoding : public Encoder {
 private:
  class CardIncData : public IncrementalData {
   private:
    std::vector<Lit> outlits;

   public:
    CardIncData(std::vector<Lit>& outlits);
    ~CardIncData() override = default;
    void encodeNewGeq(int64_t newGeq, ClauseDatabase& formula,
                      AuxVarManager& auxVars,
                      std::vector<int32_t> conditionals) override;
    void encodeNewLeq(int64_t newLeq, ClauseDatabase& formula,
                      AuxVarManager& auxVars,
                      std::vector<int32_t> conditionals) override;
  };

 public:
  void encode(const std::shared_ptr<IncSimplePBConstraint>& pbconstraint,
              ClauseDatabase& formula, AuxVarManager& auxvars) override;
  void encode(const SimplePBConstraint& pbconstraint, ClauseDatabase& formula,
              AuxVarManager& auxvars) override;

  int64_t encodingValue(const SimplePBConstraint& pbconstraint) override;
  int64_t encodingValue(
      const std::shared_ptr<IncSimplePBConstraint>& pbconstraint) override;

  CardEncoding(PBConfig& config);
  ~CardEncoding() override = default;
};

}  // namespace PBLib

#endif  // CARDENCODING_H
