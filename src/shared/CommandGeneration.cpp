#include "CommandGeneration.h"

namespace CommandGeneration{

void generateCommand(Engine& engine){
    std::vector<Command*> coms(generateCommandList(engine));
    for(int i=0 ; i<(int)coms.size() ; i++)
        engine.addCommand(coms[i]);
}

std::vector<Command*> generateCommandList(Engine& engine){
    State& state = engine.getState();

    Unit& uRI   = *(Unit*)(engine.getState().getUnitTab().getElem(1,0));
    Unit& uRR   = *(Unit*)(engine.getState().getUnitTab().getElem(0,1));
    Unit& uRML  = *(Unit*)(engine.getState().getUnitTab().getElem(0,4));
    Unit& uBT   = *(Unit*)(engine.getState().getUnitTab().getElem(5,2));
    Unit& uBM   = *(Unit*)(engine.getState().getUnitTab().getElem(4,3));
    Unit& uBMGT = *(Unit*)(engine.getState().getUnitTab().getElem(3,4));
    Command* cMvRID1    = new MoveCommand(uRI, 2,2);   //move inftr
    Command* cMvRRD1    = new MoveCommand(uRR, 3,3);   //move recon
    Command* cAtRRD1    = new AttackCommand(uRR, uBM);   //recon attack mech
    Command* cAtRMlD1   = new AttackCommand(uRML, uBMGT);   //missileLauncher attack megatank
    Command* cEdRD1     = new EndTurnCommand(state);   //-endTurn-
    Command* cMvBMD1    = new MoveCommand(uBM, 3,2);   //move mech
    Command* cAtBMD1    = new AttackCommand(uBM, uRI);   //mech attack inftr
    Command* cMvBTD1    = new MoveCommand(uBT, 4,3);   //move tank
    Command* cAtBTD1    = new AttackCommand(uBT, uRR);   //tank attack recon
    Command* cAtBMgtD1  = new AttackCommand(uBMGT, uRR);   //megatank attack recon
    Command* cEdBD1     = new EndTurnCommand(state);   //-endTurn-
    Command* cAtRMlD2   = new AttackCommand(uRML, uBMGT);   //missileLauncher attack megatank
    Command* cEdRD2     = new EndTurnCommand(state);   //-endTurn-

    std::vector<Command*> vec ;

    vec.push_back(cMvRID1);
    vec.push_back(cMvRRD1);
    vec.push_back(cAtRRD1);
    vec.push_back(cAtRMlD1);
    vec.push_back(cEdRD1);
    vec.push_back(cMvBMD1);
    vec.push_back(cAtBMD1);
    vec.push_back(cMvBTD1);
    vec.push_back(cAtBTD1);
    vec.push_back(cAtBMgtD1);
    vec.push_back(cEdBD1);
    vec.push_back(cAtRMlD2);
    vec.push_back(cEdRD2);

    return vec ;
}

};
