# ns3-network-performance-tool-v2
NS-3 network performance analysis tool 

INSTALLATION INSTRUCTIONS:
Copy files from repository to ns-3 installation folder. Nothing else is needed to be done.
These folders are changed:
.../scratch,
.../src/applications,
.../src/applications/model,
.../src/applications/helper.
There are few small differences between ns3 releases, so files that are release specific are stored in  the folder: "release specific files". 

USAGE INSTRUCTIONS:
Usage of StatsFlows tool in NS-3 script 
int main () {
  // .... network configuration
  StatsFlows sf;
  Simulator::Run (); 
  sf.Finalize ();
  Simulator::Destroy ();
  return 0;
}

./multi-run.sh



