/// RunAction.cc  Serial version

#include "RunAction.hh"

#include <fstream>
#include <iostream>

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "SimData.hh"

RunAction::RunAction() = default;

RunAction::~RunAction() = default;

void RunAction::BeginOfRunAction(const G4Run* /*unused*/) {
  simdata[0].Initialize();
}

void RunAction::EndOfRunAction(const G4Run* /*unused*/) {
  G4String fName = "P10_Pixel_Four_Output.csv";
  auto record = simdata[0].GetRecord();

  std::ofstream outputfile(fName);
  for (auto val : record) {
    outputfile << (val.eventID);
    outputfile << " , ";
    outputfile << std::get<0>(val.replica);
    outputfile << " , ";
    outputfile << std::get<1>(val.replica);
    outputfile << " , ";
    outputfile << std::get<2>(val.replica);
    outputfile << " , ";
    outputfile << std::get<0>(val.coordinate);
    outputfile << " , ";
    outputfile << std::get<1>(val.coordinate);
    outputfile << " , ";
    outputfile << std::get<2>(val.coordinate);
    outputfile << std::endl;
  }
  outputfile.close();
}
