#include "PBConfig.h"

#include <iostream>
using namespace std;
using namespace PBLib;

void statistic::printStatistic() {
  cout << "c PBLib statistic: encode_amo=" << num_amo
       << " encode_amk=" << num_amk << " encode_pb=" << num_pb
       << " encode_clause=" << num_clause << " encode_trivial=" << num_trivial
       << endl;
  //   cout << "c encodings: " << endl;
  //   cout << "c amo: " << num_amo_encodings << " card: " << num_card_encodings
  //   << " bdd: " << num_bdd_clause_encodings + num_bdd_gates_encodings
  //        << " adder: " << num_adder_encodings << endl;
}

void statistic::printStatisticRelative() {
  double sum = (num_amo + num_amk + num_pb + num_clause + num_trivial) / 100;
  double sum_encodings =
      (num_adder_encodings + num_amo_encodings + num_bdd_clause_encodings +
       num_bdd_gates_encodings + num_card_encodings) /
      100;
  cout.precision(2);
  cout << "c PBLib statistic: encode_amo=" << (double)num_amo / sum
       << " encode_amk=" << (double)num_amk / sum
       << " encode_pb=" << (double)num_pb / sum
       << " encode_clause=" << (double)num_clause / sum
       << " encode_trivial=" << (double)num_trivial / sum << endl;
  //   cout << "c encodings: " << endl;
  //   cout << "c amo: " << (double)num_amo_encodings / sum_encodings << " card:
  //   " << (double)num_card_encodings / sum_encodings
  //        << " bdd: " << ((double)num_bdd_clause_encodings +
  //        (double)num_bdd_gates_encodings) / sum_encodings
  //        << " adder: " << (double)num_adder_encodings / sum_encodings <<
  //        endl;
}
