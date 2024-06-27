//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geant4 Tutorial for Hep/Space/Medicine Users
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <G4SystemOfUnits.hh>

#include "FTFP_BERT.hh"
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "Geometry.hh"
#include "UserActionInitialization.hh"

//-------------------------------------------------------------------------------
auto main(int argc, char** argv) -> int
//-------------------------------------------------------------------------------
{
  // Construct a run manager
  auto runManager = std::make_unique<G4RunManager>();

  // Set up mandatory user initialization: Geometry
  runManager->SetUserInitialization(new Geometry{});

  // Set up mandatory user initialization: Physics-List
  runManager->SetUserInitialization(new FTFP_BERT{});

  // Set up user initialization: User Actions
  runManager->SetUserInitialization(new UserActionInitialization{});
  runManager->SetNumberOfThreads(10);

  // Initialize G4 kernel
  runManager->Initialize();

  // Create visualization environment
  auto visManager = std::make_unique<G4VisExecutive>();
  visManager->Initialize();

  // Get UI (User Interface) manager
  G4UImanager* uiManager = G4UImanager::GetUIpointer();

  // Switch batch or interactive mode
  if (argc == 1) {  // Interactive mode - no command argument
    auto uiExec = std::make_unique<G4UIExecutive>(argc, argv);
    uiExec->SessionStart();
  } else {  // Batch mode - 1st command argument is a macro-filename
    G4String macroName = argv[1];
    uiManager->ApplyCommand("/control/execute " + macroName);
  }
  G4cout << "End of Geant4 Tutorial for Hep/Space/Medicine Users" << G4endl;

  return 0;
}
