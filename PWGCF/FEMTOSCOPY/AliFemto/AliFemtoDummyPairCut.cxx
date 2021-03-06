///
/// \file AliFemtoDummyPairCut.cxx
///

#include "AliFemtoDummyPairCut.h"
#include <string>
#include <cstdio>

#ifdef __ROOT__
  /// \cond CLASSIMP
  ClassImp(AliFemtoDummyPairCut);
  /// \endcond
#endif

//__________________
AliFemtoDummyPairCut::AliFemtoDummyPairCut() :
  fNPairsPassed(0),
  fNPairsFailed(0)
{
  /* no-op */
}
//__________________
AliFemtoDummyPairCut::~AliFemtoDummyPairCut()
{
  /* no-op */
}
//__________________
bool AliFemtoDummyPairCut::Pass(const AliFemtoPair* /* pair */)
{
  // Pass all pairs
  bool temp = true;
  temp ? fNPairsPassed++ : fNPairsFailed++;
  return true;
}
//__________________
AliFemtoString AliFemtoDummyPairCut::Report()
{
  // prepare a report from the execution
  string stemp = "AliFemtoDummy Pair Cut - total dummy-- always returns true\n";
  char ctemp[100];
  snprintf(ctemp , 100, "Number of pairs which passed:\t%ld  Number which failed:\t%ld\n",fNPairsPassed,fNPairsFailed);
  stemp += ctemp;
  AliFemtoString returnThis = stemp;
  return returnThis;
}
//__________________
TList *AliFemtoDummyPairCut::ListSettings()
{
  // return a list of settings in a writable form
  TList *tListSetttings = new TList();

  return tListSetttings;
}
