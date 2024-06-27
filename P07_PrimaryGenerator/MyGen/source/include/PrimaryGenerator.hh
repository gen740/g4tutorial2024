//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// PrimaryGenerator.hh
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef PrimaryGenerator_h
#define PrimaryGenerator_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
class G4ParticleDefinition;
class G4Event;

//------------------------------------------------------------------------------
class PrimaryGenerator : public G4VUserPrimaryGeneratorAction
//------------------------------------------------------------------------------
{
 public:
  PrimaryGenerator();
  ~PrimaryGenerator() override;

  void GeneratePrimaries(G4Event* /*anEvent*/) override;
};
#endif
