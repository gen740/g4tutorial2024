//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// UserActionInitialization.cc   Serial version
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "UserActionInitialization.hh"

#include "G4RunManager.hh"
#include "Geometry.hh"
#include "PrimaryGenerator.hh"
#include "RunAction.hh"
#include "SimData.hh"

UserActionInitialization::UserActionInitialization() = default;

UserActionInitialization::~UserActionInitialization() = default;

void UserActionInitialization::BuildForMaster() const {}

void UserActionInitialization::Build() const {
  auto *runaction = new RunAction{};
  runaction->SetSimData(simdata);
  SetUserAction(new PrimaryGenerator{});
  SetUserAction(runaction);
}
