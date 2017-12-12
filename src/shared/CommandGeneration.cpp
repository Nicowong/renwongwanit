#include "CommandGeneration.h"

namespace CommandGeneration{

void generateCommand(Engine& engine){
	State& state = engine.getCurrentState();

	Unit& uRI   = *(Unit*)(engine.getCurrentState().getUnitTab().getElem(1,0));
    Unit& uRR   = *(Unit*)(engine.getCurrentState().getUnitTab().getElem(0,1));
    Unit& uRML  = *(Unit*)(engine.getCurrentState().getUnitTab().getElem(0,4));
    Unit& uBT   = *(Unit*)(engine.getCurrentState().getUnitTab().getElem(5,2));
    Unit& uBM   = *(Unit*)(engine.getCurrentState().getUnitTab().getElem(4,3));
    Unit& uBMGT = *(Unit*)(engine.getCurrentState().getUnitTab().getElem(3,4));
    Command* cMvRID1    = new MoveCommand(uRI, 2,2);
    Command* cMvRRD1    = new MoveCommand(uRR, 3,3);
    Command* cAtRRD1    = new AttackCommand(uRR, uBM);
    Command* cAtRMlD1   = new AttackCommand(uRML, uBMGT);
    Command* cEdRD1     = new EndTurnCommand(state);
    Command* cMvBMD1    = new MoveCommand(uBM, 3,2);
    Command* cAtBMD1    = new AttackCommand(uBM, uRI);
    Command* cMvBTD1    = new MoveCommand(uBT, 4,3);
    Command* cAtBTD1    = new AttackCommand(uBT, uRR);
    Command* cAtBMgtD1  = new AttackCommand(uBMGT, uRR);
    Command* cEdBD1     = new EndTurnCommand(state);
    Command* cAtRMlD2   = new AttackCommand(uRML, uBMGT);
    Command* cEdRD2     = new EndTurnCommand(state);
    engine.addCommand(cMvRID1)     ;   //move inftr
    engine.addCommand(cMvRRD1)     ;   //move recon
    engine.addCommand(cAtRRD1)     ;   //recon attack mech
    engine.addCommand(cAtRMlD1)    ;   //missileLauncher attack megatank
    engine.addCommand(cEdRD1)      ;   //-endTurn-
    engine.addCommand(cMvBMD1)     ;   //move mech
    engine.addCommand(cAtBMD1)     ;   //mech attack inftr
    engine.addCommand(cMvBTD1)     ;   //move tank
    engine.addCommand(cAtBTD1)     ;   //tank attack recon
    engine.addCommand(cAtBMgtD1)   ;   //megatank attack recon
    engine.addCommand(cEdBD1)      ;   //-endTurn-
    engine.addCommand(cAtRMlD2)    ;   //missileLauncher attack megatank
    engine.addCommand(cEdRD2)      ;   //-endTurn-
}

};
