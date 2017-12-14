#include <iostream>
#include <fstream>
#include "state.h"
#include "engine.h"
#include "json/json.h"
#include "json/json-forwards.h"

#include "mapGeneration.h"
#include "CommandGeneration.h"

using namespace std ;
using namespace state ;
using namespace engine ;

using namespace mapGeneration ;
using namespace CommandGeneration ;

#define WIDTH 10
#define HEIGHT 10

void testRecord(){
	srand(time(NULL));
	State state(WIDTH, HEIGHT);

	generateTestMap(state);
	generateTestUnits(state);

    Engine engine(state);
    generateCommand(engine);

    Json::Value root ;

    std::string encoding = root.get("encoding", "UTF-8").asString();
    cout << "encoding : " << encoding << endl ;

    const Json::Value plugins = root["plug-ins"];
/*	for ( int index = 0; index < plugins.size(); ++index )  // Iterates over the sequence elements.
	   loadPlugIn( plugins[index].asString() );
	   
	setIndentLength( root["indent"].get("length", 4).asInt() );
	setIndentUseSpace( root["indent"].get("use_space", true).asBool() );

	// ...
	// At application shutdown to make the new configuration document:
	// Since Json::Value has implicit constructor for all value types, it is not
	// necessary to explicitly construct the Json::Value object:
	root["encoding"] = getCurrentEncoding();
	root["indent"]["length"] = getCurrentIndentLength();
	root["indent"]["use_space"] = getCurrentIndentUseSpace();
*/
	Json::StyledStreamWriter writer;
	// Make a new JSON document for the configuration. Preserve original comments.

	// You can also use streams.  This will put the contents of any JSON
	// stream at a particular sub-value, if you'd like.
	//std::cin >> root["subtree"];

	// And you can write to a stream, using the StyledWriter automatically.
	root["test"]["mem_A"] = 2 ;
	root["test"]["mem_B"] = "hello" ;
	root["test"]["mem_C"] = (char)'r' ;

	std::cout << root;

	ofstream ofs ;
	ofs.open("replay.txt", ofstream::out | ofstream::trunc);

	writer.write(ofs, root);

	ofs.close();

}